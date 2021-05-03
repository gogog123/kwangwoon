`timescale 1ns/100ps

module tb_dff_rs; //tb_dff_rs module
reg tb_clk, tb_set_n, tb_reset_n, tb_d;
wire tb_q;
_dff_rs U0_dff_rs(.clk(tb_clk),.set_n(tb_set_n),.reset_n(tb_reset_n),.d(tb_d),.q(tb_q));
//instance of dff_rs
always #5 tb_clk=~tb_clk;
initial 
begin 
tb_clk=0; tb_set_n=0; tb_reset_n=0; tb_d=0;
#2.5 tb_d=1;
#10 tb_d=0;
#10 tb_d=1;
#10 tb_d=0;
#10 tb_d=1; tb_reset_n=1;
#10 tb_d=0;
#10 tb_d=1;
#10 tb_d=0;
#10 tb_d=1; tb_set_n=1;
#10 tb_d=0;
#10 tb_d=1;
#10 tb_d=0;
#10 tb_d=1;
#10 tb_d=0;
#10 tb_d=1;
#10 tb_d=0;
#10 tb_d=1;
#10 tb_d=0;
#10 tb_d=1;
#10 $stop;
end 
//testbench
endmodule 