module cla4(a,b,ci,s,co);//4-bit cla
input [3:0]a,b;//4-bit input a,b
input ci; // input carry in 
output [3:0]s;//4-bit output s
output co; // output carry out
wire c1,c2,c3; // wire values


clb4 U0_clb4(.a(a),.b(b),.ci(ci),.c1(c1),.c2(c2),.c3(c3),.co(co));//calculation of Cout of 4-bit input a,b

fa_v2 U0_fa_v2(.a(a[0]),.b(b[0]),.ci(ci),.s(s[0])); // full adder s0
fa_v2 U1_fa_v2(.a(a[1]),.b(b[1]),.ci(c1),.s(s[1])); // full adder s1
fa_v2 U2_fa_v2(.a(a[2]),.b(b[2]),.ci(c2),.s(s[2])); // full adder s2
fa_v2 U3_fa_v2(.a(a[3]),.b(b[3]),.ci(c3),.s(s[3])); // full adder s3

endmodule

module cla32 (a,b,ci,s,co);//32-bit cla
input [31:0] a,b;//32-bit input a,b
input ci; // input carry in
output [31:0] s;//32-bit output s
output co; // output carrt out

wire c1,c2,c3,c4,c5,c6,c7; // wire result of carry out 

//each instance calculate Cout and Sum of 4-bit input. 
cla4 U0_cla4(.a(a[3:0]),.b(b[3:0]),.ci(ci),.s(s[3:0]),.co(c1)); // 4bit cla(3~0)
cla4 U1_cla4(.a(a[7:4]),.b(b[7:4]),.ci(c1),.s(s[7:4]),.co(c2)); // 4vit cla(4~7)
cla4 U2_cla4(.a(a[11:8]),.b(b[11:8]),.ci(c2),.s(s[11:8]),.co(c3)); // 4vit cla(8~11)
cla4 U3_cla4(.a(a[15:12]),.b(b[15:12]),.ci(c3),.s(s[15:12]),.co(c4)); // 4vit cla(12~15)
cla4 U4_cla4(.a(a[19:16]),.b(b[19:16]),.ci(c4),.s(s[19:16]),.co(c5)); // 4vit cla(16~19)
cla4 U5_cla4(.a(a[23:20]),.b(b[23:20]),.ci(c5),.s(s[23:20]),.co(c6)); // 4vit cla(20~23)
cla4 U6_cla4(.a(a[27:24]),.b(b[27:24]),.ci(c6),.s(s[27:24]),.co(c7)); // 4vit cla(24~27)
cla4 U7_cla4(.a(a[31:28]),.b(b[31:28]),.ci(c7),.s(s[31:28]),.co(co)); // 4vit cla(28~31)

endmodule

module cla32_16 (a,b,ci,s,co);//upper 16-bit calculate 32bit cla 
input [15:0] b;
input [31:0] a;//32-bit input a,b
input ci; // input carry in
output [31:0] s;//32-bit output s
output co; // output carrt out

wire c1,c2,c3; // wire result of carry out 

assign s[15:0] = a[15:0];
//each instance calculate Cout and Sum of 4-bit input. 
cla4 U0_cla4(.a(a[19:16]),.b(b[3:0]),.ci(ci),.s(s[19:16]),.co(c1)); // 4bit cla(3~0)
cla4 U1_cla4(.a(a[23:20]),.b(b[7:4]),.ci(c1),.s(s[23:20]),.co(c2)); // 4vit cla(4~7)
cla4 U2_cla4(.a(a[27:24]),.b(b[11:8]),.ci(c2),.s(s[27:24]),.co(c3)); // 4vit cla(8~11)
cla4 U3_cla4(.a(a[31:28]),.b(b[15:12]),.ci(c3),.s(s[31:28]),.co(co)); // 4vit cla(12~15)

endmodule


module clb4(a,b,ci,c1,c2,c3,co);//It calculates c1,c2,c3,co
input [3:0] a,b;//4-bit input a,b
input ci; // single bit input carry in
output c1,c2,c3,co; // outputs carry out

wire [3:0] g,p;//4-bit wire g,p

wire w0_c1; // middle result of carry out
wire w0_c2, w1_c2; // middle result of carry out
wire w0_c3, w1_c3, w2_c3; // middle result of carry out
wire w0_co, w1_co, w2_co, w3_co; // middle result of carry out


_and2 U0_and2(.a(a[0]),.b(b[0]),.y(g[0])); // calculate G0
_and2 U1_and2(.a(a[1]),.b(b[1]),.y(g[1])); // calculate G1
_and2 U2_and2(.a(a[2]),.b(b[2]),.y(g[2])); // calculate G2
_and2 U3_and2(.a(a[3]),.b(b[3]),.y(g[3])); // calculate G3

_or2 U0_or(.a(a[0]),.b(b[0]),.y(p[0])); // calculate P0
_or2 U1_or(.a(a[1]),.b(b[1]),.y(p[1])); // calculate P1
_or2 U2_or(.a(a[2]),.b(b[2]),.y(p[2])); // calculate P2
_or2 U3_or(.a(a[3]),.b(b[3]),.y(p[3])); // calculate P3

_and2 U4_and2(.a(p[0]),.b(ci),.y(w0_c1)); // calculate P0ci
_or2 U4_or(.a(w0_c1),.b(g[0]),.y(c1)); // calculate G0+P0ci

_and2 U5_and2(.a(p[1]),.b(g[0]),.y(w0_c2));  // calculate G0p1
_and3 U0_and3(.a(p[1]),.b(p[0]),.c(ci),.y(w1_c2)); // calculate P1P0ci
_or3 U0_or3(.a(w0_c2),.b(w1_c2),.c(g[1]),.y(c2)); // calculate G1+G0p1+P1P0ci

_and2 U6_and2(.a(p[2]),.b(g[1]),.y(w0_c3)); // calculate G1P2
_and3 U1_and3(.a(p[2]),.b(p[1]),.c(g[0]),.y(w1_c3)); // calculate P2P1G0
_and4 U0_and4(.a(p[2]),.b(p[1]),.c(p[0]),.d(ci),.y(w2_c3)); // calculate P2P1P0ci
_or4 U0_or4(.a(g[2]),.b(w0_c3),.c(w1_c3),.d(w2_c3),.y(c3)); // calculate G2+G1P2+P2P1G0+P2P1P0ci

_and2 U7_and2(.a(p[3]),.b(g[2]),.y(w0_co)); // calculate G2P3
_and3 U2_and3(.a(p[3]),.b(p[2]),.c(g[1]),.y(w1_co)); // calculate G1P2P3
_and4 U1_and4(.a(p[3]),.b(p[2]),.c(p[1]),.d(g[0]),.y(w2_co)); // calculate P3P2P1G0
_and5 U0_and5(.a(p[3]),.b(p[2]),.c(p[1]),.d(p[0]),.e(ci),.y(w3_co)); // calculate P3P2P1P0ci
_or5 U0_or5(.a(g[3]),.b(w0_co),.c(w1_co),.d(w2_co),.e(w3_co),.y(co)); // calculate G4+G2P3+G1P2P3+P3P2P1G0+P3P2P1P0ci



endmodule

module fa_v2(a,b,ci,s);//fa_v2
input a,b,ci;//input variables
output s;//output variable
wire p;//wire variable
_xor2 U0_xor2(.a(a),.b(b),.y(p));//a XOR b
_xor2 U1_xor2(.a(p),.b(ci),.y(s));//p(=a XOR b) XOR s
endmodule


