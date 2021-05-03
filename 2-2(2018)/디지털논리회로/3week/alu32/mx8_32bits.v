module mx8_32bits(a,b,c,d,e,f,g,h,s2,s1,s0,y);
//32bits 8-to-1 multiplexer
input [31:0] a,b,c,d,e,f,g,h;
input s2, s1, s0;
output [31:0] y;

wire [31:0] w0, w1, w2, w3, w4, w5;

mx2_32bits U0_mx2_32bits(.d0(a[31:0]),.d1(b[31:0]),.s(s0),.y(w0[31:0]));
mx2_32bits U1_mx2_32bits(.d0(c[31:0]),.d1(d[31:0]),.s(s0),.y(w1[31:0]));
mx2_32bits U2_mx2_32bits(.d0(e[31:0]),.d1(f[31:0]),.s(s0),.y(w2[31:0]));
mx2_32bits U3_mx2_32bits(.d0(g[31:0]),.d1(h[31:0]),.s(s0),.y(w3[31:0]));
mx2_32bits U4_mx2_32bits(.d0(w0[31:0]),.d1(w1[31:0]),.s(s1),.y(w4[31:0]));
mx2_32bits U5_mx2_32bits(.d0(w2[31:0]),.d1(w3[31:0]),.s(s1),.y(w5[31:0]));
mx2_32bits U6_mx2_32bits(.d0(w4[31:0]),.d1(w5[31:0]),.s(s0),.y(y[31:0]));
//instance to mx2_32bits
endmodule 