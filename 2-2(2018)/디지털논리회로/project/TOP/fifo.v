module fifo(clk,reset_n,opclear,rd_en,wr_en,din,dout,data_count); // fifo module
input clk, reset_n, rd_en,wr_en,opclear; // input port variables
input [31:0] din; // 32bit input port variable
output [31:0] dout; // 32bit output port variable
//wire full,empty; // output port variables
output [3:0] data_count; // 4bit output port variable

wire [2:0] head,next_head; // 3bit wire port variables
wire [2:0] tail,next_tail; // 3bit wire port variables
wire [2:0] state,next_state; // 3bit wire port variables
wire [3:0] next_data_count; // 4bit wire port variables

wire [31:0] rData,w; // 32bit wire port variables
wire we, re; // wire port variables

RF U0_Register_file(.clk(clk),.clear(opclear),.wAddr(tail),.wData(din),.we(we),.rAddr(head),.rData(rData)); // Register file module
_dff_3_r U0_dff_3_r(.clk(clk),.reset_n(reset_n),.d(next_state),.q(state));//Asynchronous 3bit D-flipflop module
_dff_3_r U1_dff_3_r(.clk(clk),.reset_n(reset_n),.d(next_head),.q(head));//Asynchronous 3bit D-flipflop module
_dff_3_r U2_dff_3_r(.clk(clk),.reset_n(reset_n),.d(next_tail),.q(tail));//Asynchronous 3bit D-flipflop module
_dff_4_r U0_dff_4_r(.clk(clk),.reset_n(reset_n),.d(next_data_count),.q(data_count));//Asynchronous 4bit D-flipflop module
_dff_32w_r U0_dff_32w_r(.clk(clk),.reset_n(reset_n),.next_data_count(next_data_count),.a(rData),.d(w),.q(dout));//Asynchronous 32bit D-flipflop module
mx2 U0_m2(.a(rData),.y(w),.en(re)); // MUX 2 module instance
//fifo_out U0_fifo_out(.state(state),.data_count(data_count),.full(full),.empty(empty)); // fifo out logic module instance
fifo_cal_addr U0_fifo_cal_addr(.state(next_state),.head(head),.tail(tail),.data_count(data_count),.we(we),.re(re),.next_head(next_head),.next_tail(next_tail),.next_data_count(next_data_count)); // fifo calculate logic module instance
fifo_ns U0_fifo_ns(.op_clear(opclear),.wr_en(wr_en),.rd_en(rd_en),.state(state),.data_count(data_count),.next_state(next_state)); // fifo next state logic module instance


endmodule

module fifo_cal_addr(state,head,tail,data_count,we,re,next_head,next_tail,next_data_count); // fifo calculate address module
input [2:0] state, head, tail; // 3bit input port variables
input [3:0] data_count; // 4bit input port variable
output we,re; // output port variables
output [2:0] next_head,next_tail; //3bit output port variables
output [3:0] next_data_count; // 4bit output port variable

parameter INIT =3'b000; // INIT
parameter NO_OP=3'b001; // NO_OP
parameter WRITE =3'b010; // WRITE
parameter WR_ERROR =3'b011; // WR_ERROR
parameter READ =3'b100; // READ
parameter RD_ERROR =3'b101; // RD_ERROR

reg we,re; // reg port variables
reg [2:0] next_head,next_tail; // 3bit reg port variables
reg [3:0] next_data_count; // 4bit reg port variable

always@(state or head or tail or data_count) // execute when input port variables change
begin
case(state) // condition of state
INIT : // 3'b000
begin
next_head<=3'b000; // next head change
next_tail<=3'b000;  // next tail change
next_data_count<=4'b0000; // next data_count change
we<=1'b0; re<=1'b0; // next w,r enable change
end

