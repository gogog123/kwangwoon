`timescale 1ns/100ps
module tb_cntr8;
//cntr8 testbench module
reg tb_clk, tb_reset_n, tb_inc, tb_load;
reg [7:0] tb_d_in;
wire [7:0] tb_d_out;
wire [2:0] tb_o_state;

cntr8 U0_cntr8(.clk(tb_clk),.reset_n(tb_reset_n),.inc(tb_inc),.load(tb_load),
               .d_in(tb_d_in),.d_out(tb_d_out),.o_state(tb_o_state));
//instance of cntr8
parameter STEP=10;
//set parameter
always #(STEP/2) tb_clk=~tb_clk;

initial
begin
tb_clk=1; tb_reset_n=0;tb_inc=0; tb_load=0; 
tb_d_in=2'h00;
#22.5 tb_reset_n=1; tb_inc=1;
#50 tb_inc=0;
#30 $stop;
end
//testbench
endmodule 
