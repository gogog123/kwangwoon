	AREA project, CODE, READONLY
		ENTRY

	LDR r12, =Matrix_data
	LDR r13, TEST_data1
	LDR r9, SAVE_data
	
	LDR r10, [r12], #4  ; r10 = N
	LDR r11, [r12], #4  ; r11 = k
	MOV r14, #0         ; count = 0
	
low1
	LDR r12, =Matrix_data
	ADD r12, r12, #8
	LDR r9, SAVE_data2
	LDR r6, [r9]
	ADD r6, r6, #1
	STR r6, [r9]
	B low_load
	
low2
	LDR r12, TEST_data2
	LDR r9, SAVE_data2
	LDR r6, [r9]
	ADD r6, r6, #1
	STR r6, [r9]
	B low_load
	
low3
	LDR r12, TEST_data4
	LDR r9, SAVE_data2
	LDR r6, [r9]
	ADD r6, r6, #1
	STR r6, [r9]
	B low_load

low_load
	LDR r9, SAVE_data4   ;0x00090018
	LDR r8, [r9]
	MOV r5, r10, LSL r8
	ADD r14, r14, #1
	CMP r14, r5
	BEQ padding
	
	CMP r8, #1
	MOV r0,r10,LSL#2
	MOVEQ r0,r0,LSL#1
	MOVGT r0,r0,LSL#2
	
	LDR r9, SAVE_data2      ;0x90008, 
	LDR r6, [r9]
	SUB r6, r6, #1
	CMP r14, #1
	ADDEQ r12, r12, r6, LSL #2

	LDR r1, [r12], r0
	LDR r2, [r12]
	
	B cal
	
column1
	LDR r12, TEST_data1
	ADD r4, r8, #1
	CMP r4, r11
	LDR r9, SAVE_data5
	LDR r5, [r9]
	ADDEQ r5, r5, r10, LSL r4
	STR r5, [r9]
	
	LDR r9, SAVE_data3
	LDR r3, [r9]
	ADD r3, r3, #1
	STR r3, [r9]
	
	B column_load
	
column2
	LDR r12, TEST_data3
	ADD r4, r8, #1
	CMP r4, r11
	LDR r9, SAVE_data5
	LDR r5, [r9]
	ADDEQ r5, r5, r10, LSL r4
	STR r5, [r9]
	LDR r9, SAVE_data3
	LDR r3, [r9]
	ADD r3, r3, #1
	STR r3, [r9]
	B column_load
	
column3
	LDR r12, TEST_data5
	ADD r4, r8, #1
	CMP r4, r11
	LDR r9, SAVE_data5
	LDR r5, [r9]
	ADDEQ r5, r5, r10, LSL r4
	STR r5, [r9]
	LDR r9, SAVE_data3
	LDR r3, [r9]
	ADD r3, r3, #1
	STR r3, [r9]
	B column_load
	
column_load
	LDR r9, SAVE_data4   ;0x00090018
	LDR r8, [r9]
	MOV r5, r10, LSL r8
	ADD r14, r14, #1
	CMP r14, r5
	BEQ padding
	
	CMP r8,#1
	MOV r0,r10,LSL#3
	MOVEQ r0,r0,LSL#1
	MOVGT r0,r0,LSL#2
	
	LDR r9, SAVE_data3      ;0x90008, 
	LDR r3, [r9]
	SUB r3, r3, #1
	CMP r14, #1
	ADDEQ r12, r12, r3, LSL #2

	
	LDR r1, [r12], r0
	LDR r2, [r12]
	
	B cal
	
floating_save
	STR r1, [r13], #4
	STR r7, [r13], #4
	STR r2, [r13]
	
	LDR r9, SAVE_data  ;SAVE_data = 0x90000
	LDR r3, [r9]
	LDR r9, SAVE_data4   ;0x00090018
	LDR r8, [r9]
	MOV r4, r10, LSL r8
	CMP r3, r4
	BLT low_load
	
	B column_load
	
padding
	STR r2, [r13], #4
	STR r2, [r13], #4
	;;;;;;padding
	
	LDR r9, SAVE_data  ;SAVE_data = 0x90000
	LDR r3, [r9]
	ADD r3, r3, #1
	STR r3, [r9]
	
	LDR r9, SAVE_data4   ;0x00090018
	LDR r8, [r9]
	CMP r8, #1

	BLT Twice
	BEQ Quadruple
	BGT Eightfold
	
Twice
	CMP r3, r10
	ADDLT r12, r12, #4
	MOV r14, #0
	BLT low1
	LDREQ r13, TEST_data2
	
	LDR r9, SAVE_data3
	LDR r4, [r9]
	MOV r3, r10, LSL #1
	CMP r4, r3
	BLT column1
	
	LDR r13, TEST_data2
	B data_read
	
Quadruple
	MOV r4, r10, LSL r8
	CMP r3, r4
	ADDLT r12, r12, #4
	MOV r14, #0
	BLT low2
	LDREQ r13, TEST_data4
	
	LDR r9, SAVE_data3
	LDR r4, [r9]
	MOV r3, r10, LSL #2
	CMP r4, r3
	BLT column2
	
	LDR r13, TEST_data4
	B data_read
	
