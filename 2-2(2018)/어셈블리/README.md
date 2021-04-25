## 1week (data_transfer_to_or_from_Mem)
기본 명령어 사용 예제를 통해 어셈블리어 프로그래밍을 이해하고 ARM 조건부 실행 코드 보는 방법을 이해하고 어셈블리어 프로그래밍 능력을 습득  
또한 원하는 데이터를 메모리로 저장 및 가져올 수 있도록 어셈블리어 프로그래밍 능력을 습득
  
  
## 2week (control_flow_&_data_processing) 
Memory로부터 값을 받아 이를 이용해 원하는 연산을 수행  
Assembly code를 작성할 때 performance를 생각하며 작성  
branch 명령어와 conditional execution의 차이를 알아보고 memory를 할당하여 data를 저장  
  
   
## 3week (Second Operand & Multiplication)  
Multiplication operation을 사용하는 것과 Second operand를 사용한 코드의 성능 차이를 비교  
Operand의 순서에 따른 성능의 차이  
  

## 4week  (Block Data Transfer & Stack)
레지스터와 메모리간 블록 단위의 데이터 저장/가져오기를 이해  
어셈블리어의 서브 루틴(함수) 사용 방법 이해  
프로그래밍 수준에서 스택 명령어의 필요성과 효용성에 대해 이해 및 응용  
여러 종류의 스택 저장 방식(stack type)에 대해 이해하고 각 방식에 따른 메모리 접근 방법을 실질적으로 확인해봄으로써 그 차이를 이해  
  

## 5week (Floating-Point)
Arm에는 floating point를 해주는 instruction이 존재하지 않음 때문에 floating point가 입력되었을 때 해당 연산을 수행시켜주는 assembly code가 필요  
 Floating point의 adder를 구현하여 floating point의 덧셈과 뺄셈에 대한 이해  
 Normalize 과정에서 어떤 경우에는 right로, 어떤 경우에는 left로 shift되는지를 고려하며 코드를 작성  

## 6week (Pseudo Instructions)
Pseudo instruction이 assembler에 의해 어떻게 실제 instruction으로 변환되는지 직접 확인하고 이해  
Disassembly를 해석하는 방법을 이해  
 Label의 이름이 실제 메모리 주소임을 이해하고 이를 이용해 어셈블리어 프로그래밍을 진행하는 능력을 습득  
   
    
## project  
임의의 부동소수점 데이터로 이루어진 20x20 정방행렬에 대해 Bilinear Interpolation 을 수행하여 행과 열을 각 4배로 확장한 80x80 정방행렬을 계산 및 어셈블리 코드 작성  
  