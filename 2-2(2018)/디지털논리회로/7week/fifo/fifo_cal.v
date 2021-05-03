module fifo_cal(state,head, tail, data_count, we, re, next_head, next_tail, next_data_count);
//calculate address module
input [2:0] state, head, tail;
input [3:0] data_count;
output we, re;
output [2:0] next_head, next_tail;
output [3:0] next_data_count;
reg we, re;
reg [2:0] next_head, next_tail;
reg [3:0] next_data_count;

parameter INIT_STATE     = 3'b000;
parameter NO_OP_STATE    = 3'b001;
parameter WRITE_STATE    = 3'b010;
parameter WR_ERROR_STATE = 3'b011;
parameter READ_STATE     = 3'b100;
parameter RD_ERROR_STATE = 3'b101;
//binary encoding state

always @ (state, head, tail, data_count)
//always input change
begin
case(state)
INIT_STATE: begin
next_head = head;
next_tail = tail;
next_data_count = data_count;
we = 1'b0;
re = 1'b0;
end
//INIT일 때 head=tail=0 no change

NO_OP_STATE: begin
next_head = head;
next_tail = tail;
next_data_count = data_count;
we = 1'b0;
re = 1'b0;
end 
//NO_OP일 때 no change

WRITE_STATE: begin
next_head = head;
next_tail = tail +3'b001;
next_data_count = data_count + 4'b0001;
we = 1'b1;
re = 1'b0;
end 
//WRITE일 때 tail++, data_count++

WR_ERROR_STATE: begin
next_head = head;
next_tail = tail;
next_data_count = data_count;
we = 1'b0;
re = 1'b0;
end
//nochange

READ_STATE: begin
next_head = head + 3'b001;
next_tail = tail;
next_data_count = data_count - 4'b0001;
we = 1'b0;
re = 1'b1;
end
//READ일 때 head++, data_count--

RD_ERROR_STATE: begin
next_head = head;
next_tail = tail;
next_data_count = data_count;
we = 1'b0;
re = 1'b0;
end 
//nochange

default: begin
next_head = 3'bxxx;
next_tail = 3'bxxx;
next_data_count = 4'bxxxx;
we=1'bx;
re=1'bx;
end 

endcase
end
endmodule 