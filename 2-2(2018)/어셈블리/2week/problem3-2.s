	AREA ARMex, CODE, READONLY
		ENTRY

start
	LDR r7, Address1
	MOV r0, #1
	LSL r1, r0, #1
	LSL r2, r1, #1
	LSL r2, r2, #1
	ADD r2, r2, r1 ;r2=10
	
	ADD r3, r2, r2
	MUL r4, r3, r2 ;n(n+10)
	
	STRB r4, [r7]
	
	MOV pc, lr

	
Address1 & &00004000
	END