`timescale 1ns/100ps

module tb_dff_rs_sync_async;
reg tb_clk, tb_set_n, tb_reset_n, tb_d;
wire tb_q_sync, tb_q_async;

_dff_rs_sync_async U0_dff_rs_sync_async(.clk(tb_clk), .set_n(tb_set_n), .reset_n(tb_reset_n), 
                                        .d(tb_d), .q_sync(tb_q_sync), .q_async(tb_q_async));
always #15 tb_clk=~tb_clk;

initial
begin 
tb_clk=0; tb_set_n=0; tb_reset_n=0; tb_d=0;
#5 tb_d=1; tb_reset_n=1;
#2.5 tb_set_n=1;
#5 tb_set_n=0;
#2.5 tb_reset_n=0;
#2.5 tb_set_n=1;
#5 tb_set_n=0;
#2.5 tb_reset_n=1;
#2.5 tb_set_n=1;
#5 tb_set_n=0;
#2.5 tb_reset_n=0;
#2.5 tb_set_n=1;
#5 tb_set_n=0;
#2.5 tb_reset_n=1;
#2.5 tb_d=0; tb_reset_n=1;
#2.5 tb_set_n=1;
#5 tb_set_n=0;
#2.5 tb_reset_n=0;
#2.5 tb_set_n=1;
#5 tb_set_n=0;
#2.5 tb_reset_n=1;

#10 $stop;
end 
endmodule 												 