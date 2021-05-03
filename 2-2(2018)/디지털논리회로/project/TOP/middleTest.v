module multiplierANDadder(clk,reset_n,rAddr,fifo0_in,fifo1_in,fifo0_we,fifo1_we,op_clear,multi_op_start,adder_op_start,rData,multi_op_done,adder_op_done,data_count0,data_count1);
// multiplier + fifo*2 + adder + fifo + register file module
input clk,reset_n,fifo0_we,fifo1_we,op_clear,multi_op_start,adder_op_start; // input variable
input [31:0] fifo0_in,fifo1_in; // input variable
input [2:0] rAddr; // input variable
output multi_op_done,adder_op_done; // output variable
output [31:0] rData; // output variable
output [3:0] data_count0,data_count1; // output variable
wire [31:0] adder_out_result; // wire variable
wire [2:0] wAddr; // wire variable
wire [31:0] multi_out_result; // wire variable
wire fifo_we,RF_we; // wire variable



// adder + fifo
adderANDfifo U0_adderANDfifo(.clk(clk),.din(multi_out_result),.op_clear(op_clear),.op_start(adder_op_start),.reset_n(reset_n),.fifo_we(fifo_we),
.RF_we(RF_we),.op_done(adder_op_done),.out_result(adder_out_result),.wAddr(wAddr));
//multiplier + fifo*2
multiplierANDfifo U1_multiplierANDfifo(.clk(clk),.reset_n(reset_n),.fifo0_in(fifo0_in),.fifo1_in(fifo1_in),.fifo0_we(fifo0_we),.fifo1_we(fifo1_we),
			.op_clear(op_clear),.op_start(multi_op_start),.op_done(multi_op_done),.out_result(multi_out_result),.fifo_we(fifo_we),.data_count0(data_count0),.data_count1(data_count1));
//register file
RF U2_Register_file(.clk(clk),.clear(op_clear),.wAddr(wAddr),.wData(adder_out_result),.we(RF_we),.rAddr(rAddr),.rData(rData));
			
endmodule

module multiplierANDfifo(clk,reset_n,fifo0_in,fifo1_in,fifo0_we,fifo1_we,
			op_clear,op_start,op_done,out_result,fifo_we,data_count0,data_count1); // multiplier + fifo module

input clk,reset_n,fifo0_we,fifo1_we,op_clear,op_start; // input variable
input [31:0] fifo0_in, fifo1_in; // input variable
output op_done; // output variable
output [31:0] out_result; // output variable
output fifo_we; // output variable

wire fifo_re; // wire variable
wire [31:0] multiplier,multiplicand; // wire variable
output [3:0] data_count0,data_count1; // output variable



//fifo0 module
fifo U0_fifo(.clk(clk),.reset_n(reset_n),.opclear(op_clear),.rd_en(fifo_re),.wr_en(fifo0_we),.din(fifo0_in),.dout(multiplier),
.data_count(data_count0));
//fifo1 module
fifo U1_fifo(.clk(clk),.reset_n(reset_n),.opclear(op_clear),.rd_en(fifo_re),.wr_en(fifo1_we),.din(fifo1_in),.dout(multiplicand),
.data_count(data_count1));
//multipliermodule
multiplier U3_multiplier(.fifo0_data_count(data_count0),.fifo1_data_count(data_count1),.clk(clk),.reset_n(reset_n),.op_start(op_start),.op_clear(op_clear),.multiplicand(multiplicand),.multiplier(multiplier),
.out_result(out_result),.op_done(op_done),.fifo_re(fifo_re),.fifo_we(fifo_we));


endmodule

module adderANDfifo(clk,din,op_clear,op_start,reset_n,fifo_we,RF_we,op_done,out_result,wAddr); // Adder + fifo module
input fifo_we,clk,reset_n,op_clear,op_start; // input variable
input [31:0] din;// input variable
output RF_we,op_done;// output variable
output [2:0] wAddr;// output variable
output [31:0] out_result;// output variable

wire [3:0] fifo_data_count;// wire variable
wire [31:0] dout;// wire variable
wire fifo_re;// wire variable
// fifo instance
fifo U0_fifo(.clk(clk),.reset_n(reset_n),.opclear(op_clear),.rd_en(fifo_re),.wr_en(fifo_we),.din(din),.dout(dout),.data_count(fifo_data_count));
//adder instance
adder U1_adder(.din(dout),.op_start(op_start),.clk(clk),.fifo_data_count(fifo_data_count),.op_clear(op_clear),.reset_n(reset_n),.RF_we(RF_we),
.op_done(op_done),.out_result(out_result),.fifo_re(fifo_re),.wAddr(wAddr));
endmodule





