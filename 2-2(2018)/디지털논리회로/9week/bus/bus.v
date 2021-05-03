module bus(clk, reset_n, M0_req, M0_wr, M0_address, M0_dout, M1_req, M1_wr, M1_address, M1_dout, S0_dout, S1_dout, 
M0_grant, M1_grant, M_din, S0_sel, S1_sel, S_address, S_wr, S_din);
//data 전송 할 수 있도록 연결해주는 component
input clk, reset_n, M0_req, M0_wr, M1_wr, M1_req;
input [7:0] M0_address, M1_address;
input [31:0] M0_dout, M1_dout, S0_dout, S1_dout;
output M0_grant, M1_grant, S0_sel, S1_sel, S_wr;
output [7:0] S_address;
output [31:0] M_din, S_din;

wire W0_sel, W1_sel;
//flipflop output wire

bus_arbit U0_bus_arbit(.clk(clk), .reset_n(reset_n), .M0_req(M0_req), .M1_req(M1_req), .M0_grant(M0_grant), .M1_grant(M1_grant));
//instance of bus_arbit

mux2 U0_mux2(.d0(M0_wr), .d1(M1_wr), .s(M1_grant), .y(S_wr));
mux2_8bit U0_mux2_8bit(.d0(M0_address),.d1(M1_address),.s(M1_grant),.y(S_address));
mux2_32bit U0_mux2_32bit(.d0(M0_dout),.d1(M1_dout),.s(M1_grant),.y(S_din));
//instance of mux

bus_addr U0_bus_addr(.S_address(S_address), .S0_sel(S0_sel),.S1_sel(S1_sel));
//instance of bus_addr

dff_r U0_dff_r(.clk(clk),.reset_n(reset_n), .d(S0_sel),.q(W0_sel));
dff_r U1_dff_r(.clk(clk),.reset_n(reset_n), .d(S1_sel),.q(W1_sel));
//instance of flipflop
mux3_32bit U0_mux3_32bit(.d0(S0_dout), .d1(S1_dout), .d2(32'b0), .s({W1_sel,W0_sel}), .y(M_din));

endmodule 