// full fadder
module full_adder (a,b,ci,s,co);	// dataflow style
	input a,b,ci;	// input a,b,carry_in
	output s,co;	// output sum,carry_out
	assign co = a&b | b&ci | ci&a;
	assign s = (a^b)^ci;
endmodule

// module full_adder_behavioral (a,b,ci,s,co); // behavioral style
// module full_adder_be// 	input a,b,ci;
// module full_adder_be// 	output s,co;
// module full_adder_be// 	assign {s,co} = {0'b0,a}+{0'b0,b}+{0'b0,ci};
// module full_adder_be// endmodule
