## 3-1
* 소켓을 사용하여 ls명령어를 구현 
* Client는 server address 127.0.0.1과 port number를 사용자로부터 입력을 받아온다. 또한 어떤 명령어(ls, quit)를 실행할 것인지 입력을 받아와서 ls이면 디렉토리나 파일을 나열하여 출력하고, quit를 받아오면 프로그램을 server와 client의 연결을 끊고 종료한다.
* Server는 port number를 사용자로부터 입력을 받아온다. 여기서 port number은 client와 server와 같은 값을 가져야만 server와 client를 연결할 수 있다. 그리고 client의 IP와 PORT를 ntohs()와 inet_ntoa()를 이용하여 출력한다.
  
  
  
## 3-2
소켓 client와 server를 연결하고 새로운 process, fork() 함수를 이용하여 child process와 parent process를 생성하고, process ID를 출력한다. 또한 quit를 입력 받았을 때는 signal함수를 통해 child, parent process를 종료하고 그로 인해 client도 종료한다.