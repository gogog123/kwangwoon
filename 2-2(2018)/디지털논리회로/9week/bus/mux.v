module dff_r(clk, reset_n, d, q);
input clk, reset_n;
input d;
output reg q;
always @(posedge clk or negedge reset_n)
begin
if(reset_n==0) q <= 1'b0;
else q <= d;
end 
endmodule 
//flipflop module

module mux2(d0, d1, s, y); //1bit 2-to-1 Multiplexer
input d0, d1;
input s;
output y;

assign y =(s==1'b0)?d0:d1;
//instances of inverter and nand gate
endmodule 

module mux2_8bit(d0, d1, s, y);
//multiplexer module 
input [7:0] d0, d1;
input s;
output [7:0] y;

assign y[7:0] =(s==1'b0)?d0[7:0]:d1[7:0];

endmodule 

module mux2_32bit(d0, d1, s, y);
input [31:0] d0, d1;
input s;
output [31:0] y;

assign y[31:0] =(s==1'b0)?d0[31:0]:d1[31:0];

endmodule 

module mux3_32bit(d0, d1, d2, s, y);
input [31:0] d0, d1, d2;
input [1:0] s;
output [31:0] y;
wire [31:0] w0, w1;

assign y[31:0] =(s==2'b01)?d0[31:0]:((s==2'b10)?d1[31:0]:d2[31:0]);

endmodule 