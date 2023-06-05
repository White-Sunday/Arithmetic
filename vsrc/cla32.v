`include "./vsrc/cla/cla_32.v"

module cla32 (a,b,ci,s);
	input [31:0] a, b;
	input ci;
	output [31:0] s;
	wire g_out, p_out;
	cla_32 cla (a,b,ci,g_out,p_out,s);
endmodule
