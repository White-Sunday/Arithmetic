#include <stdio.h>
#include <stdlib.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "../obj_dir/Vcla32.h"

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
	Vcla32 *top = new Vcla32{contextp};
	
	VerilatedVcdC *tfp = new VerilatedVcdC;
	contextp->traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("wave.vcd");

	// init signal
	top->a = 0x77777777;
	top->b = 0xffffffff;
	top->ci = 0;
	top->eval();
	tfp->dump(contextp->time());

	step({top->a=0x77777777;top->b=0xffffffff;top->ci=1;});
	step({top->a=0xaaaaaaaa;top->b=0x55555555;top->ci=0;});
	step({top->a=0xaaaaaaaa;top->b=0x55555555;top->ci=1;});
	step({top->a=0xcccccccc;top->b=0xcccccccc;top->ci=0;});
	step({top->a=0xcccccccc;top->b=0xcccccccc;top->ci=1;});
	step({top->a=0x00000000;top->b=0x00000000;top->ci=0;});
	step();

	delete top;
	tfp->close();
	delete tfp;
	delete contextp;
	return 0;
}
