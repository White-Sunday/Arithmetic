`include "./vsrc/full_adder.v"

module add4(a,b,ci,s,co);	// ripple adder 逐位进位加法器
	input [3:0] a;
	input [3:0] b;
	input ci;
	output [3:0] s;
	output co;
	
	wire [2:0] c; 
	full_adder a0(a[0],b[0],ci,s[0],c[0]);
	full_adder a1(a[1],b[1],c[0],s[1],c[1]);
	full_adder a2(a[2],b[2],c[1],s[2],c[2]);
	full_adder a3(a[3],b[3],c[2],s[3],co);
endmodule
