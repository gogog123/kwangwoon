`timescale 1ns/100ps

module tb_rca_clk;//rca testbench
reg clock;
reg [31:0]tb_a,tb_b;//32-bit register tb_a,tb_b
reg tb_ci;
wire [31:0] tb_s_rca;//32-bit register tb_s_rca
wire tb_co_rca;

parameter STEP=10;// STEP setting

rca_clk U0_rca_clk(.clock(clock),.a(tb_a),.b(tb_b),.ci(tb_ci),.s_rca(tb_s_rca),.co_rca(tb_co_rca));
//instance of rca_clk

always#(STEP/2) clock=~clock;

initial//test
begin
clock=1; tb_a=32'h00000000; tb_b=32'h000000000; tb_ci=0;
#(STEP)  tb_a=32'hffff_ffff; tb_ci=1;
#(STEP)  tb_a=32'h0000_ffff; tb_b=32'hffff_0000; tb_ci=0;
#(STEP)   tb_a=32'h135f_a562; tb_b=32'h3561_4642;
#(STEP*2) $stop;
end
endmodule

