`timescale 1ns/100ps

module tb_rca; //rca 검증 
	reg 	[3:0] tb_a, tb_b; //4bit input a, b
	reg 	tb_ci;
	wire 	[3:0] tb_s; //output
	wire	tb_co;
	wire 	[4:0] tb_result;
	
	rca U0_rca(.a(tb_a), .b(tb_b), .ci(tb_ci), .s(tb_s), .co(tb_co));
	
	initial
	begin
		tb_a = 4'h0; tb_b = 4'h0; tb_ci = 0;
		#10; tb_a = 4'h5; tb_b = 4'h4;
		#10; tb_a = 4'hF; tb_b = 4'hF;
		#10; tb_ci = 1;
		#10; $stop;
	end
	
	assign tb_result = {tb_co, tb_s};
	
endmodule
