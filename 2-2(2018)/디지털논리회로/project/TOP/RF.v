module register32_r_en(clk,clear,en,d_in,d_out);//register32_r_en module
input clk, clear, en;//clk port variable
input [31:0] d_in;//32-bit input port variable
output [31:0] d_out;//32-bit output port variable

register8_r_en U0_register_r_en(.clk(clk),.clear(clear),.en(en),.d_in(d_in[7:0]),.d_out(d_out[7:0]));//instances for d_out[0]~d_out[7]
register8_r_en U1_register_r_en(.clk(clk),.clear(clear),.en(en),.d_in(d_in[15:8]),.d_out(d_out[15:8]));//instances for d_out[8]~d_out[15]
register8_r_en U2_register_r_en(.clk(clk),.clear(clear),.en(en),.d_in(d_in[23:16]),.d_out(d_out[23:16]));//instances for d_out[16]~d_out[23]
register8_r_en U3_register_r_en(.clk(clk),.clear(clear),.en(en),.d_in(d_in[31:24]),.d_out(d_out[31:24]));//instances for d_out[24]~d_out[31]
endmodule

module register32_8(clk,clear,en,d_in,d_out0,d_out1,d_out2,d_out3,d_out4,d_out5,d_out6,d_out7); // register32 * 8 instance
input clk,clear; // input port variables
input [7:0] en; // 8bit input port variable
input [31:0] d_in; // 32bit input port variable
output [31:0] d_out0,d_out1,d_out2,d_out3,d_out4,d_out5,d_out6,d_out7; // 32bit output port variable

register32_r_en U0_register_r_en(.clk(clk),.clear(clear),.en(en[0]),.d_in(d_in),.d_out(d_out0));//register32_r_en instances for d_out0
register32_r_en U1_register_r_en(.clk(clk),.clear(clear),.en(en[1]),.d_in(d_in),.d_out(d_out1));//register32_r_en instances for d_out1
register32_r_en U2_register_r_en(.clk(clk),.clear(clear),.en(en[2]),.d_in(d_in),.d_out(d_out2));//register32_r_en instances for d_out2
register32_r_en U3_register_r_en(.clk(clk),.clear(clear),.en(en[3]),.d_in(d_in),.d_out(d_out3));//register32_r_en instances for d_out3
register32_r_en U4_register_r_en(.clk(clk),.clear(clear),.en(en[4]),.d_in(d_in),.d_out(d_out4));//register32_r_en instances for d_out4
register32_r_en U5_register_r_en(.clk(clk),.clear(clear),.en(en[5]),.d_in(d_in),.d_out(d_out5));//register32_r_en instances for d_out5
register32_r_en U6_register_r_en(.clk(clk),.clear(clear),.en(en[6]),.d_in(d_in),.d_out(d_out6));//register32_r_en instances for d_out6
register32_r_en U7_register_r_en(.clk(clk),.clear(clear),.en(en[7]),.d_in(d_in),.d_out(d_out7));//register32_r_en instances for d_out7

endmodule

module register8_r_en(clk,clear,en,d_in,d_out);//register8_r_en module
input clk,clear,en;//input port variable
input [7:0] d_in;//8-bit input port variable
output [7:0] d_out;//8-bit output port variable

_dff_r_en U0_dff_r_en(.clk(clk),.clear(clear),.en(en),.d(d_in[0]),.q(d_out[0]));//dff_r_en instances for q[0]
_dff_r_en U1_dff_r_en(.clk(clk),.clear(clear),.en(en),.d(d_in[1]),.q(d_out[1]));//dff_r_en instances for q[1]
_dff_r_en U2_dff_r_en(.clk(clk),.clear(clear),.en(en),.d(d_in[2]),.q(d_out[2]));//dff_r_en instances for q[2]
_dff_r_en U3_dff_r_en(.clk(clk),.clear(clear),.en(en),.d(d_in[3]),.q(d_out[3]));//dff_r_en instances for q[3]
_dff_r_en U4_dff_r_en(.clk(clk),.clear(clear),.en(en),.d(d_in[4]),.q(d_out[4]));//dff_r_en instances for q[4]
_dff_r_en U5_dff_r_en(.clk(clk),.clear(clear),.en(en),.d(d_in[5]),.q(d_out[5]));//dff_r_en instances for q[5]
_dff_r_en U6_dff_r_en(.clk(clk),.clear(clear),.en(en),.d(d_in[6]),.q(d_out[6]));//dff_r_en instances for q[6]
_dff_r_en U7_dff_r_en(.clk(clk),.clear(clear),.en(en),.d(d_in[7]),.q(d_out[7]));//dff_r_en instances for q[7]

