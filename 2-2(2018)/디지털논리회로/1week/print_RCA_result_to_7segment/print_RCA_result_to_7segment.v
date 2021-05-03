module print_RCA_result_to_7segment(a, b, cin, dec_out);
// print 7segment module
	input [3:0] 	a;
	input [3:0] 	b;
	input 			cin;
	output [13:0]	dec_out;
	
	wire	[3:0] 	s;
	wire 				c;
		
	rca 		U0_rca(.a(a), .b(b), .ci(cin), .s(s), .co(c));
	seg_dec	U1_seg_dec(.iHex(s), .oSEG7(dec_out[6:0]));
	seg_dec	U2_seg_dec(.iHex({3'b000,c}), .oSEG7(dec_out[13:7]));
	
endmodule
