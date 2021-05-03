module multiplier(fifo0_data_count,fifo1_data_count,clk,reset_n,op_start,op_clear,multiplicand,multiplier,out_result,op_done,fifo_re,fifo_we);
// multiplier module
input clk,reset_n,op_clear,op_start;          //    input's port variable
input [3:0] fifo0_data_count,fifo1_data_count;
input [31:0] multiplicand,multiplier;          //   32-bit input's port variable
output op_done,fifo_re,fifo_we;          //    output's port variable
output [31:0] out_result;          //    32-bit output's port variable

wire [31:0] result, next_result;          //    32-bit wire port variable
wire [1:0] next_state, state;          //    2-bit wire port variable
wire [2:0] next_count, count;          //    3-bit wire port variable
wire [4:0] booth;          //    5-bit wire port variable


//flip flop module instance
_dff_2_r U0_dff_2_r(.clk(clk),.reset_n(reset_n),.d(next_state),.q(state));
_dff_3_r U0_dff_3_r(.clk(clk),.reset_n(reset_n),.d(next_count),.q(count));
_dff_32_r U0_dff_32_r(.clk(clk),.reset_n(reset_n),.d(next_result),.q(result));
// separate and encode to booth module
boothAlgo U0_boothAlgo(.multiplier(multiplier),.count(next_count),.booth(booth));
// multiplier logic module
multiplier_ns U0_multiplier_ns(.fifo0_data_count(fifo0_data_count),.fifo1_data_count(fifo1_data_count),.op_start(op_start),.op_clear(op_clear),.count(count),.state(state),.next_state(next_state),.next_count(next_count));
multiplier_cal U0_multiplier_cal(.multiplicand(multiplicand),.booth(booth),.count(count),.state(state),.result(result),.next_result(next_result));
multiplier_out U0_multiplier_out(.count(count),.state(state),.op_done(op_done),.fifo_re(fifo_re),.fifo_we(fifo_we),.result(result),.out_result(out_result));


endmodule

module multiplier_cal(multiplicand,booth,count,state,result,next_result);
// calculation module
input [31:0] multiplicand;          //    32 -bit input's port variable
input [4:0] booth;          //    3-bit input's port variable
input [1:0] state;          //    2-bit input's port variable
input [31:0] result;          //    64-bit input's port variable
input [2:0] count;          //    5-bit input's port variable
output reg [31:0] next_result;          //    64 -bit output's port variable

wire [31:0] adding1;          //    32-bit wire port variable
wire [31:0] subing1;          //    32-bit wire port variable
wire [31:0] adding2;          //    32-bit wire port variable
wire [31:0] subing2;          //    32-bit wire port variable
wire [31:0] adding3;          //    32-bit wire port variable
wire [31:0] subing3;          //    32-bit wire port variable
wire [31:0] adding4;          //    32-bit wire port variable
wire [31:0] subing4;          //    32-bit wire port variable
wire [31:0] adding5;          //    32-bit wire port variable
wire [31:0] subing5;          //    32-bit wire port variable
wire [31:0] adding6;          //    32-bit wire port variable
wire [31:0] subing6;          //    32-bit wire port variable
wire [31:0] adding7;          //    32-bit wire port variable
wire [31:0] subing7;          //    32-bit wire port variable
wire [31:0] adding8;          //    32-bit wire port variable
wire [31:0] subing8;          //    32-bit wire port variable

parameter IDLE =2'b00;          //    IDLE state
parameter EXEC =2'b01;          //    EXEC state
parameter OUT  =2'b10;
parameter DONE =2'b11;          //    DONE state

always@(*)// change when input's port variable come in

begin
case(state)          //    case condition
IDLE : begin          //    IDLE state
		next_result<=32'b0;          //    reset result
		end

