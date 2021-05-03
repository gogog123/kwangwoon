module os_logic(state, d_in, d_out);
//output logic part
parameter IDLE_STATE = 3'b000;
parameter LOAD_STATE = 3'b001;
parameter INC_STATE = 3'b010;
parameter INC2_STATE = 3'b011;
parameter DEC_STATE = 3'b100;
parameter DEC2_STATE = 3'b101;
//binary encoding states

input [2:0] state;
input [7:0] d_in;
output [7:0] d_out;

reg [7:0] d_out;
wire [7:0] d_inc;
wire [7:0] d_dec;

always @ (state)
//always state change
begin
case(state)
IDLE_STATE : d_out <= 8'b00000000;
LOAD_STATE : d_out <= d_in;
INC_STATE  : d_out <= d_inc;
INC2_STATE : d_out <= d_inc;
DEC_STATE  : d_out <= d_dec;
DEC2_STATE : d_out <= d_dec;
default    : d_out <= 8'bx;
//state값을 통해 출력될 값을 계산 
endcase 
end

cla8 U0_cla8(.a(d_out),.b(8'b00000001),.ci(0),.s(d_inc)); //count 증가 
cla8 U1_cla8(.a(d_out),.b(8'b11111111),.ci(0),.s(d_dec)); //count 감소 
//instance of CLA

endmodule 