Eightfold
	MOV r4, r10, LSL r8
	CMP r3, r4
	ADDLT r12, r12, #4
	MOV r14, #0
	BLT low3
	LDREQ r13, Result_data
	
	LDR r9, SAVE_data3
	LDR r4, [r9]
	MOV r3, r10, LSL #3
	CMP r4, r3
	BLT column3
	
	LDR r13, Result_data
	B data_read
	
data_read
	LDR r9, SAVE_data4
	LDR r8, [r9]
	ADD r8, r8, #1
	STR r8, [r9]

	CMP r8, r11
	BEQ endline
	
	MOV r3, #0
	LDR r9, SAVE_data    ;0x90000
	STR r3, [r9]
	LDR r9, SAVE_data2   ;0x90008
	STR r3, [r9]
	LDR r9, SAVE_data3   ;0x90010
	STR r3, [r9]

	CMP r8, #1
	LDREQ r13, TEST_data3
	BEQ low2
	
	LDRNE r13, TEST_data5
	BNE low3

endline 
	CMP r8, #3
	BEQ end_pc
	LDR r9, Result_data
	LDR r10, SAVE_data5
	LDR r5, [r10]
	
store
	LDR r0, [r13], #4
	STR r0, [r9], #4
	SUB r5, r5, #1
	CMP r5, #0
	BNE store
	
	B end_pc

end_pc
	MOV pc, #0
	
;;calculate;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
cal
   CMP r1, r2
   BEQ floatingpoint_end_same
   MOV r3,r1,LSR #31 ; S1 = r3
   MOV r4,r2,LSR #31 ; S2 = r4  
   MOV r5,r1,LSL #9  
   MOV r5,r5,LSR #9  ; mantissa1 = r5
   MOV r6,r2,LSL #9  
   MOV r6,r6,LSR #9  ; mantissa2 = r6
   MOV r7,r1,LSL #1
   MOV r7,r7,LSR #24 ; Exponent1 = r7 
   MOV r8,r2,LSL #1
   MOV r8,r8,LSR #24 ; Exponent2 = r8  
   ADD r5,r5,#0x00800000 ;ADD 1 to mantisa
   ADD r6,r6,#0x00800000 
   CMP r7,r8 ;compare exponent
   SUBGT r9,r7,r8
   SUBLT r9,r8,r7 ;shift num   
   MOVGT r6,r6,LSR r9 ;if shift num is not 0
   MOVLT r5,r5,LSR r9   
   MOVLE r7,r8
   CMP r3,r4
   BEQ SAME
   
NSAME
   MOV r8, r1, LSL #1
   MOV r9, r2, LSL #1
   MOV r8, r8, LSR #1
   MOV r9, r9, LSR #1
   CMP r8, r9
   MOVEQ r7,#0 ;when the result is zero
   BEQ floating_save
   SUBGT r5,r5,r6 
   SUBLT r5,r6,r5   
   ;MOVGT r3,r3
   MOVLT r3,r4;Declare sign
   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
loop4 ;for normalize
   CMP r5,#0x00800000
   MOVLT r5,r5,lsl #1
   SUBLT r7,r7,#1
   BLT loop4
   B floatingpoint_end
   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

SAME  
   ADD r5,r5,r6 ;adding mantissa
   CMP r5,#0x01000000
   MOVGE r5,r5,LSR #1
   ADDGE r7,r7,#1   

floatingpoint_end
   SUB r5,r5,#0x00800000
   SUB r7,r7,#1            ;x0.5
   ADD r7,r5,r7,lsl #23    ;mantissa + exponent
   ADD r7,r7,r3,lsl #31    ;S + mantissa + exponent
   
   B floating_save
   
floatingpoint_end_same
   MOV r7, r1
   
   B floating_save
   
;;;;calculate end;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


Result_data & 0x60000000   ;result
SAVE_data  & 0x90000
SAVE_data2 & 0x90008
SAVE_data3 & 0x90010
SAVE_data4 & 0x90018
SAVE_data5 & 0x90020

TEST_data1 & 0x30000       ; 
TEST_data2 & 0x40000       ;x2
TEST_data3 & 0x50000       ;
TEST_data4 & 0x60000       ;x4
TEST_data5 & 0x70000       ;

Matrix_data
   DCD 3
   DCD 1
   DCD 2_01000010110111000000000000000000
   DCD 2_01000011011110000000000000000000
   DCD 2_11000001100000000000000000000000
   DCD 2_11000010101010000000000000000000
   DCD 2_11000001010110000000000000000000
   DCD 2_01000000011111000000000000000000
   DCD 2_10111110101101000000000000000000
   DCD 2_01000010011100000000000000000000
   DCD 2_11000100010000000000000000000000

;   DCD 3
;   DCD 2
;   DCD 2_01000010011010000000000000000000
;   DCD 2_10111111111101000000000000000000
;   DCD 2_11000000110000000000000000000000
;   DCD 2_11000010111000000000000000000000
;   DCD 2_01000011000000000000000000000000
;   DCD 2_01000010001011000000000000000000
;   DCD 2_01000011110001000000000000000000
;   DCD 2_01000011011100000000000000000000
;   DCD 2_01000001101000000000000000000000
   
;   DCD 2
;   DCD 3
;   DCD 2_01000000000000100000000000000000
;   DCD 2_11000000111000000000000000000000
;   DCD 2_01000011100000100000000000000000
;   DCD 2_01000001100010000000000000000000

   END	