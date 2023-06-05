#include <stdio.h>
#include <stdlib.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "../obj_dir/Vaddsub4.h"

#define step(statements) do { \
	contextp->timeInc(1); \
	{statements} \
	top->eval(); \
	tfp->dump(contextp->time()); \
} while(0)

int main(int argc, char **argv)
{
	VerilatedContext *contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);
	Vaddsub4 *top = new Vaddsub4{contextp};
	
	VerilatedVcdC *tfp = new VerilatedVcdC;
	contextp->traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("wave.vcd");

	// init signal
	top->a = 0x7;
	top->b = 0x7;
	top->sub = 1;
	top->ci = 1;
	top->eval();
	tfp->dump(contextp->time());

	step({top->a=0x7;top->b=0x7;top->sub=0;top->ci=1;});
	step();

	delete top;
	tfp->close();
	delete tfp;
	delete contextp;
	return 0;
}
