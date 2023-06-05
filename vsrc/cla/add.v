module add(a,b,c,g,p,s);
	input a;
	input b;
	input c;
	output g;	// carry generator
	output p;	// carry propagator
	output s;	// sum
	
	assign g = a & b;
	assign p = a | b;
	assign s = a ^ b ^ c;
endmodule
