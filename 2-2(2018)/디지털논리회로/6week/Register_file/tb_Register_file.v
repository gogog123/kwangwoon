`timescale 1ns/100ps

module tb_Register_file;
reg tb_clk, tb_reset_n, tb_we;
reg [2:0] tb_wAddr, tb_rAddr;
reg [31:0] tb_wData;
wire [31:0] tb_rData;

Register_file U0_Register_file(.clk(tb_clk),.reset_n(tb_reset_n),.wAddr(tb_wAddr),
                               .wData(tb_wData),.we(tb_we),.rAddr(tb_rAddr),.rData(tb_rData));

parameter STEP=10;
//set parameter
always #(STEP/2) tb_clk=~tb_clk;

initial
begin
tb_clk=0; tb_reset_n=0; tb_we=0;
tb_wAddr=3'b000; tb_rAddr=3'b000; tb_wData=32'h0000000;
#7.5 tb_reset_n=1; tb_we=1; tb_wData=32'h11111111;
#10 tb_wAddr=3'b001; tb_wData=32'hff00ff00;
#10 tb_wAddr=3'b010;
#10 tb_wAddr=3'b011; tb_wData=32'h00ff00ff;
#10 tb_we=0;
#10 tb_rAddr=001;
#10 tb_rAddr=010;
#10 tb_rAddr=011;
#20 $stop;
end
//testbench
endmodule 