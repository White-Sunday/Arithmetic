`include "./vsrc/wallace_8x8/wallace_8x8.v"

module wallace_8x8_product (a,b,z);	// 8*8 wallacetree product
	input [07:00] a;
	input [07:00] b;
	output [15:00] z;
	wire [15:05] x;
	wire [15:05] y;
	wire [15:05] z_high;
	wire [04:00] z_low;
	wallace_8x8 wt_partial (a,b,x,y,z_low);
	assign z_high = x+y;
	assign z = {z_high, z_low};	// product
endmodule
