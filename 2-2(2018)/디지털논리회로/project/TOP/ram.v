module ram(clk, cen, wen, addr, din, dout); //memory module
input clk; // input variable
input cen,wen;  // input variables
input [4:0] addr; // 5bit input variable
input [31:0] din; // 32bit input variable
output reg [31:0] dout; // 32bit output variable

reg [31:0] mem [0:31]; // 32*32 reg variable

integer i; // integer variable

initial begin
for(i=1'b0; i<10'd32; i=i+1)	// memory reset to zero
begin
mem[i]=32'b0; // to zero
end
end

always @ (posedge clk) // sequential logic
begin
if(cen==1'b1 && wen==1'b1) // write memory condition
begin
mem[addr]<=din; // write memory
dout<=32'b0; // print zero
end

else if(cen==1'b1 && wen==1'b0) // print condition
begin
dout<=mem[addr]; // print memory
end

else if(cen==1'b0) // reset condition
begin
dout<=1'b0; // to zero
end

end


endmodule
