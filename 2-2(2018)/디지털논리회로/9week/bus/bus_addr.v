module bus_addr(S_address, S0_sel, S1_sel);
//address decoder module 
input [7:0] S_address;
output reg S0_sel, S1_sel;

wire [2:0] upper_3bit;
assign upper_3bit = S_address[7:5];
//upper = S_address의 상위 3bit 
always @ (upper_3bit, S_address)
begin
if(upper_3bit == 3'b000)
{S0_sel,S1_sel} = 2'b10;
else if (upper_3bit == 3'b001)
{S0_sel,S1_sel} = 2'b01;
else
{S0_sel, S1_sel} = 2'b00;
end 

endmodule 