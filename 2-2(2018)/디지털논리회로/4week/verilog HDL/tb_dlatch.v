`timescale 1ns/100ps

module tb_dlatch; //tb_dlatch module
reg tb_clk, tb_d;
wire tb_q, tb_q_bar;

_dlatch U0_dlatch(.clk(tb_clk), .d(tb_d), .q(tb_q), .q_bar(tb_q_bar));
//instance of dlatch
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
