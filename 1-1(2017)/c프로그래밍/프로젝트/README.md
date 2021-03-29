## 미사일을 발사하여 목표물을 맞추는 게임

목표물을 □, 비행기를 ▲로 하여 비행기로 미사일을 발사하여 목표물을 맞추는 게임
목표물은 매 시행마다 가장 윗줄 랜덤한 위치에 고정
* 말은 사용자가 조종하지 않고 오른쪽으로 이동하다 끝에 도달하면 왼쪽으로 이동, 이 과정을 반복
* Space Bar를 눌러 미사일을 발사
* 미사일을 발사하면 목표물을 향해 날아가는 길을 표시하고목표물의 명중 여부를 표시  
* 이 후 아무키나 누르면 이어서 다시 진행  
* 미사일을 총 10번 발사하면 최종 결과를 출력  

***  
#### 사용되는 함수
void gotoxy(int x, int y)
* Header: conio.h
* 설명: 커서의 위치를 이동하는 함수
* int x: 화면에서의 가로 위치를 지정
* int y: 화면에서의 세로 위치를 지정

int kbhit(void)
* Header: conio.h
* 설명: 키 입력여부를 반환하는 함수 (있으면 1, 없으면 0)

void sleep(unsigned seconds)
* Header: Windows.h
* 설명: 입력한 시간만큼 시스템을 일시정지
* unsigned seconds: millisecond 단위 ( ex) 1000 -> 1초 )

int system(const char *string)
* Header: Windows.h
* 설명: 프로세스 호출 함수
* 사용 예시  
system(“cls”) => 콘솔에 출력된 내용을 모두 지움
