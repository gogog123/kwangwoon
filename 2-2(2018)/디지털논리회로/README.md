## 1(4-bits RCA)
* 두 수를 더하는 가산기 중 가장 기본에 되는 가산기인 4-bits RCA를 구현 및 검증  
  
  
  
## 2(carry look-ahead adder, 4-bits CLA, 32bit CLA)
* 가산기 중 올림 수를 미리 계산하는 가산기인 carry look-ahead adder에 대해서 구현 및 검증  
* 4-bits cla에 대한 구현 및 검증
* 32bits cla와 rca의 크기와 속도를 비교
  
  

## 3(4bit ALU, 32bit ALU)
* 산술 논리 연산 장치(Arithmetic Logic Unit)는 산술 연산과 논리 연산을 수행하는 회로로, 프로세서의 핵심 구성 요소라고 할 수 있다.   
* 4-bits ALU와 32-bits ALU 구현
  
  
  
## 4(flip-flop, N-bits register)
* 이전 값을 유지하는 저장 소자 역할을 하는 latch와 flip-flop을 설계하고, 더불어 reset과 set 기능을 구현  
* flip-flop을 사용하여 N-bits register를 구현



## 5(FSM, traffic light)
* FSM의 기법 중 하나인 Moore FSM을 적용하여 traffic light controller를 설계
  


## 6(shifter, counter)
* Flip-flop과 combinational logic을 이용하여 sequential logic인 shifter와 counter를 설계
  


## 7(FIFO queue (first in first out))
* First-in, first-out(FIFO) queue에 대해서 설계
  


## 8(multipler)
* multiplicand(피승수)와 multiplier(승수)를 곱하여 결론 값을 도출하는 multipler 설계
  


## 9(memory, BUS)
* Address에 기반하여 데이터를 저장하는 hardware인 memory를 구현
* 여러 component들 간에 data를 전송(transfer)할 수 있도록 연결해주는 component인 Bus를 구현  
  
  
  
## Project(Matirx)
* Multiplier, Adder, FIFO(first in first out), RF(register file)를 이용하여 Matrix를 설계하고, bus를 통해 Memory와 연결하여 검증