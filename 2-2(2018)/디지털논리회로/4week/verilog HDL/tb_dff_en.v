`timescale 1ns/100ps
module tb_dff_en; //tb_dff_en module
reg tb_clk, tb_en, tb_d;
wire tb_q;

_dff_en U0_dff_en(.clk(tb_clk),.en(tb_en),.d(tb_d),.q(tb_q));
//instance of dff
always #5 tb_clk=~tb_clk;
initial
begin
tb_clk=0; tb_d=0; tb_en=1;
#2.5 tb_d=1;
#10 tb_d=0;
#10 tb_d=1;
#10 tb_d=0;
#10 tb_d=1;
#10 tb_d=0; tb_en=0;
#10 tb_d=1;
#10 tb_d=0;
#10 tb_d=1;
#10 tb_d=0;
#10 tb_d=1;
#10 tb_d=0;
#10 $stop;
end
//testbench
endmodule 