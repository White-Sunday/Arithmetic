#include <stdio.h>
#include <stdlib.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "../obj_dir/Vwallace_8x8_product.h"

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
	Vwallace_8x8_product *top = new Vwallace_8x8_product{contextp};
	
	VerilatedVcdC *tfp = new VerilatedVcdC;
	contextp->traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("wave.vcd");

	// init signal
	top->a = 0x00;
	top->b = 0x01;
	top->eval();
	tfp->dump(contextp->time());

	step({top->a=0xff;top->b=0x02;});
	step({top->a=0xff;top->b=0x04;});
	step({top->a=0xff;top->b=0x08;});
	step({top->a=0xff;top->b=0x10;});
	step({top->a=0xff;top->b=0x20;});
	step({top->a=0xff;top->b=0x40;});
	step({top->a=0xff;top->b=0xff;});
	step();

	delete top;
	tfp->close();
	delete tfp;
	delete contextp;
	return 0;
}
