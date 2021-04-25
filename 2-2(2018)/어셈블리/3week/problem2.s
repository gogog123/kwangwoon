	AREA ARMex, CODE, READONLY
		ENTRY
		
start
	ldr r0, tempaddr
	mov r1, #1
	mov r11, #1
	
	add r11, r11, #1      ;r11=r11+1=1+1=2
	mul r2, r1, r11       ;r2=r1*r11=1*2=2
	
	add r11, r11, #1      ;r11=r11+1=2+1=3
	mul r3, r2, r11       ;r3=r2*r11=2*3=6
	
	add r11, r11, #1      ;r11=r11+1=3+1=4
	mul r4, r3, r11       ;r4=r3*r11=6*4=24
	
	add r11, r11, #1      ;r11=r11+1=4+1=5
	mul r5, r4, r11       ;r5=r4*r11=24*5=120
	
	add r11, r11, #1      ;r11=r11+1=5+1=6
	mul r6, r5, r11       ;r6=r5*r11=120*6=720
	
	add r11, r11, #1      ;r11=r11+1=6+1=7
	mul r7, r6, r11       ;r7=r6*r11=720*7=5040
	
	add r11, r11, #1      ;r11=r11+1=7+1=8
	mul r8, r7, r11       ;r8=r7*r11=5040*8=40320
	
	add r11, r11, #1      ;r11=r11+1=8+1=9
	mul r9, r8, r11       ;r9=r8*r11=40320*9=362880
	
	add r11, r11, #1      ;r11=r11+1=9+1=10
	mul r10, r9, r11      ;r10=r9*r11=362880*10=3628800
	
	str r10, [r0]
	
	mov pc, lr

tempaddr & &40000

	end