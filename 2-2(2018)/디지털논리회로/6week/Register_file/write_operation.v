module _3_to_8_decoder(d,q);
//decoder module 
input [2:0] d;
output reg [7:0] q;

always @ (d)
begin
case(d)
3'b000  : q <= 8'b00000001;
3'b001  : q <= 8'b00000010;
3'b010  : q <= 8'b00000100;
3'b011  : q <= 8'b00001000;
3'b100  : q <= 8'b00010000;
3'b101  : q <= 8'b00100000;
3'b110  : q <= 8'b01000000;
3'b111  : q <= 8'b10000000;
default : q <= 8'hx;
//output q 8비트로 지정 
endcase 
end 
endmodule 

module write_operation(Addr, we, to_reg);
input we;
input [2:0] Addr;
output [7:0] to_reg;

wire [7:0] write_wire;

_3_to_8_decoder U0_3_to_8_decoder(.d(Addr[2:0]),.q(write_wire[7:0]));
_and2 U0_and2(.a(we),.b(write_wire[0]),.y(to_reg[0]));
_and2 U1_and2(.a(we),.b(write_wire[1]),.y(to_reg[1]));
_and2 U2_and2(.a(we),.b(write_wire[2]),.y(to_reg[2]));
_and2 U3_and2(.a(we),.b(write_wire[3]),.y(to_reg[3]));
_and2 U4_and2(.a(we),.b(write_wire[4]),.y(to_reg[4]));
_and2 U5_and2(.a(we),.b(write_wire[5]),.y(to_reg[5]));
_and2 U6_and2(.a(we),.b(write_wire[6]),.y(to_reg[6]));
_and2 U7_and2(.a(we),.b(write_wire[7]),.y(to_reg[7]));
//instance of decoder, 2-input and gates
endmodule 