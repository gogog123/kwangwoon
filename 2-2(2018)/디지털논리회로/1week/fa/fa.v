module fa(a,b,ci,s,co);
input a,b,ci;
output s,co;
wire c1,c2,sm;
ha U0_ha(.a(a),.b(b),.s(sm),.co(c1));
ha U1_ha(.a(sm),.b(ci),.s(s),.co(c2));
_or2 U2_or2(.a(c1),.b(c2),.y(co));
endmodule 
