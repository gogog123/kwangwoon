module MATRIX_Top(M_din,S_din,S_address,S_sel,S_wr,clk,reset_n,m_interrupt,multi_done,S_dout,M1_address,M1_dout,M1_req,M1_wr);
// matrix top module
input [31:0] M_din,S_din; // input port variable
input [7:0] S_address; // input port variable
input S_sel,S_wr,clk,reset_n; // input port variable

output m_interrupt,multi_done; // output port variable
output [31:0] S_dout; // output port variable
output M1_req,M1_wr; // output port variable
output [7:0] M1_address; // output port variable
output [31:0] M1_dout; // output port variable

wire [31:0] S_dout; // wire port variable
wire S_sel,op_clear,m_interrupt; // wire port variable
wire [2:0] rAddr; // wire port variable

//sub matrix module
matrix U0_matrix(.M_din(M_din),.S_address(S_address),.S_din(S_din),.S_sel(S_sel),.S_wr(S_wr),.clk(clk),.reset_n(reset_n),.multi_op_done(multi_done),.m_interrupt(m_interrupt),.S_dout(S_dout),.op_clear(op_clear),.rAddr(rAddr));
//master module
master U1_master(.rAddr(rAddr),.clk(clk),.reset_n(reset_n),.S_sel(S_sel),.S_wr(S_wr),.op_clear(op_clear),.m_interrupt(m_interrupt),.rData(S_dout),.M1_address(M1_address),.M1_dout(M1_dout),.M1_req(M1_req),.M1_wr(M1_wr));



endmodule



