`timescale 1ns/100ps

module tb_dff_r; //tb_dff_r module
reg tb_clk, tb_reset_n, tb_d;
wire tb_q;

_dff_r U0_dff_r(.clk(tb_clk),.reset_n(tb_reset_n),.d(tb_d),.q(tb_q));
//instance
always #5 tb_clk=~tb_clk;
initial
begin
tb_clk=0; tb_reset_n=0; tb_d=0;
#2.5 tb_d=1;
#10 tb_d=0; tb_reset_n=1;
#10 tb_d=1;
#10 tb_d=0;
#10 tb_d=1;
#10 tb_d=0;
#10 tb_d=1;
#10 tb_d=0;
#10 tb_d=1;
#10 tb_d=0;
#10 tb_d=1;
#10 tb_d=0;
#20 tb_d=1; tb_reset_n=0;
#10 tb_d=0;
#10 tb_d=1;
#10 $stop;
end
//testbench
endmodule
