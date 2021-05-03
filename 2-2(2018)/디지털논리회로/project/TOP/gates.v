module _inv(a,y);//Not gate
input a;// input variable
output y;//output variable
assign y=~a;//y is assigned by !a
endmodule

module _nand2(a,b,y);//2 input Nand gate 
input a,b;//input variables
output y;//output variable
assign y=~(a&b);//y is assigned by !(a&b) 
endmodule

module  _and2(a,b,y);// 2 input And gate
input a,b;//input variables
output y;//output variable
assign y=a&b;// y is assigned by a&b
endmodule

module _or2(a,b,y);//2 input Or gate
input a,b;//input variables
output y;//output variable
assign y=a|b;//y is assigned by a|b
endmodule

module _xor2(a,b,y);//2 input Xor gate
input a,b;//input variables
output y;//output variable
wire inv_a, inv_b, wire_y0, wire_y1;//wire variables
_inv _inv0(.a(a),.y(inv_a));//_inv instance _inv0 is used for obtaining !a
_inv _inv1(.a(b),.y(inv_b));//_inv instance _inv1 is used for obtaining !b
_and2 _and20(.a(a),.b(inv_b),.y(wire_y0));//_and2 instance _and20 is used for obtaining a&!b
_and2 _and21(.a(inv_a),.b(b),.y(wire_y1));//_and2 instance _and21 is used for obtaining !a&B
_or2 _or2(.a(wire_y0),.b(wire_y1),.y(y));// _or instance _or2 is used for obtaining (a&!b)|(!a&b)
endmodule


module _and3(a,b,c,y);//3 input And gate
input a,b,c;//3 input variables
output y;// output variable
assign y=a&b&c;//y is assigned by a&b&c
endmodule

module _and4(a,b,c,d,y);//4 input And gate
input a,b,c,d;//4 input variables
output y;//output variable
assign y=a&b&c&d;//y is assigned by a&b&c&d
endmodule

module _and5(a,b,c,d,e,y);//5 input And gate
input a,b,c,d,e;//5 input variables
output y;//output variable
assign y=a&b&c&d&e;//y is assigned by a&b&c&d&e
endmodule

module _or3(a,b,c,y);//3 input OR gate
input a,b,c;//3 input variables
output y;//output vairable
assign y=a|b|c;//y is assigned by a|b|c
endmodule
module _or4(a,b,c,d,y);
input a,b,c,d;//4 input variables
output y;//output variable
assign y=a|b|c|d;//y is assigned by a|b|c|d
endmodule

module _or5(a,b,c,d,e,y);//5 input OR gate
input a,b,c,d,e;//5 input variables
output y;//output variable
assign y=a|b|c|d|e;//y is assigned by a|b|c|d|e
endmodule

