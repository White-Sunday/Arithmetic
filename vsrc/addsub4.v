`include "./vsrc/full_adder.v"

module addsub4(a,b,ci,sub,s,co);
	input [3:0] a;
	input [3:0] b;
	input ci;
	input sub;	// sub=1: s=a-b-ci; sub=0: s=a+b+ci
	output [3:0] s;
	output co;
	
	// sub==1, ci==0, a-b-ci = a+(-b)-0 = a+(~b+1)-0 = a+(b^sub)+(ci^sub)
	// sub==1, ci==1, a-b-ci = a+(-b)-1 = a+(~b+1)-1 = a+(b^sub)+(ci^sub)
	// sub==0, ci==0, a+b+ci = a+b+0 = a+(b^sub)+(ci^sub)
	// sub==0, ci==1, a+b+ci = a+b+1 = a+(b^sub)+(ci^sub)
	wire [2:0] c;
	full_adder a0(a[0], sub^b[0], ci^sub, s[0], c[0]);
	full_adder a1(a[1], sub^b[1], c[0], s[1], c[1]);
	full_adder a2(a[2], sub^b[2], c[1], s[2], c[2]);
	full_adder a3(a[3], sub^b[3], c[2], s[3], co);
endmodule
