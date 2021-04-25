	AREA problem1, CODE, READONLY
		ENTRY
		
start
	LDR r0, =Values
	LDR r1, TEMPADDR1
	
	LDR r2, [r0], #4
	MOV r4, r2, LSR #31   ;S1 = r4
	MOV r5, r2, LSL #1     
	MOV r5, r5, LSR #24   ;exponent1 = r5
	MOV r6, r2, LSL #9
	MOV r6, r6, LSR #2    ;mantissa1 = r6
	
	LDR r3, [r0], #4
	MOV r7, r3, LSR #31   ;S2 =r7
	MOV r8, r3, LSL #1     
	MOV r8, r8, LSR #24   ;exponent2 = r8
	MOV r9, r3, LSL #9
	MOV r9, r9, LSR #2    ;mantissa2 = r9

	ADD r6, r6, #0x40000000 ;mantissa1 +1.
	ADD r9, r9, #0x40000000 ;mantissa2 +1.
	
	CMP r5, r8              ;exponent compare
	SUBGE r10, r5, r8       ;r10=|exponent1-exponent2|
	MOVGE r9, r9, LSR r10   ;mantissa2 shift r10
	MOVGE r10, r5           ;r10=large value exponent store
	SUBLT r10, r8, r5       ;r10=|exponent1-exponent2|
	MOVLT r6, r6, LSR r10   ;mantissa1 shift r10
	MOVLT r10, r8           ;r10=large value exponent store

;	STR r2, [r1], #4
;	STR r3, [r1], #4
	
	CMP r4, r7              ;sign vlaue compare
	BEQ same                ;s1=s2
	BNE nsame               ;s1!=s2
	
same
	CMP r4, #0              ;compare r4, 0
	MOVEQ r4, #0            ;result s = 0
	MOVNE r4, #0x80000000   ;result s = 1

	ADD r6, r6, r9          
	MOV r9, r6              ;mantissa1+ mantissa2
	
	MOV r9, r9, LSR #31     ;result mantissa of s
	CMP r9, #1              ;s=1
	ADDEQ r5, r10, #1       ;exponent + 1
	MOVEQ r6, r6, LSL #1    ;mantissa shift left
	MOVEQ r6, r6, LSR #9    
	ADDNE r5, r10, #0       ;s=0
	MOVNE r6, r6, LSL #2    ;mantissa shift 2left
	MOVNE r6, r6, LSR #9
	
	MOV r5, r5, LSL #23     ;result exponent
	
	ADD r13, r4, r5         
	ADD r13, r13, r6        ;result = s+exponent+mantissa
	B endline

nsame
	MOV r11, r2, LSL #1    ;signbit X
	MOV r12, r3, LSL #1    ;sign X
	CMP r11, r12           
	MOVHI r4, r4, LSL #31  
	MOVCC r4, r7, LSL #31
	BEQ zero 
	
	CMP r6, r9
	SUBGT r6, r6, r9
	SUBLT r6, r9, r6

	MOV r9, r6
	
	MOV r9, r9, LSR #29
	CMP r9, #2
	ADDGE r5, r10, #0
	MOVGE r6, r6, LSL #2
	MOVGE r6, r6, LSR #9
	CMP r9, #1
	SUBEQ r5, r10, #1
	MOVEQ r6, r6, LSL #3
	MOVEQ r6, r6, LSR #9
	CMP r9, #0
	SUBEQ r5, r10, #2
	MOVEQ r6, r6, LSL #4
	MOVEQ r6, r6, LSR #9
	
	MOV r5, r5, LSL #23
	
	ADD r13, r4, r5
	ADD r13, r13, r6
	
	B endline
	
zero
	MOV r13, #0
	B endline
	
endline
	STR r13, [r1]
	MOV pc, lr
	
Values DCD 2_01000010110111000000000000000000, 2_01000011011110000000000000000000
TEMPADDR1 DCD &40000000
	END