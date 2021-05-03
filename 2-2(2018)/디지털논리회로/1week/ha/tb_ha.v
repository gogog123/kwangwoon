`timescale 1ns/100ps

module tb_ha; //halfadder 검증
	reg tb_a, tb_b; //input
	wire tb_s, tb_co; // output
	
	ha U0_ha(.a(tb_a), .b(tb_b), .s(tb_s), .co(tb_co));
	
	initial
	begin
		tb_a = 0; tb_b = 0; //초기값 ab=00
		#10; tb_a = 0; tb_b = 1; //10ns 지날때 ab=01
		#10; tb_a = 1; tb_b = 0; //10ns 지날때 ab=10
		#10; tb_a = 1; tb_b = 1; //10ns 지날때 ab=11
		#10; $stop;	
	end 
endmodule 
