module mx2(a,y,en); // 2input mux module
input [31:0] a; //32bit port variable 
input en; //enable
output reg [31:0] y; // output reg 32bit port variable

always@(a or en) // execute at coming in a or en
begin
if(en==1'b0) y=32'h00000000; // come out zero
else y=a; // come out a
end

endmodule

module mux5_32bit(d0,d1,d2,d3,d4,sel,dout); // mux 5input module
	input [31:0] d0,d1,d2,d3,d4; // input port variable
	input [3:0] sel;  // input port variable
	output reg [31:0] dout; // output port variable

	always@(d0,d1,d2,d3,d4,sel)
	begin
		case(sel)
		4'b1000: dout=d0;	// first case
		4'b0100: dout=d1;	// second case
		4'b0010: dout=d2;	// third case
		4'b0001: dout=d3;	// fourth case
		default: dout=d4;	//default case
		endcase
	end
endmodule

module mux2_32bit(d0,d1,sel,dout); // 32bit mux module
	input [31:0] d0,d1; // input port variable
	input [1:0] sel;  // input port variable
	output reg [31:0] dout; // output port variable
	

	always@(d0,d1,sel)
	begin
		case(sel)				
		2'b10: dout=d0; // first case
		2'b01: dout=d1; // second case
		default: dout=32'h0; // default case
		endcase
	end
endmodule	


module mux2_8bit(d0,d1,sel,dout);// mux module
	input [7:0] d0,d1;  // input port variable
	input [1:0]sel;  // input port variable
	output reg [7:0] dout;  // output port variable
	
	always@(d0,d1,sel)
	begin
		case(sel)							
		2'b10: dout=d0; // first case
		2'b01: dout=d1; // second case
		default: dout=8'h0; // default case
		endcase
	end
endmodule

module mux2(d0,d1,sel,dout); // mux module
	input d0,d1; // input port variable
	input [1:0] sel; // input port variable
	output reg dout; // output port variable
	
	always@(d0,d1,sel) // sel combinational logic
	begin
		case(sel)				
		2'b10: dout=d0; // first select
		2'b01: dout=d1; // second select
		default: dout=1'bx; // default select
		endcase
	end
endmodule


