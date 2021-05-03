module master(rAddr,clk,reset_n,S_sel,S_wr,op_clear,m_interrupt,rData,M1_address,M1_dout,M1_req,M1_wr); // master module
input clk,reset_n,S_sel,S_wr,op_clear,m_interrupt; // input variable
input [31:0] rData; // input variable
input [2:0] rAddr; // input variable
output M1_req,M1_wr; // output variable
output [7:0] M1_address; // output variable
output [31:0] M1_dout; // output variable


endmodule