endmodule

module RF(clk,clear,wAddr,wData,we,rAddr,rData); // Register file module
input clk, we,clear; // input port variables
input [2:0] wAddr,rAddr; // 3bit input port variables
input [31:0] wData; // 32bit input port variable
output [31:0] rData; //32bit output port variable

wire [7:0] to_reg; // 8bit wire port variable
wire [31:0] from_reg[7:0]; // 32bit wire port variable
// write_operation + register32*8 + read_operation module instance
write_operation U0_write_operation(.Addr(wAddr),.we(we),.to_reg(to_reg));
register32_8 U0_register32_8(.clk(clk),.clear(clear),.en(to_reg),.d_in(wData),.d_out0(from_reg[0]),.d_out1(from_reg[1]),.d_out2(from_reg[2]),.d_out3(from_reg[3]),.d_out4(from_reg[4]),.d_out5(from_reg[5]),.d_out6(from_reg[6]),.d_out7(from_reg[7]));
read_operation U0_read_operation(.Addr(rAddr),.Data(rData),.from_reg0(from_reg[0][31:0]),.from_reg1(from_reg[1][31:0]),.from_reg2(from_reg[2][31:0]),.from_reg3(from_reg[3][31:0]),.from_reg4(from_reg[4][31:0]),.from_reg5(from_reg[5][31:0]),.from_reg6(from_reg[6][31:0]),.from_reg7(from_reg[7][31:0]));
endmodule

module write_operation(Addr,we,to_reg); // write_operation module
input we; // input port variable
input [2:0] Addr; //3bit input port variable
output [7:0] to_reg; // 8bit output port variable

wire [7:0] write_wire; // 8bit wire port variable
// 3to8 decoder module instance
_3_to_8_decoder U0_3_to_8_decoder(.d(Addr),.q(write_wire));
//2input and gate * 8 instance
_and2 U0_and2(.a(we),.b(write_wire[0]),.y(to_reg[0]));
_and2 U1_and2(.a(we),.b(write_wire[1]),.y(to_reg[1]));
_and2 U2_and2(.a(we),.b(write_wire[2]),.y(to_reg[2]));
_and2 U3_and2(.a(we),.b(write_wire[3]),.y(to_reg[3]));
_and2 U4_and2(.a(we),.b(write_wire[4]),.y(to_reg[4]));
_and2 U5_and2(.a(we),.b(write_wire[5]),.y(to_reg[5]));
_and2 U6_and2(.a(we),.b(write_wire[6]),.y(to_reg[6]));
_and2 U7_and2(.a(we),.b(write_wire[7]),.y(to_reg[7]));

endmodule

module read_operation(Addr,Data,from_reg0,from_reg1,from_reg2,from_reg3,from_reg4,from_reg5,from_reg6,from_reg7); // read operation module
input [31:0] from_reg0,from_reg1,from_reg2,from_reg3,from_reg4,from_reg5,from_reg6,from_reg7; // 32bit input port variables
input [2:0] Addr; // 3bit input port variable
output [31:0] Data; // 32bit output port variable

wire [31:0] data_wire; // 32bit wire port variable
wire [31:0] ff_wire; // 32bit wire port variable
// 8to1 MUX module instance
_8_to_1_MUX U0_8_to_1_MUX(.a(from_reg0),.b(from_reg1),.c(from_reg2),.d(from_reg3),.e(from_reg4),.f(from_reg5),.g(from_reg6),.h(from_reg7),.sel(Addr),.d_out(Data));

endmodule
