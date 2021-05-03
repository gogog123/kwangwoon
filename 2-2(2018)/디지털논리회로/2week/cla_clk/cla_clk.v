module cla_clk(clock,a,b,ci,s_cla,co_cla);//cla_clk module
input clock;
input [31:0] a,b;//32-bit input a,b
input ci;
output [31:0] s_cla;//32-bit output s_cla
output co_cla;

reg[31:0] reg_a, reg_b;//32-bit reg_a, reg_b
reg reg_ci;
reg [31:0] reg_s_cla;//32-bit reg_s_cla
reg reg_co_cla;

wire[31:0]wire_s_cla;//32-bit wire_s_cla
wire wire_co_cla;

always @(posedge clock) //positive edge 일때  
begin
reg_a           <=a;
reg_b           <=b;
reg_ci          <=ci;
reg_s_cla       <=wire_s_cla;
reg_co_cla      <=wire_co_cla;
end

//instance of cla32
cla32 U0_cla32(.a(reg_a),.b(reg_b),.ci(reg_ci),.s(wire_s_cla),.co(wire_co_cla));

assign s_cla=reg_s_cla;
assign co_cla=reg_co_cla;
endmodule