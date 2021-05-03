`timescale 1ns/100ps

module tb_tl_cntr;
reg tb_clk, tb_reset_n, tb_Ta, tb_Tb;
wire [1:0] tb_La, tb_Lb;

tl_cntr U0_tl_cntr(.clk(tb_clk), .reset_n(tb_reset_n), .Ta(tb_Ta), .Tb(tb_Tb), .La(tb_La[1:0]),.Lb(tb_Lb[1:0]));
//instance of tl_cntr
always #5 tb_clk=~tb_clk; //5ns마다 변경 
initial
begin
tb_clk=0; tb_reset_n=1; tb_Ta=1; tb_Tb=0; //초기값 설정 
#2.5 tb_reset_n=0;
#10 tb_reset_n=1; //reset_n 1->0->1
#10 tb_Tb=1;
#10 tb_Ta=0;
#30 tb_Ta=1; tb_Tb=0;
#30 tb_Ta=0;
#10 $stop;
end 
//testbench
endmodule 