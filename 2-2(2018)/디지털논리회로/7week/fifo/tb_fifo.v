`timescale 1ns/100ps

module tb_fifo;
reg tb_clk,tb_reset_n,tb_rd_en,tb_wr_en;
reg [31:0] tb_d_in;
wire [31:0] tb_d_out;
wire tb_full, tb_empty, tb_wr_ack, tb_wr_err, tb_rd_ack, tb_rd_err;
wire [3:0] tb_data_count;

fifo U0_fifo(.clk(tb_clk),.reset_n(tb_reset_n),.rd_en(tb_rd_en),.wr_en(tb_wr_en),
             .d_in(tb_d_in),.d_out(tb_d_out),.data_count(tb_data_count),.full(tb_full),
				 .empty(tb_empty),.wr_ack(tb_wr_ack),.wr_err(tb_wr_err),.rd_ack(tb_rd_ack),.rd_err(tb_rd_err));
//instance of fifo
always #5 tb_clk=~tb_clk;

initial
begin
tb_clk=0; tb_reset_n=0; tb_rd_en=0; tb_wr_en=0; tb_d_in=32'h00000000;
#7.5 tb_reset_n=1;
#10 tb_rd_en=1;
#10 tb_rd_en=0; tb_wr_en=1;
#15 tb_d_in=32'h00000001;
#15 tb_d_in=32'h00000002;
#15 tb_d_in=32'h00000003;
#15 tb_d_in=32'h00000004;
#15 tb_d_in=32'h00000005; //clk signal에 따라 입력 
#30 tb_wr_en=0; tb_rd_en=1;
#100 tb_wr_en=1; tb_rd_en=0;
#75 $stop;
end
//testbench
endmodule 
