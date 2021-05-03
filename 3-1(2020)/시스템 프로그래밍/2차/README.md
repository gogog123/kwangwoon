## 2-1
* getopt()를 사용하여 매개 변수(-a, -b, -c[str])을 입력 받음  
* Argument를 분석하는 함수 getopt를 사용하여 a를 입력 받으면 aflag, b를 입력 받으면 bflag c를 입력 받으면 c value의 값을 변경  
  
  
## 2-2
* ls 명령어를 구현  
* 디렉토리를 여는 opendir함수, 디렉토리를 읽는 readdir함수, 디렉토리를 종료하는 cloasedir 함수를 이용하여 ls file system을 구현  
  

## 2-3
* 파일 관련 명령어 함수를 구현
*  파일 관련 명령어들은 현재 working directory를 출력하는 pwd, 현재 working directory를 변경하는 cd, 디렉토리를 생성하는 mkdir, 디렉토리를 삭제하는 rmdir, 파일 및 디렉토리 이름을 변경하는 rename 등이 있다.   