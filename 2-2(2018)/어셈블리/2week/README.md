## 2week (control_flow_&_data_processing) 
Memory로부터 값을 받아 이를 이용해 원하는 연산을 수행  
Assembly code를 작성할 때 performance를 생각하며 작성  
branch 명령어와 conditional execution의 차이를 알아보고 memory를 할당하여 data를 저장  

### Problem1  
* Strcmp함수 작성  
* 만약 두 문자열이 같을 경우에는 0x0A를, 그렇지 않을 경우에는 0x0B를 4000번지에 저장  
   

### Problem2  
* 배열을 정렬하여 4000번지부터 저장  
* Array[10]={10, 9, 8, 7, 6, 5, 4, 3, 2, 1}  
  

### Problem3  
* 11+13+15+⋯27+29를 계산하여 결과값을 4000번지에 저장  
* Loop을 이용하는 방법, 일반화 식인 n(n+1)을 이용한 방법, unrolling을 이용한 방법으로 구현해 보고 성능 비교  
*  Branch와 conditional execution의 차이점과 성능 차이  

