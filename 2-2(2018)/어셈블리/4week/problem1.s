	AREA blockData, CODE, READONLY
		ENTRY
		
start
	MOV r0, #1
	MOV r1, #2
	MOV r2, #3
	MOV r3, #4
	MOV r4, #5
	MOV r5, #6
	MOV r6, #7
	MOV r7, #8
	
	LDR r8, TEMPADDR1
	STMIA r8!, {r2}
	STMIA r8!, {r0}
	STMIA r8!, {r3}
	STMIA r8!, {r5}
	STMIA r8!, {r6}
	STMIA r8!, {r7}
	STMIA r8!, {r1}
	STMIA r8!, {r4}
	
	LDMDB r8, {r0-r7}
	MOV pc, lr
	
TEMPADDR1 & &00040000
	END
	
	