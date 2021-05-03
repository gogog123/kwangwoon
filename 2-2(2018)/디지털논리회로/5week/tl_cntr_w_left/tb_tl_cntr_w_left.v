`timescale 1ns/100ps

module tb_tl_cntr_w_left;
reg tb_clk, tb_reset_n, tb_Ta, tb_Tal, tb_Tb, tb_Tbl;
wire [1:0] tb_La, tb_Lb;

tl_cntr_w_left U0_tl_cntr_w_left(.clk(tb_clk), .reset_n(tb_reset_n), 
.Ta(tb_Ta), .Tal(tb_Tal), .Tb(tb_Tb), .Tbl(tb_Tbl), .La(tb_La), .Lb(tb_Lb));
//instance of tl_cntr_w_left

always #5 tb_clk=~tb_clk;//5ns마다 변경 
initial
begin
tb_clk=1; tb_reset_n=1; tb_Ta=1; tb_Tal=0;
tb_Tb=0; tb_Tbl=0;//초기값 설정 
#2.5 tb_reset_n=0;
#10 tb_reset_n=1;//reset_n 1->0->1
#10 tb_Tal=1;
#10 tb_Ta=0;
#30 tb_Ta=1; tb_Tal=0;
#10 tb_Tal=1;
#10 tb_Tb=1;
#10 tb_Tal=0;
#30 tb_Tal=1; tb_Tb=0;
#10 tb_Tb=1;
#10 tb_Tbl=1;
#10 tb_Tb=0;
#30 tb_Tb=1; tb_Tb=0;
#10 tb_Ta=0;
#10 $stop;
end 
//testbench
endmodule 