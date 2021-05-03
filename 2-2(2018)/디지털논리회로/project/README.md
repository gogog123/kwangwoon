## project  
임의의 부동소수점 데이터로 이루어진 20x20 정방행렬에 대해 Bilinear Interpolation 을 수행하여 행과 열을 각 4배로 확장한 80x80 정방행렬을 계산 및 어셈블리 코드 작성  
  
* Bilinear Interpolation(보간:알려진 지점의 값 사이에 위치한 값을 알려진 값으로 부터 추정하는 것) 계산  
* Interpolation 이 불가능한 외곽에 추가된 값들은 현재 위치와
가장 가까운 값으로 값 복사  
  
  
### <20x20 행렬의 4배>  
![image](https://user-images.githubusercontent.com/66414115/116873147-21d78400-ac52-11eb-9b8b-c6e2704834ab.png)  

  
### <알고리즘>
![image](https://user-images.githubusercontent.com/66414115/116873404-990d1800-ac52-11eb-9360-0c5e9fb19e4f.png)
  
  
  
<결론>  
State를 줄이는 방법  
성능의 기준은 code size와 state2를 곱한 값이다. State가 제곱이기 때문에 state가 줄어들수록 성능이 좋아진다고 볼 수 있다. 일단 생각하는 대로 코드를 구현하여 알맞은 결과값을 출력해내면 그 때 코드를 분석하여 같은 연산을 하는 부분은 함수로 만들어 주어 code size와 state를 줄일 수 있다. 구현한 코드에서는 4배, 8배를 구현하는 부분이 따로 없고 2배를 구현하는 함수만 있다. 따라서 2배한 code에서는 padding하여 N-1과 N이 같은 값이 나오게 된다. 이 두 수의 bilinear interpolation은 따로 계산할 필요없이 N-1과 N이 같은 값이므로 중점은 r7=r1=r2이라는 것을 알 수 있다. 그래서 cal연산을하지 않고 바로 값을 출력, 저장할 수 있다.   
