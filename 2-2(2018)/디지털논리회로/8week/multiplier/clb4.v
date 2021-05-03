module clb4(a,b,ci,c1,c2,c3,co);
input [3:0] a, b;
input ci;
output c1, c2, c3, co;

wire [3:0] g, p; //generate, propagate

wire w0_c1;
wire w0_c2, w1_c2;
wire w0_c3, w1_c3, w2_c3;
wire w0_co, w1_co, w2_co, w3_co;

//Generate
assign g[3:0] = a[3:0]&b[3:0];
//_and2 U0_and2(.a(a[3:0]),.b(b[3:0]),.y(g[3:0]));

//Propagate
assign p[3:0] = a[3:0]|b[3:0];
//_or2 U1_or2(.a(a[3:0]),.b(b[3:0]),.y(p[3:0]))

//c1
assign c1 = g[0]|(p[0]&ci);

//c2
assign c2 = g[1]|(p[1]&g[0])|(p[1]&p[0]&ci);

//c3
assign c3 = g[2]|(p[2]&g[1])|(p[2]&p[1]&g[0])|(p[2]&p[1]&p[0]&ci); 

//co
assign co = g[3]|(p[3]&g[2])|(p[3]&p[2]&g[1])|(p[3]&p[2]&p[1]&g[0])|(p[3]&p[2]&p[1]&p[0]&ci);

endmodule 