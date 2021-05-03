module cc_logic(op, shamt, d_in, d_out, do_next);
//coding combinational circuits 
input [2:0] op;
input [1:0] shamt;
input [7:0] d_in;
input [7:0] d_out;
output [7:0] do_next;
reg [7:0] do_next;
//input, output 선언 
wire [7:0] d_lsl;
wire [7:0] d_lsr;
wire [7:0] d_asr;

parameter NOP = 3'b000;
parameter LOAD = 3'b001;
parameter LSL = 3'b010;
parameter LSR = 3'b011;
parameter ASR = 3'b100;
//encoding states

always @ (op, shamt, d_in, d_out, d_lsl, d_lsr, d_asr)
//always op, shamt ... change
begin
case(op)
NOP     : do_next <= d_out;
LOAD    : do_next <= d_in;
LSL     : do_next <= d_lsl;
LSR     : do_next <= d_lsr;
ASR     : do_next <= d_asr;
default : do_next <= 8'bx;
endcase 
//select do_next
end 

LSL8 U0_LSL8(.d_in(d_out), .shamt(shamt),.d_out(d_lsl));
LSR8 U0_LSR8(.d_in(d_out), .shamt(shamt),.d_out(d_lsr));
ASR8 U0_ASR8(.d_in(d_out), .shamt(shamt),.d_out(d_asr));
//instance of LSL8, LSR8, ASR8
endmodule 