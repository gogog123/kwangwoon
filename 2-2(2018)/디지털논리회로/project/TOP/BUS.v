module BUS(clk, reset_n, M0_req, M0_wr, M0_address, M1_req, M1_wr, M1_address,M0_dout, M1_dout, S0_dout, S1_dout,S2_dout,S3_dout,
			M0_grant, M1_grant, M_din, S0_sel,S1_sel,S2_sel,S3_sel, S_address, S_wr, S_din);// bus module
			
	input clk; //input port variable
	input reset_n; //input port variable
	input M0_req, M1_req;  //input port variable
	input M0_wr,M1_wr; //input port variable
	input [7:0] M0_address,M1_address;  //input port variable
	input [31:0] M0_dout,M1_dout; //input port variable
	input [31:0] S0_dout,S1_dout,S2_dout,S3_dout; //input port variable
	
	output M0_grant, M1_grant; // output port variable
	output S0_sel,S1_sel,S2_sel,S3_sel; // output port variable
	output S_wr; // output port variable
	output [7:0] S_address; // output port variable
	output [31:0] M_din,S_din; // output port variable
	
	wire [3:0] w0_sel; //wire port variable
	
	//instance of modules
	bus_addr U0_bus_addr(.address(S_address), .S0_sel(S0_sel), .S1_sel(S1_sel),.S2_sel(S2_sel),.S3_sel(S3_sel)); // address module
	bus_arbit U1_bus_arbit(.clk(clk), .reset_n(reset_n),.M0_req(M0_req),.M1_req(M1_req),.M0_grant(M0_grant), .M1_grant(M1_grant)); // arbiter module
	mux2 U2_mux2(.d0(M0_wr),.d1(M1_wr),.sel({M0_grant,M1_grant}),.dout(S_wr)); // mux module
	mux2_8bit U3_mux2_8bit(.d0(M0_address),.d1(M1_address),.sel({M0_grant,M1_grant}),.dout(S_address)); // mux module
	mux2_32bit U4_mux2_32bit(.d0(M0_dout),.d1(M1_dout),.sel({M0_grant,M1_grant}),.dout(S_din)); // mux module
	mux5_32bit U5_mux5_32bit(.d0(S0_dout), .d1(S1_dout), .d2(S2_dout),.d3(S3_dout),.d4(32'h0), .sel(w0_sel), .dout(M_din)); // mux module
	_dff_4_r U6_dff_4_r(.clk(clk), .reset_n(reset_n), .d({S0_sel,S1_sel,S2_sel,S3_sel}), .q(w0_sel)); // flip-flop module

endmodule

module bus_addr(address,S0_sel,S1_sel,S2_sel,S3_sel);//bus address module
	input [7:0] address;	// input port variable
	output reg S0_sel,S1_sel,S2_sel,S3_sel; // output port variable
			
	always@(address) // address change condition
	begin
	if((address>=8'h00)&&(address<8'h20))begin // matrix set
		{S0_sel,S1_sel,S2_sel,S3_sel} = 4'b1000;
		end
	else if((address>=8'h20)&&(address<8'h40))begin // memory A set
		{S0_sel,S1_sel,S2_sel,S3_sel} = 4'b0100;
		end
	else if((address>=8'h40)&&(address<8'h60))begin // memory B set
		{S0_sel,S1_sel,S2_sel,S3_sel} = 4'b0010;
		end
	else if((address>=8'h60)&&(address<8'h80))begin // memory C set
		{S0_sel,S1_sel,S2_sel,S3_sel} = 4'b0001;
		end
	else {S0_sel,S1_sel,S2_sel,S3_sel} = 4'b0000; // other case
	end
endmodule

module bus_arbit(clk,reset_n,M0_req,M1_req,M0_grant,M1_grant);// bus arbiter module
	input clk; // input port variable
	input reset_n;	//input port variable
	input M0_req,M1_req;	//input port variable
	
	output reg M0_grant, M1_grant; //output port variable
	
	reg next_M0_grant, next_M1_grant; // reg port variable

	always@(posedge clk or negedge reset_n) // grant sequential logic
	begin
		if(~reset_n) begin // reset set
			M0_grant<=1'b1; 
			M1_grant<=1'b0; 
			end	//M0 Grant
		else	begin	// else
			M0_grant<=next_M0_grant;			
			M1_grant<=next_M1_grant; 
			end
	end
		
	always@(M0_grant,M1_grant,M0_req,M1_req) // grant combinational logic
	begin
	case({M0_grant,M1_grant}) // grant case
		2'b10: begin					
			if((M0_req==1'b0) && (M1_req==1'b1)) // M1 grant set
				begin
				next_M0_grant=1'b0;
				next_M1_grant=1'b1; // set
				end
			else 	// else case
				begin
				next_M0_grant=1'b1; // set
				next_M1_grant=1'b0;
				end
			end
		2'b01: begin		
			if(M1_req==1'b0) // M0 grant set
				begin
				next_M0_grant=1'b1; // set
				next_M1_grant=1'b0;
				end
			else 	// else case
				begin
				next_M0_grant=M0_grant;
				next_M1_grant=M1_grant;
				end
			end
		default: begin	// default case					
			next_M0_grant = 1'bx;
			next_M1_grant = 1'bx;end
	endcase
	end
endmodule
