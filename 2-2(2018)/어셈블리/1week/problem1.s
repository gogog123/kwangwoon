	AREA ARMex, CODE, READONLY
		ENTRY
start
	MOV r0, #10
	MOV r1, #13
	MOV r2, #05
	MOV r3, #0x0A
	
	LDR r4, TEMPADDR1
	
	STRB r0,[r4]
	STRB r1,[r4,#1]
	STRB r2,[r4,#2]
	
	LDRB r6,[r4]
	LDRB r7,[r4,#1]
	LDRB r8,[r4,#2]
	
	CMP r6,r3
	MOVGT r5,#1 
	MOVMI r5,#2 
	MOVEQ r5,#3 
	
	CMP r7,r3
	MOVGT r5,#1 
	MOVMI r5,#2 
	MOVEQ r5,#3

	CMP r8,r3 
	MOVGT r5,#1 
	MOVMI r5,#2 
	MOVEQ r5,#3 
	
TEMPADDR1 & &00001000
	MOV pc, lr
	END