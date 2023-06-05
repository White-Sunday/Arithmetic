#include <stdio.h>
#include <stdlib.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "../obj_dir/Vadd4.h"

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
	Vadd4 *top = new Vadd4{contextp};
	
	VerilatedVcdC *tfp = new VerilatedVcdC;
	contextp->traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("wave.vcd");

	// init signal
	top->a = 0x7;
	top->b = 0x6;
	top->ci = 1;
	top->eval();
	tfp->dump(contextp->time());

	step();

	delete top;
	tfp->close();
	delete tfp;
	delete contextp;
	return 0;
}