NO_OP : // 3'b001
begin
next_head<=head; // next head change
next_tail<=tail;  // next tail change
next_data_count<=data_count; // next data_count change
if(data_count==4'b1000) we<=1'b0;
end

WRITE : // 3'b010
begin
if(data_count==4'b0111) next_tail<=tail;
else next_tail<=tail+3'b001; // next tail change
next_data_count<=data_count+4'b0001; // next data_count change
next_head<=head; // next head change
re<=1'b0; we<=1'b1; // next w,r enable change
end

WR_ERROR : // 3'b011
begin
next_head<=head; // next head change
next_tail<=tail;  // next tail change
next_data_count<=data_count; // next data_count change
we<=1'b0; re<=1'b0; // next w,r enable change
end

READ : // 3'b100
begin
if(data_count==4'b1000) next_tail<=tail+3'b001; // next tail change
else next_tail<=tail; // next tail change
next_data_count<=data_count+4'b1111; // next data_count change
next_head<=head+3'b001; // next head change
we<=1'b0; re<=1'b1; // next w,r enable change
end

RD_ERROR : // 3'b101
begin
next_head<=head; // next head change
next_tail<=tail; // next tail change
next_data_count<=data_count; // next data_count change
re<=1'b0; we<=1'b0; // next w,r enable change
end

default : // default
begin
next_data_count<=4'bx; // next data_count change
next_head<=3'bx; // next head change
next_tail<=3'bx; // next tail change
we<=1'bx; re<=1'bx; // next w,r enable change
end

endcase
end

endmodule


module fifo_ns(op_clear,wr_en,rd_en,state,data_count,next_state); // fifo next state logic
input wr_en, rd_en,op_clear; // input port variables
input [2:0] state; // 3bit input port variable
input [3:0] data_count; // 4bit input port variable
output [2:0] next_state; // 3bit output port variable

parameter INIT =3'b000; // INIT
parameter NO_OP =3'b001; // NO_OP
parameter WRITE =3'b010; // WRITE
parameter WR_ERROR =3'b011; // WR_ERROR
parameter READ =3'b100; // READ
parameter RD_ERROR =3'b101; // RD_ERROR

reg [2:0] next_state; // 3bit reg port variable

always@(wr_en or rd_en or data_count or state or op_clear) // when input port variables change
begin
case(state) // state come in
INIT : // reset state
begin
if(op_clear==1'b1) next_state<=INIT;
else if(wr_en==1'b1 && rd_en==1'b1) next_state<=NO_OP; //all enables are high
else if(wr_en==1'b1) // wr enable is high
	begin
	if(data_count==4'b1000) next_state<=WR_ERROR; // full queue
	else next_state<=WRITE; // write state
	end
else if(rd_en==1'b1) // rd enable is high
	begin
	if(data_count==4'b0000) next_state<=RD_ERROR; // empty queue
	else next_state<=READ; // read state
	end
else next_state<=NO_OP; // else case
end

NO_OP : // Load state
begin
if(op_clear==1'b1) next_state<=INIT;
else if(wr_en==1'b1 && rd_en==1'b1) next_state<=NO_OP; //all enables are high
else if(wr_en==1'b1) // wr enable is high
	begin
	if(data_count==4'b1000) next_state<=WR_ERROR; // full queue
	else next_state<=WRITE; // write state
	end
else if(rd_en==1'b1) // rd enable is high
	begin
	if(data_count==4'b0000) next_state<=RD_ERROR; // empty queue
	else next_state<=READ; // read state
	end
else next_state<=NO_OP; // else case
end

WRITE : // increase state
begin
if(op_clear==1'b1) next_state<=INIT;
else if(wr_en==1'b1 && rd_en==1'b1) next_state<=NO_OP; //all enables are high
else if(wr_en==1'b1) // wr enable is high
	begin
	if(data_count==4'b1000) next_state<=WR_ERROR; // full queue
	else next_state<=WRITE; // write state
	end
else if(rd_en==1'b1) // rd enable is high
	begin
	if(data_count==4'b0000) next_state<=RD_ERROR; // empty queue
	else next_state<=READ; // read state
	end
else next_state<=NO_OP; // else case
end

WR_ERROR : // increase state
begin
if(op_clear==1'b1) next_state<=INIT;
else if(wr_en==1'b1 && rd_en==1'b1) next_state<=NO_OP; //all enables are high
else if(wr_en==1'b1) // wr enable is high
	begin
	if(data_count==4'b1000) next_state<=WR_ERROR; // full queue
	else next_state<=WRITE; // write state
	end
else if(rd_en==1'b1) // rd enable is high
	begin
	if(data_count==4'b0000) next_state<=RD_ERROR; // empty queue
	else next_state<=READ; // read state
	end
else next_state<=NO_OP; // else case
end

READ : // decrease state
begin
if(op_clear==1'b1) next_state<=INIT;
else if(wr_en==1'b1 && rd_en==1'b1) next_state<=NO_OP; //all enables are high
else if(wr_en==1'b1) // wr enable is high
	begin
	if(data_count==4'b1000) next_state<=WR_ERROR; // full queue
	else next_state<=WRITE; // write state
	end
else if(rd_en==1'b1) // rd enable is high
	begin
	if(data_count==4'b0000) next_state<=RD_ERROR; // empty queue
	else next_state<=READ; // read state
	end
else next_state<=NO_OP; // else case
end

RD_ERROR : // decrease state
begin
if(op_clear==1'b1) next_state<=INIT;
else if(wr_en==1'b1 && rd_en==1'b1) next_state<=NO_OP; //all enables are high
else if(wr_en==1'b1) // wr enable is high
	begin
	if(data_count==4'b1000) next_state<=WR_ERROR; // full queue
	else next_state<=WRITE; // write state
	end
else if(rd_en==1'b1) // rd enable is high
	begin
	if(data_count==4'b0000) next_state<=RD_ERROR; // empty queue
	else next_state<=READ; // read state
	end
else next_state<=NO_OP; // else case
end


default : next_state=3'bxxx; // default state
endcase
end

endmodule


module fifo_out(state,data_count,full,empty); // fifo_out logic module
input [2:0] state; // 3bit input port variable
input [3:0] data_count; // 4bit input port variable
output full,empty; // output port variables

parameter INIT =3'b000; // INIT
parameter NO_OP=3'b001; // NO_OP
parameter WRITE =3'b010; // WRITE
parameter WR_ERROR =3'b011; // WR_ERROR
parameter READ =3'b100; // READ
parameter RD_ERROR =3'b101; // RD_ERROR

reg wr_ack,wr_err,rd_ack,rd_err,full,empty; // reg port variables

always@(state or data_count) // when input port variables change
begin
case(state) // come in change
INIT : // 3'b000
begin
full=1'b0; 
empty=1'b1;
end

NO_OP : // 3'b001
begin 
if(data_count==4'b0000) // when queue is empty
begin
full=1'b0; 
empty=1'b1;
end
else if(data_count==4'b1000) // when queue is full
begin
full=1'b1; 
empty=1'b0;
end
else // when queue is not full and empty
begin
full=1'b0; 
empty=1'b0;
end
end

WRITE :  // 3'b010
begin
if(data_count==4'b1000) // when queue is full
begin
full=1'b1; 
empty=1'b0;
end
else // when queue is not full
begin
full=1'b0; 
empty=1'b0;
end
end

WR_ERROR : // 3'b011
begin
full=1'b1; 
empty=1'b0;
end

READ :  // 3'b100
begin
if(data_count==4'b0000)// when queue is empty
begin
full=1'b0; 
empty=1'b1;
end
else // when queue is not empty
begin
full=1'b0; 
empty=1'b0;
end
end

RD_ERROR : // 3'b101
begin
full=1'b0; 
empty=1'b1;
end

default : // default
begin 
full=1'bx; 
empty=1'bx;
end

endcase
end

endmodule