EXEC : begin          //    EXEC state
		case(booth)
		5'b00000 : begin          //    shift case
					if(count==3'b000) next_result=32'b0;
					next_result=result>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];					
					end
		5'b00001 : begin          //    add +A case
					if(count==3'b000) next_result=32'b0;
					next_result=adding1>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b00010 : begin          //    add +A case
					if(count==3'b000) next_result=32'b00;
					next_result=adding1>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b00011 : begin          //    add +2A case
					if(count==3'b000) next_result=32'b0;
					next_result=adding2>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b00100 : begin          //    add +2A case
					if(count==3'b000) next_result=32'b0;
					next_result=adding2>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b00101 : begin          //    add +3A case
					if(count==3'b000) next_result=32'b0;
					next_result=adding3>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b00110 : begin          //    add +3A case
					if(count==3'b000) next_result=32'b0;
					next_result=adding3>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b00111 : begin          //    add +4A case
					if(count==3'b000) next_result=32'b0;
					next_result=adding4>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b01000 : begin          //    add +4A case
					if(count==3'b000) next_result=32'b0;
					next_result=adding4>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b01001 : begin          //    add +5A case
					if(count==3'b000) next_result=32'b0;
					next_result=adding5>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b01010 : begin          //    add +5A case
					if(count==3'b000) next_result=32'b0;
					next_result=adding5>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b01011 : begin          //    add +6A case
					if(count==3'b000) next_result=32'b0;
					next_result=adding6>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b01100 : begin          //    add +6A case
					if(count==3'b000) next_result=32'b0;
					next_result=adding6>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b01101 : begin          //    add +7A case
					if(count==3'b000) next_result=32'b0;
					next_result=adding7>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b01110 : begin          //    add +7A case
					if(count==3'b000) next_result=32'b0;
					next_result=adding7>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b01111 : begin          //    add +8A case
					if(count==3'b000) next_result=32'b0;
					next_result=adding8>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];	
					end
		5'b10000 : begin          //    sub -8A case
					if(count==3'b000) next_result=32'b0;
					next_result=subing8>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b10001 : begin          //    sub -7A case
					if(count==3'b000) next_result=32'b0;
					next_result=subing7>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b10010 : begin          //    sub -7A case
					if(count==3'b000) next_result=32'b0;
					next_result=subing7>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b10011 : begin          //    sub -6A case
					if(count==3'b000) next_result=32'b0;
					next_result=subing6>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b10100 : begin          //    sub -6A case
					if(count==3'b000) next_result=32'b0;
					next_result=subing6>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end 
		5'b10101 : begin// sub -5A case
					if(count==3'b000) next_result=32'b0;
					next_result=subing5>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b10110 : begin          //    sub -5A case
					if(count==3'b000) next_result=32'b0;
					next_result=subing5>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b10111 : begin// sub -4A case
					if(count==3'b000) next_result=32'b0;
					next_result=subing4>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b11000 : begin// sub -4A case
					if(count==3'b000) next_result=32'b0;
					next_result=subing4>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b11001 : begin// sub -3A case
					if(count==3'b000) next_result=32'b0;
					next_result=subing3>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b11010 : begin// sub -3A case
					if(count==3'b000) next_result=32'b0;
					next_result=subing3>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b11011 : begin// sub -2A case
					if(count==3'b000) next_result=32'b0;
					next_result=subing2>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b11100 : begin// sub -2A case
					if(count==3'b000) next_result=32'b0;
					next_result=subing2>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b11101 : begin// sub -A case
					if(count==3'b000) next_result=32'b0;
					next_result=subing1>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b11110 : begin// sub -A case
					if(count==3'b000) next_result=32'b0;
					next_result=subing1>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];
					end
		5'b11111 : begin          //    shift case
					if(count==3'b000) next_result=32'b0;
					next_result=result>>4;
					next_result[31]=next_result[27];
					next_result[30]=next_result[27];
					next_result[29]=next_result[27];
					next_result[28]=next_result[27];	
					end
		default : begin          //    default case
					next_result=32'bx;
					end					
		endcase
		end

OUT : begin          //    OUT state
			next_result<= result;          //    state nochange
		end

DONE : begin          //    DONE state
			next_result<= result;          //    state nochange
		 end
default : begin
				next_result<=32'bx;
			end
endcase
end
cla32_16 U0_cla32_16(.a(result),.b(multiplicand[15:0]),.ci(1'b0),.s(adding1),.co());          //   cla32_16 module instance
cla32_16 U1_cla32_16(.a(adding1),.b(multiplicand[15:0]),.ci(1'b0),.s(adding2),.co());          //   cla32_16 module instance
cla32_16 U2_cla32_16(.a(adding2),.b(multiplicand[15:0]),.ci(1'b0),.s(adding3),.co());          //   cla32_16 module instance
cla32_16 U3_cla32_16(.a(adding3),.b(multiplicand[15:0]),.ci(1'b0),.s(adding4),.co());          //   cla32_16 module instance
cla32_16 U4_cla32_16(.a(adding4),.b(multiplicand[15:0]),.ci(1'b0),.s(adding5),.co());          //   cla32_16 module instance
cla32_16 U5_cla32_16(.a(adding5),.b(multiplicand[15:0]),.ci(1'b0),.s(adding6),.co());          //   cla32_16 module instance
cla32_16 U6_cla32_16(.a(adding6),.b(multiplicand[15:0]),.ci(1'b0),.s(adding7),.co());          //   cla32_16 module instance
cla32_16 U7_cla32_16(.a(adding7),.b(multiplicand[15:0]),.ci(1'b0),.s(adding8),.co());          //   cla32_16 module instance

cla32_16 U10_cla32_16(.a(result),.b(~multiplicand[15:0]),.ci(1'b1),.s(subing1),.co());          //   cla32_16 module instance
cla32_16 U11_cla32_16(.a(subing1),.b(~multiplicand[15:0]),.ci(1'b1),.s(subing2),.co());          //   cla32_16 module instance
cla32_16 U12_cla32_16(.a(subing2),.b(~multiplicand[15:0]),.ci(1'b1),.s(subing3),.co());          //   cla32_16 module instance
cla32_16 U13_cla32_16(.a(subing3),.b(~multiplicand[15:0]),.ci(1'b1),.s(subing4),.co());          //   cla32_16 module instance
cla32_16 U14_cla32_16(.a(subing4),.b(~multiplicand[15:0]),.ci(1'b1),.s(subing5),.co());          //   cla32_16 module instance
cla32_16 U15_cla32_16(.a(subing5),.b(~multiplicand[15:0]),.ci(1'b1),.s(subing6),.co());          //   cla32_16 module instance
cla32_16 U16_cla32_16(.a(subing6),.b(~multiplicand[15:0]),.ci(1'b1),.s(subing7),.co());          //   cla32_16 module instance
cla32_16 U17_cla32_16(.a(subing7),.b(~multiplicand[15:0]),.ci(1'b1),.s(subing8),.co());          //   cla32_16 module instance

endmodule

module multiplier_ns(fifo0_data_count,fifo1_data_count,op_start,op_clear,count,state,next_state,next_count);
//next state module
input op_start,op_clear;          //    input's port variable
input[1:0] state;          //    2-bit input's port variable
input [2:0] count;          //    5-bit input's port variable
input [3:0] fifo0_data_count,fifo1_data_count;

output reg [1:0] next_state;          //    2-bit output reg port variable
output reg [2:0] next_count;          //    3-bit output reg port variable


parameter IDLE =2'b00;          //    state IDLE
parameter EXEC =2'b01;          //    state EXEC
parameter OUT  =2'b10;           //    state OUT
parameter DONE =2'b11;          //    state DONE
// when input's port variable come in

always@(op_clear or op_start or state or count or fifo0_data_count or fifo1_data_count )          //    always condtion 
begin
case(state)
IDLE : 
begin
if(op_clear==1'b1) begin          //    clear come in
		next_state<=IDLE;          //    next state set
		next_count<=3'b000;          //    next count set
		end
else if(op_start==1'b0) begin 
		next_state<=state;          //    next state set
		next_count<=3'b000;          //    next count set
		end
else begin
		next_state<=EXEC;          //    start come in
		next_count<=3'b0;          //    count reset
		end
end

EXEC :          //    EXEC state
begin
if(op_clear==1'b1) begin          //    clear set
		next_state<=IDLE;          //    next state set
		next_count<=3'b000;          //    next count set
		end
else if(count==3'b011)begin          //    end calculate
		next_state<=OUT;          //    next state set
		next_count<=count+3'b001;          //    next count set
		end
else begin          //    calculating
		next_state<=EXEC;          //    next state set
		next_count<=count+3'b001;          //    next count set
	  end
end

OUT : 
begin
		if(op_clear==1'b1) begin          //    clear set
		next_state<=IDLE;          //    next state set
		next_count<=3'b000;          //    next count set
		end
		else if(fifo0_data_count==4'b0000 && fifo1_data_count==4'b0000) begin          //    DONE condtion
		next_state<=DONE;          //    next is DONE
		next_count<=3'b0;
		end
		else begin
		next_state<=IDLE;          //    next state set
		next_count<=3'b000;          //    next count set
		end
end

DONE :          //    DONE state
begin
if(op_clear==1'b1) begin          //    clear set
		next_state<=IDLE;          //    next state set
		next_count<=3'b000;          //    next_count set
		end
if(op_start==1'b1) begin 
		next_state<=DONE;          //    next state set
		next_count<=count;          //    next_count set
		end
else begin          //    change next state
		next_state<=IDLE;          //    next state set
		next_count<=3'b000;          //    next_count set
		end
end

default : begin          //    default state
		next_state<=2'bx;          //    next state set
		next_count<=3'bx;          //    next_count set
	  end
endcase


end
endmodule

module multiplier_out(count,state,op_done,fifo_re,fifo_we,result,out_result);          //    output module
input [1:0] state;          //    2-bit input's port variable
input [2:0] count;
input [31:0] result;
output reg op_done,fifo_re,fifo_we;          //    output's port variable
output reg [31:0] out_result;

parameter IDLE =2'b00;          //    IDLE state
parameter EXEC =2'b01;          //    EXEC state
parameter OUT  =2'b10;          //    OUT stata
parameter DONE =2'b11;          //    DONE state

always@(state or result or count)          //    always condition
begin 
case(state)          //   case condition
IDLE : begin
		fifo_re<=1'b0;
		fifo_we<=1'b0;
		op_done<=1'b0;          //    IDLE state output
		out_result<=result;
		end
EXEC : begin 
		if(count==3'b011) fifo_re<=1'b1;
		else fifo_re<=1'b0;
		fifo_we<=1'b0;
		op_done<=1'b0;          //    EXEC state output
		out_result<=result;
		end
OUT : begin 
		fifo_re<=1'b0;
		fifo_we<=1'b1;
		op_done<=1'b0;          //    OUT state output
		out_result<=result;
		end
DONE : begin
		fifo_re<=1'b0;
		fifo_we<=1'b0;
		op_done<=1'b1;          //    DONE state output
		out_result<=result;
		end
default : begin
		fifo_re<=1'bx;
		fifo_we<=1'bx;
		op_done<=1'bx;          //    default state output
		out_result<=32'bx;
		end
endcase
end

endmodule

module boothAlgo(multiplier,count,booth);          //    separate multiplier module
input [31:0] multiplier;          //    32-bit input varable
input [2:0] count;          //    3-bit varable
output reg [4:0] booth;          //   5-bit output reg varable

always@(multiplier or count)          //    when new data come in
begin
case(count)          //    case condition
// Multiplier separation according to count
3'b000 : booth <= 5'bx;          //    initial set
3'b001 : booth <= {multiplier[3:0],1'b0};          //    Detach with first zero
3'b010 : booth <= multiplier[7:3];
3'b011 : booth <= multiplier[11:7];
3'b100 : booth <= multiplier[15:11];

default : booth <= 5'bx;          //    default case
endcase
end
endmodule
