`timescale 1ns/100ps

module tb_bus;
//bus testbench module
reg tb_clk, tb_reset_n, tb_M0_req, tb_M0_wr, tb_M1_wr, tb_M1_req;
reg [7:0] tb_M0_address, tb_M1_address;
reg [31:0] tb_M0_dout, tb_M1_dout, tb_S0_dout, tb_S1_dout;
wire tb_M0_grant, tb_M1_grant, tb_S0_sel, tb_S1_sel, tb_S_wr;
wire [7:0] tb_S_address;
wire [31:0] tb_M_din, tb_S_din;

bus U0_bus
(.clk(tb_clk), .reset_n(tb_reset_n), .M0_req(tb_M0_req), .M0_wr(tb_M0_wr), .M0_address(tb_M0_address), .M0_dout(tb_M0_dout), 
.M1_req(tb_M1_req), .M1_wr(tb_M1_wr), .M1_address(tb_M1_address), .M1_dout(tb_M1_dout), 
.S0_dout(tb_S0_dout), .S1_dout(tb_S1_dout), 
.M0_grant(tb_M0_grant), .M1_grant(tb_M1_grant), .M_din(tb_M_din), 
.S0_sel(tb_S0_sel), .S1_sel(tb_S1_sel), .S_address(tb_S_address), .S_wr(tb_S_wr), .S_din(tb_S_din));
//instance of bus
always #5 tb_clk = ~tb_clk;
//clock
initial
begin
tb_clk=1; tb_reset_n=0; tb_M0_req=0; tb_M0_wr=0; tb_M1_wr=0; tb_M1_req=0;
tb_M0_address=8'b0; tb_M1_address=8'b0;
tb_M0_dout=32'b0; tb_M1_dout=32'b0; tb_S0_dout=32'b0; tb_S1_dout=32'b0;
#17 tb_reset_n=1;
#10 tb_M0_req=1; tb_S0_dout=32'h1; tb_S1_dout=32'h2;
#10 tb_M0_wr=1;
#10 tb_M0_address=8'h01; tb_M0_dout=32'h2;
#10 tb_M0_address=8'h02; tb_M0_dout=32'h4;
#10 tb_M0_address=8'h03; tb_M0_dout=32'h6;
#10 tb_M0_address=8'h20; tb_M0_dout=32'h20;
#10 tb_M0_address=8'h21; tb_M0_dout=32'h22;
#10 tb_M0_address=8'h22; tb_M0_dout=32'h24;
#10 tb_M0_address=8'h23; tb_M0_dout=32'h26;
#10 tb_M0_address=8'ha0; tb_M0_dout=32'hff;
#20 $stop;
end
//testbench
endmodule 
