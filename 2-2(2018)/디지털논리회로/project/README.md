## project  
Multiplier, Adder, FIFO(first in first out), RF(register file)를 이용하여 Matrix를 설계하고, bus를 통해 Memory와 연결하여 검증한다.
  
* Multiplier, Adder, FIFO, RF를 이용하여 Matrix를 설계하여 연속적인 연산들을 진행
* testbench를 master로 하여 입력 값들을 저장하고 연산을 출력
* Matrix, Memory 그리고 Bus를 이용하여 Top module을 구현
  
  
  
### <소개>
전체 시스템의 구성 요소는 크게 4가지로 matrix, bus, memory, testbench이다. Testbench로부터 memory#0과 memory#1에 2행 2열의 행렬 값을 serial하게 저장하고 testbench에서 matrix에게 memory에 저장된 값을 보내준다. Testbnech가 master가 되고, matrix는 전송받은 값을 내부에 있는 A Matrix, B Matirx fifo에 저장한다. Fifo에 serial하게 저장되어 있는 data들을 pop하여 mutiplier에서 A의 data와 B의 data들을 곱셈 연산을 수행하게 된다. 곱셈연산이 끝나게 되면 adder fifo에서 곱셈연산을 한 결과 값들을 RF에 저장한다. Adder에서는 fifo에 저장되어있는 data들을 순서대로 덧셈 연산을 하여 결과를 출력한다. RF에 저장된 값을 MEMORY#2의 첫 번째 register로 serial하게 전송하고 완료되면, test bench가 다시 master할 수 있다. 
  
  
  
### <state>

![image](https://user-images.githubusercontent.com/66414115/116879435-9c58d180-ac5b-11eb-9859-157a9d4c417f.png)
![image](https://user-images.githubusercontent.com/66414115/116879542-b7c3dc80-ac5b-11eb-97c4-6d8b3e7ee596.png)
    
  
  
  
