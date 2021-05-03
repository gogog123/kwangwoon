module cla4(a, b, ci, s, co); //cla4 module
input [3:0] a, b; //4-bit input a, b
input ci;
output [3:0] s; // 4-bit input s
output co;
wire c1, c2, c3;

clb4 U0_clb4(.a(a),.b(b),.ci(ci),.c1(c1),.c2(c2),.c3(c3),.co(co));
//4-bit carry look-ahead block 

fa_v2 U0_fa_v2(.a(a[0]),.b(b[0]),.ci(ci),.s(s[0]));
fa_v2 U1_fa_v2(.a(a[1]),.b(b[1]),.ci(c1),.s(s[1]));
fa_v2 U2_fa_v2(.a(a[2]),.b(b[2]),.ci(c2),.s(s[2]));
fa_v2 U3_fa_v2(.a(a[3]),.b(b[3]),.ci(c3),.s(s[3]));
//fa_v2에 각각 input 넣어준다.

endmodule 
