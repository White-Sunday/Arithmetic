#include <stdio.h>
#include <stdlib.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "../obj_dir/Vmul_signed8.h"

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
	Vmul_signed8 *top = new Vmul_signed8{contextp};
	
	VerilatedVcdC *tfp = new VerilatedVcdC;
	contextp->traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("wave.vcd");

	// init signal
	top->a = 0x02;
	top->b = 0x02;
	top->eval();
	tfp->dump(contextp->time());

	step({top->a=0xfe;top->b=0xfe;});	// -2*-2
	step({top->a=0xff;top->b=0xff;});	// -1*-1
	step({top->a=0xfe;top->b=0x04;});	// -2*4
	step({top->a=0x02;top->b=0xfc;});	// 2*-4
	step();

	delete top;
	tfp->close();
	delete tfp;
	delete contextp;
	return 0;
}
