`timescale 1ns/100ps

module tb_cla_clk; // cla의 testbench 
reg clock;
reg [31:0] tb_a,tb_b;//32-bit register a,b
reg tb_ci; 
wire [31:0] tb_s_cla;//32-bit wire s_cla
wire tb_co_cla; // wire co_cla

parameter STEP=10; //step=10

cla_clk U0_cla_clk(.clock(clock),.a(tb_a),.b(tb_b),.ci(tb_ci),.s_cla(tb_s_cla),.co_cla(tb_co_cla));

always#(STEP/2) clock=~clock;

initial

begin //testbench

 clock=1; tb_a=32'h00000000; tb_b=32'h000000000; tb_ci=0;
#(STEP)  tb_a=32'hffff_ffff; tb_ci=1;
#(STEP)  tb_a=32'h0000_ffff; tb_b=32'hffff_0000; tb_ci=0;
#(STEP)   tb_a=32'h135f_a562; tb_b=32'h3561_4642;
#(STEP*2) $stop;

end
endmodule

