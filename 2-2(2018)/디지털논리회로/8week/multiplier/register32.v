module _dff_r(clk, reset_n, d, q);
//resettable D flopflop with active low asynchrnous reset
input clk, reset_n, d;
output reg q;

always@(posedge clk or negedge reset_n)
//falling edge clk, risingedge reset_n
begin
if(reset_n==0) q <=1'b0;
else q <= d;
end
endmodule 

module _register2_r(clk, reset_n, d, q);
//state save
input clk, reset_n;
input [1:0] d;
output [1:0] q; //3bit output

_dff_r U0_dff_r(.clk(clk),.reset_n(reset_n), .d(d[0]),.q(q[0]));
_dff_r U1_dff_r(.clk(clk),.reset_n(reset_n), .d(d[1]),.q(q[1]));
//instance of dff_r
endmodule 

module _register6_r(clk, reset_n, d, q);
//state save
input clk, reset_n;
input [5:0] d;
output [5:0] q; //3bit output

_dff_r U0_dff_r(.clk(clk),.reset_n(reset_n), .d(d[0]),.q(q[0]));
_dff_r U1_dff_r(.clk(clk),.reset_n(reset_n), .d(d[1]),.q(q[1]));
_dff_r U2_dff_r(.clk(clk),.reset_n(reset_n), .d(d[2]),.q(q[2]));
_dff_r U3_dff_r(.clk(clk),.reset_n(reset_n), .d(d[3]),.q(q[3]));
_dff_r U4_dff_r(.clk(clk),.reset_n(reset_n), .d(d[4]),.q(q[4]));
_dff_r U5_dff_r(.clk(clk),.reset_n(reset_n), .d(d[5]),.q(q[5]));
//instance of dff_r
endmodule 

module _register8_r(clk, reset_n, d, q);
//state save
input clk, reset_n;
input [7:0] d;
output [7:0] q; //3bit output

_dff_r U0_dff_r(.clk(clk),.reset_n(reset_n), .d(d[0]),.q(q[0]));
_dff_r U1_dff_r(.clk(clk),.reset_n(reset_n), .d(d[1]),.q(q[1]));
_dff_r U2_dff_r(.clk(clk),.reset_n(reset_n), .d(d[2]),.q(q[2]));
_dff_r U3_dff_r(.clk(clk),.reset_n(reset_n), .d(d[3]),.q(q[3]));
_dff_r U4_dff_r(.clk(clk),.reset_n(reset_n), .d(d[4]),.q(q[4]));
_dff_r U5_dff_r(.clk(clk),.reset_n(reset_n), .d(d[5]),.q(q[5]));
_dff_r U6_dff_r(.clk(clk),.reset_n(reset_n), .d(d[6]),.q(q[6]));
_dff_r U7_dff_r(.clk(clk),.reset_n(reset_n), .d(d[7]),.q(q[7]));
//instance of dff_r
endmodule 

module _register32_r(clk, reset_n, d, q);
//state save
input clk, reset_n;
input [31:0] d;
output [31:0] q; //3bit output

_register8_r U0_register8_r(.clk(clk),.reset_n(reset_n), .d(d[7:0]),.q(q[7:0]));
_register8_r U1_register8_r(.clk(clk),.reset_n(reset_n), .d(d[15:8]),.q(q[15:8]));
_register8_r U2_register8_r(.clk(clk),.reset_n(reset_n), .d(d[23:16]),.q(q[23:16]));
_register8_r U3_register8_r(.clk(clk),.reset_n(reset_n), .d(d[31:24]),.q(q[31:24]));
//instance of dff_r
endmodule 

module _register64_r(clk, reset_n, d, q);
//state save
input clk, reset_n;
input [63:0] d;
output [63:0] q; //3bit output

_register32_r U0_register32_r(.clk(clk),.reset_n(reset_n), .d(d[31:0]),.q(q[31:0]));
_register32_r U1_register32_r(.clk(clk),.reset_n(reset_n), .d(d[63:32]),.q(q[63:32]));
//instance of dff_r
endmodule 

