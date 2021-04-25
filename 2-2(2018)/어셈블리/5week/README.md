## 5week (Floating-Point)
Arm에는 floating point를 해주는 instruction이 존재하지 않음 때문에 floating point가 입력되었을 때 해당 연산을 수행시켜주는 assembly code가 필요  
 Floating point의 adder를 구현하여 floating point의 덧셈과 뺄셈에 대한 이해  
 Normalize 과정에서 어떤 경우에는 right로, 어떤 경우에는 left로 shift되는지를 고려하며 코드를 작성  
  

### Problem1  
* Floating point값 2개를 메모리로 부터 load하여 덧셈 연산을 수행  
*  결과값은 메모리 주소에 저장  
  
  
  