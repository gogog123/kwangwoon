`timescale 1ns/100ps
module tb_shifter8;
reg tb_clk, tb_reset_n; 
reg [2:0] tb_op;
reg [1:0] tb_shamt;
reg [7:0] tb_d_in;
wire [7:0] tb_d_out;

shifter8 U0_shifter8(.clk(tb_clk),.reset_n(tb_reset_n),.op(tb_op),.shamt(tb_shamt),.d_in(tb_d_in),.d_out(tb_d_out));
//instance of shifter8

parameter STEP=10;//set parameter

always#(STEP/2) tb_clk=~tb_clk;

initial
begin
tb_clk=1'b1; tb_reset_n=1'b0; tb_op=3'b000; tb_shamt=2'b00; tb_d_in=8'b00000000;
#12.5 tb_reset_n =1;
#10 tb_op = 3'b001; tb_d_in = 8'b01110111;
#20 tb_op = 3'b010;
#20 tb_shamt = 2'b01;
#30 tb_op = 3'b011;
#20 tb_op = 3'b010; tb_shamt = 2'b11;
#10 tb_op = 3'b001; tb_d_in = 8'b10000111;
#30 tb_op = 3'b100; tb_shamt = 2'b01;
#40 tb_shamt = 2'b11;
#10 $stop;
end
//testbench
endmodule 