module _3_to_8_decoder(d,q); // 3to8 decoder module
input [2:0] d; // 3-bit input port variable
output reg [7:0] q; // 8-bit output reg port variable 

always@(d) // q change
begin
case(d) // condition
3'b000 : q=8'b00000001; //decoding
3'b001 : q=8'b00000010;
3'b010 : q=8'b00000100;
3'b011 : q=8'b00001000;
3'b100 : q=8'b00010000;
3'b101 : q=8'b00100000;
3'b110 : q=8'b01000000;
3'b111 : q=8'b10000000;
default : q=8'hx; // default case
endcase
end
endmodule

module _8_to_1_MUX(a,b,c,d,e,f,g,h,sel,d_out); // 8to1MUX module
input [31:0] a,b,c,d,e,f,g,h; // 32-bit input port variables
input [2:0] sel; // 3-bit input port variable
output reg [31:0] d_out; // 32-bit output reg port variable

always@(sel or a or b or c or d or e or f or g or h) // change input
begin
case(sel) // condition
3'b000 : d_out = a; // select d_out
3'b001 : d_out = b;
3'b010 : d_out = c;
3'b011 : d_out = d;
3'b100 : d_out = e;
3'b101 : d_out = f;
3'b110 : d_out = g;
3'b111 : d_out = h;
default : d_out = 32'hx; // default case
endcase
end
endmodule

module _dff_2_r(clk,reset_n,d,q);//Asynchronous 2-bit D-flipflop module
input clk,reset_n;//input port variables
input [1:0] d; // 2-bit input port variable
output reg [1:0] q;//2-bit output port variable

always@(posedge clk or negedge reset_n) // always at clock's positive edge or reset's negative edge
begin
	if(reset_n==0)	q<=2'b00; // reset come
	else q<=d; // clock come
end

endmodule

module _dff_3_r(clk,reset_n,d,q);//Asynchronous 3-bit D-flipflop module
input clk,reset_n;//input port variables
input [2:0] d; // 3-bit input port variable
output reg [2:0] q;//3-bit output port variable

always@(posedge clk or negedge reset_n) // always at clock's positive edge or reset's negative edge
begin
	if(reset_n==0)	q<=3'b000; // reset come
	else q<=d; // clock come
end

endmodule

module _dff_4_r(clk,reset_n,d,q);//Asynchronous 4-bit D-flipflop module
input clk,reset_n;//input port variables
input [3:0] d; // 4-bit input port variable
output reg [3:0] q;//4-bit output port variable

always@(posedge clk or negedge reset_n) // always at clock's positive edge or reset's negative edge
begin
	if(reset_n==0)	q<=4'b0000; // reset come
	else q<=d; // clock come
end

endmodule

module _dff_32_r(clk,reset_n,d,q); // 32-bit flip-flop
input clk,reset_n;//input port variables
input [31:0] d; // 32-bit input port variable
output reg [31:0] q;//32-bit output port variable

always@(posedge clk or negedge reset_n) // always at clock's positive edge or reset's negative edge
begin
	if(reset_n==0)	q<=32'b0; // reset come
	else q<=d; // clock come
end
endmodule

module _dff_32w_r(clk,reset_n,next_data_count,a,d,q);//Asynchronous 32-bit D-flipflop module
input clk,reset_n;//input port variables
input [3:0] next_data_count;
input [31:0] d,a; // 32-bit input port variable
output reg [31:0] q;//32-bit output port variable

always@(posedge clk or negedge reset_n) // always at clock's positive edge or reset's negative edge
begin
	if(reset_n==0)	q<=32'h00000000; // reset come
	else if(next_data_count==4'b0111 || next_data_count==4'b1000) q<=a; // value identfy
	else q<=d; // clock come
end

endmodule

module _dff_r(clk,reset_n,d,q);//Asynchronous 1-bit D-flipflop module
input clk,reset_n;//input port variables
input d; // 1-bit input port variable
output reg q;//1-bit output port variable

always@(posedge clk or negedge reset_n) // always at clock's positive edge or reset's negative edge
begin
	if(reset_n==0)	q<=1'b0; // reset come
	else q<=d; // clock come
end

endmodule

module _dff_r_en(clk,clear,en,d,q); // async reset enable flip-flop module
input clk, clear,en,d; // input port variables
output reg q; // output reg port variable

always@(posedge clk or posedge clear) // change when clk rising and reset falling
begin
if(clear==1'b1) q<=1'b0; // 1st reset
else if(en) q<=d; // 2nd enable
else q<=q; // else state continue;
end
endmodule
