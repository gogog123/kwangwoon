`timescale 1ns/100ps

module tb_dff; //tb_dff module
reg tb_clk, tb_d;
wire q, q_bar;

_dff U0_dff(.clk(tb_clk), .d(tb_d), .q(q), .q_bar(q_bar));
//instance of dff
always #12.5 tb_clk=~tb_clk;
initial
begin
tb_clk=0; tb_d=0;
#7.5 tb_d=1;
#7.5 tb_d=0;
#15 tb_d=1;
#5 tb_d=0;
#10 tb_d=1;
#10 tb_d=0;
#20 $stop;
end
//testbench
endmodule 