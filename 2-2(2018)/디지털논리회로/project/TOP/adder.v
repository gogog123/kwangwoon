module adder_cal(din,state,data_count,result,next_result); // adder cal logic module
input [1:0] state; // input port variable
input [1:0] data_count; // input port variable
input [31:0] result,din; // input port variable
output reg [31:0] next_result; // output port variable

wire [31:0] add_middle; // wire port variable

parameter IDLE =2'b00; // state IDLE
parameter EXEC =2'b01; // state EXEC
parameter OUT  =2'b10;  // state OUT
parameter DONE =2'b11; // state DONE

always@(*) // always execution when satisfy condition
begin
case(state) // case of state
IDLE : next_result<=32'b0; // IDLE

EXEC : begin // EXEC
		case(data_count)
		2'b00 : next_result<=result;
		2'b01 : next_result<=din;
		2'b10 : next_result<=add_middle; // result of two inputs add_middle
		default : next_result<=32'bx;
		endcase
		end
OUT : next_result<= result; // result nochange, OUT state

DONE : next_result<= result; // result nochange, DONE state
		 
default : next_result<=32'bx; // default
endcase 
end

cla32 U0_cla32(.a(result),.b(din),.ci(1'b0),.s(add_middle),.co()); // cla for two inputs add_middle
endmodule

module adder_ns(fifo_data_count,op_start,op_clear,wAddr,data_count,state,next_state,next_data_count,next_wAddr);
//next state module
input [2:0] wAddr; // input port variable
input op_start,op_clear; // input port variable
input [3:0] fifo_data_count; // input port variable
input[1:0] state; // 2bit input port variable
input [1:0] data_count; // 2bit input port variable

output reg [1:0] next_state; // 2bit output reg port variable
output reg [1:0] next_data_count; // 2bit output reg port variable
output reg [2:0] next_wAddr; // 3bit output reg port variable

parameter IDLE =2'b00; // state IDLE
parameter EXEC =2'b01; // state EXEC
parameter OUT  =2'b10;  // state OUT
parameter DONE =2'b11; // state DONE
// when input port variable come in

always@(*) // combinational logic
begin
case(state) // condition
IDLE : 
begin
if(op_clear==1'b1) begin // clear come in
		next_state<=IDLE; // next state set
		next_data_count<=2'b00; // next data_count set
		next_wAddr<=3'b0;
		end
else if(op_start==1'b0) begin // start come in
		next_state<=state; // next state set
		next_data_count<=2'b00; // next data_count set
		next_wAddr<=3'b0;
		end
else begin // else
		next_state<=EXEC; // exec state come in
		next_data_count<=2'b0;
		next_wAddr<=wAddr;
		end
end

EXEC : // EXEC state
begin
if(op_clear==1'b1) begin // clear set
		next_state<=IDLE; // next state set
		next_data_count<=2'b00; // next data_count set
		next_wAddr<=3'b0;
		end
else if(data_count==2'b10)begin // end calculate
		next_state<=OUT; // next state set
		next_data_count<=data_count; // next data_count set
		next_wAddr<=wAddr;
		end
else begin // calculating
		next_state<=EXEC; // next state set
		next_data_count<=data_count+2'b01; // next data_count set
		next_wAddr<=wAddr;
	  end
end

OUT : // OUT state
begin
		if(op_clear==1'b1) begin // clear set
		next_state<=IDLE; // next state set
		next_data_count<=2'b00; // next data_count set
		next_wAddr<=3'b0;
		end
		else if(fifo_data_count==4'b0000) begin // fifo empty
		next_state<=DONE; // done state come in
		next_data_count<=2'b0; // reset
		next_wAddr<=wAddr;
		end
		else begin
		next_state<=IDLE; // next state set
		next_data_count<=2'b00; // next data_count set
		next_wAddr<=wAddr+3'b001; // address increasement 
		end
end

DONE : // DONE state
begin
if(op_clear==1'b1) begin // clear set
		next_state<=IDLE; // next state set
		next_data_count<=2'b00; // next_data_count set
		next_wAddr<=3'b0; // next address set
		end
else if(op_start==1'b1) begin // clear set
		next_state<=DONE; // next state set
		next_data_count<=2'b00; // next_data_count set
		next_wAddr<=wAddr; // next address set
		end
else begin // change next state
		next_state<=IDLE; // next state set
		next_data_count<=2'b00; // next_data_count set
		next_wAddr<=wAddr; // next address set
		end
end

default : begin // default state
		next_state<=2'bx; // next state set
		next_data_count<=2'bx; // next_data_count set
		next_wAddr<=3'bx;
	  end
endcase


end
endmodule

module adder_out(state,data_count,result,out_result,fifo_re,op_done,RF_we); // adder output logic
input [1:0] state; // 2bit input port variable
input [1:0] data_count; // 2bit input port variable
input [31:0] result; // 32bit input port variable
output reg op_done,fifo_re,RF_we; // output port variable
output reg [31:0] out_result; // 2bit output port variable

parameter IDLE =2'b00; // IDLE state
parameter EXEC =2'b01; // EXEC state
parameter OUT  =2'b10; // OUT state
parameter DONE =2'b11; // DONE state

always@(*) // always condition
begin 
case(state) //case condition
IDLE : begin // IDLE state
		fifo_re<=1'b0; // IDLE state output
		RF_we<=1'b0; // IDLE state output
		op_done<=1'b0; // IDLE state output
		out_result<=result; // IDLE state output
		end
EXEC : begin  // EXEC state output
		if(data_count==2'b10) // second inputting
		begin
		RF_we<=1'b1; // fifo read
		fifo_re<=1'b0;
		end
		else // first inputting
		begin
		fifo_re<=1'b1; // fifo read
		RF_we=1'b0;
		end
		
		op_done<=1'b0;
		out_result<=result;
		end
OUT : begin // OUT state
		fifo_re<=1'b0;
		RF_we<=1'b1; // fifo write
		op_done<=1'b0; // EXEC state output
		out_result<=result;
		end
DONE : begin // DONE state
		fifo_re<=1'b0;
		RF_we<=1'b0;
		op_done<=1'b1; // DONE state output
		out_result<=result;
		end
default : begin // default state
		fifo_re<=1'bx;
		RF_we<=1'bx;
		op_done<=1'bx; // default state output
		out_result<=32'bx;
		end
endcase
end

endmodule

module adder(din,op_start,clk,fifo_data_count,op_clear,reset_n,RF_we,op_done,out_result,fifo_re,wAddr); // Adder module
input clk,reset_n,op_clear,op_start; // input port variable
input [3:0] fifo_data_count; // input port variable
input [31:0] din; // input port variable
output op_done, fifo_re,RF_we; // output port variable
output [2:0] wAddr; // output port variable
output [31:0] out_result; // output port variable

wire [1:0] state, next_state,data_count,next_data_count; // wire port variable
wire [31:0] result,next_result; // wire port variable
wire [2:0] next_wAddr; // wire port variable
// flip-flop set
_dff_2_r U0_dff_2_r(.clk(clk),.reset_n(reset_n),.d(next_data_count),.q(data_count));
_dff_2_r U1_dff_2_r(.clk(clk),.reset_n(reset_n),.d(next_state),.q(state));
_dff_3_r U2_dff_3_r(.clk(clk),.reset_n(reset_n),.d(next_wAddr),.q(wAddr));
_dff_32_r U3_dff_32_r(.clk(clk),.reset_n(reset_n),.d(next_result),.q(result));

// adder state,cal,out logic module set
adder_ns U4_adder_ns(.fifo_data_count(fifo_data_count),.op_start(op_start),.op_clear(op_clear),.wAddr(wAddr),
.data_count(data_count),.state(state),.next_state(next_state),.next_data_count(next_data_count),.next_wAddr(next_wAddr));

adder_cal U5_adder_cal(.din(din),.state(state),.data_count(data_count),.result(result),.next_result(next_result));

adder_out U6_adder_out(.state(state),.data_count(data_count),.result(result),.out_result(out_result),.fifo_re(fifo_re),.op_done(op_done),.RF_we(RF_we));


endmodule


