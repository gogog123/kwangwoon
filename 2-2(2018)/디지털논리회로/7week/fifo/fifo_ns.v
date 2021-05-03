module fifo_ns(wr_en, rd_en, state, data_count, next_state);
//next state module
input wr_en, rd_en;
input [2:0] state;
input [3:0] data_count;
output [2:0] next_state;
reg [2:0] next_state;

parameter INIT_STATE     =3'b000;
parameter NO_OP_STATE    =3'b001;
parameter WRITE_STATE    =3'b010;
parameter WR_ERROR_STATE =3'b011;
parameter READ_STATE     =3'b100;
parameter RD_ERROR_STATE =3'b101;


always @ (wr_en, rd_en, state, data_count)
//always wr_en, rd_en, state, data_count
begin
case(state)
INIT_STATE:
if(wr_en == 0 && rd_en==0)           next_state = INIT_STATE; //reset
else if(wr_en==1 && rd_en==1)        next_state = NO_OP_STATE;
else if(wr_en ==1 && data_count <8)  next_state = WRITE_STATE;
else if(rd_en ==1 && data_count >0)  next_state = READ_STATE;
else if(rd_en ==1 && data_count ==0) next_state = RD_ERROR_STATE;
else                                 next_state = state;
//state INIT_STATE
NO_OP_STATE:
if(wr_en == 0 && rd_en==0)           next_state = NO_OP_STATE;
else if(wr_en==1 && rd_en==1)        next_state = NO_OP_STATE;
else if(wr_en ==1 && data_count <8)  next_state = WRITE_STATE;
else if(rd_en ==1 && data_count >0)  next_state = READ_STATE;
else if(wr_en ==1 && data_count ==8) next_state = WR_ERROR_STATE;
else if(rd_en ==1 && data_count ==0) next_state = RD_ERROR_STATE;
else                                 next_state = state;
//state NO_OP_STATE
WRITE_STATE:
if(wr_en ==1 && data_count <8)      next_state = WRITE_STATE;
else if(wr_en==1 && rd_en==1)       next_state = NO_OP_STATE;
else if(wr_en==0 && rd_en==0)       next_state = NO_OP_STATE;
else if(wr_en==1 && data_count ==8) next_state = WR_ERROR_STATE;
else if(rd_en==1)                   next_state = READ_STATE;
else                                next_state = state;
//state WRITE_STATE
READ_STATE: 
if(rd_en==1 && data_count >0)       next_state = READ_STATE;
else if(wr_en==1 && rd_en==1)       next_state = NO_OP_STATE;
else if(wr_en==0 && rd_en==0)       next_state = NO_OP_STATE;
else if(rd_en==1 && data_count ==0) next_state = RD_ERROR_STATE;
else if(wr_en==1)                   next_state = WRITE_STATE;
else                                next_state = state;
//state READ_STATE
WR_ERROR_STATE:
if(wr_en==1)                   next_state = WR_ERROR_STATE;
else if(wr_en==1 && rd_en==1)  next_state = NO_OP_STATE;
else if(wr_en ==0 && rd_en==0) next_state = NO_OP_STATE;
else if(rd_en==1)              next_state = READ_STATE;
else                           next_state = state;
//state WR_ERROR_STATE
RD_ERROR_STATE:
if(rd_en==1)                   next_state = RD_ERROR_STATE;
else if(wr_en==1 && rd_en==1)  next_state = NO_OP_STATE;
else if(wr_en ==0 && rd_en==0) next_state = NO_OP_STATE;
else if(wr_en==1)              next_state = WRITE_STATE;
else                           next_state = state;
//state RD_ERROR_STATE
default:                       next_state = 3'bxxx;
endcase
end 

endmodule 
