`timescale 1ns/100ps

module tb_multiplier;
//testbench_multiplier
reg tb_clk, tb_reset_n, tb_op_start, tb_op_clear;
reg [31:0] tb_multiplicand, tb_multiplier; 
//input
wire tb_op_done;
wire [63:0] tb_result;
//output
multiplier U0_multiplier(.clk(tb_clk),.reset_n(tb_reset_n),.multiplicand(tb_multiplicand),.multiplier(tb_multiplier),.op_start(tb_op_start),.op_clear(tb_op_clear),.result(tb_result),.op_done(tb_op_done));
//instance multiplier

always #5 tb_clk = ~tb_clk;
//10의 주기로 clock이 작동 
initial
begin
tb_clk = 1'b0; tb_reset_n = 1'b0; tb_op_start= 1'b1; tb_op_clear = 1'b0;
tb_multiplicand = 32'h00000007; tb_multiplier = 32'h00000032; //7*50 = 350
#5 tb_reset_n = 1'b1;
#300 tb_multiplicand = 32'h0000000B; tb_multiplier = 32'h00000005; //11*5 = 55
#320 tb_multiplicand = 32'h00000026; tb_multiplier = 32'h00000031; //38*49 = 1862
#320 tb_multiplicand = 32'h00000038; tb_multiplier = 32'h00000049; //56*73 = 4088
//#5 tb_op_clear=1'b1;
//#20 tb_op_clear=1'b0;
#290 tb_multiplicand = 32'h00000025; tb_multiplier = 32'hFFFFFFFF2; //
#290 tb_multiplicand = 32'h0000000B; tb_multiplier = 32'h0000000C; //
#320 tb_multiplicand = 32'h0000000D; tb_multiplier = 32'h0000000E; //
#600 $stop;
end 
//testbench
endmodule 