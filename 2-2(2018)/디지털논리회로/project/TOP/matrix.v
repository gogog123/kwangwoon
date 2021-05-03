module matrix(M_din,S_address,S_din,S_sel,S_wr,clk,reset_n,multi_op_done,m_interrupt,S_dout,op_clear,rAddr); // sub matrix module
input [31:0] M_din,S_din; // input port variable
input [7:0] S_address; // input port variable
input S_sel,S_wr,clk,reset_n; // input port variable

output m_interrupt,multi_op_done,op_clear; // output port variable
output [31:0] S_dout; // output port variable
output [2:0] rAddr; // output port variable
wire[31:0] multiplicand,multiplier,result; // wire port variable
wire adder_op_start,multi_op_start,multiplicand_we,multiplier_we,adder_op_done,op_clear; // wire port variable
wire [2:0] rAddr; // wire port variable
wire [3:0] data_count0,data_count1; // wire port variable

//multiplier + fifo*2 + adder + fifo + register file module
multiplierANDadder U0_multiplierANDadder(.clk(clk),.reset_n(reset_n),.rAddr(rAddr),.fifo0_in(multiplier),.fifo1_in(multiplicand),.fifo0_we(multiplier_we),.fifo1_we(multiplicand_we),.op_clear(op_clear),.
				multi_op_start(multi_op_start),.adder_op_start(adder_op_start),.rData(result),.multi_op_done(multi_op_done),.adder_op_done(adder_op_done),.data_count0(data_count0),.data_count1(data_count1));
// slave module
slave U1_slave(.M_din(M_din),.S_address(S_address),.S_din(S_din),.S_sel(S_sel),.S_wr(S_wr),.adder_op_done(adder_op_done),.clk(clk),.reset_n(reset_n),.result(result),.fifo0_data_count(data_count0),.fifo1_data_count(data_count1),
				.S_dout(S_dout),.adder_op_start(adder_op_start),.m_interrupt(m_interrupt),.op_clear(op_clear),.multi_op_start(multi_op_start),.multiplicand(multiplicand),.multiplicand_we(multiplicand_we),.multiplier(multiplier),.multiplier_we(multiplier_we),.rAddr(rAddr));
				
endmodule				
				