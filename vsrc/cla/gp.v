module gp(g,p,c_in,g_out,p_out,c_out);	//  carry generator, carry propagator
	input [1:0] g, p;	// lower level 2-set of g, p
	input c_in;		// lower level carry_in
	output g_out;		// higher level g
	output p_out;		// higher level p
	output c_out;		// higher level carry_out

	assign p_out = p[1] & p[0];
	assign g_out = g[1] | (p[1] & g[0]);
	assign c_out = g[0] | (p[0] & c_in);
endmodule
