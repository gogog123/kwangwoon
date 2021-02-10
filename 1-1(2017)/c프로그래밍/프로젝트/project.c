//미사일을 발사하여 목표물을 맞추는 게임이다.

#include <stdio.h> 
#include <conio.h> //gotoxy 함수
#include <Windows.h>
#include <stdlib.h>
#include <time.h>  //해더파일 선언

void gotoxy(int x, int y) //
{
	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_rectangle(int row, int col)
{
	gotoxy(1, 1);
	printf("┌"); // '┌' 출력
	for (int i = 2; i < row; i++)
		printf("──");
	printf("─");
	printf("┐\n");
	for (int i = 2; i < col; i++)
	{
		printf("│");
		gotoxy(39, i);
		printf("│\n");
	}
	printf("└");
	for (int i = 2; i < row; i++)
		printf("──");
	printf("─");
	printf("┘");

	//게임 틀 출력
}

void game_control(int* hit, int k, int rnd1, int rnd2, int rnd3)
{
	gotoxy(42, 2);
	printf("스페이스키를 누르면");
	gotoxy(42, 3);
	printf("미사일이 발사됩니다.");
	gotoxy(42, 5);
	printf("횟수 : %d", k);
	gotoxy(42, 6);
	printf("성공 : %d", *hit);

	gotoxy(rnd1,2);
	printf("□");
	gotoxy(rnd2, 2);
	printf("■");
	gotoxy(rnd3, 2);
	printf("▣");

	int i = 0;
	int j = 0;
	while (1) {
		if (i % 68 + 3 < 37)
		{
			gotoxy(i % 68 + 3, 19);
			printf("  ");
			i += 2;
			printf("▲");
			gotoxy(1, 22);
			Sleep(100 - *hit * 5);
			if (kbhit()) //키 입력 여부 확인
				if (getch() == 32) //스페이스바 눌렀을 때
					break; //멈춤
		}
		if (i % 68 + 3 >= 37)
		{
			gotoxy(72 - (i % 68 + 3), 19);
			printf("▲");
			i += 2;
			printf("  ");
			gotoxy(1, 22);
			Sleep(100 - *hit * 5); 
			if (kbhit())
				if (getch() == 32)
					break;
		}
	}// 비행기 움직임 제어

	if (i % 68 + 3 < 37)
		i = i % 68 + 3;
	else
		i = 72 - ((i-2) % 68 + 3);


	for (int a = 18; a > 2; a--) {
		gotoxy(i, a);
		printf("↑");
		Sleep(100);
		gotoxy(i, a);
		printf("  ");
	}
	
	if (rnd1 == i) // □ 맞았을 때
	{
		if (*hit == -1) {
			gotoxy(49, 6);
			printf("  ");
		}
		*hit += 1; //성공횟수 1 증가
		gotoxy(i, 2);
		printf("☆"); //☆ 출력
		gotoxy(42, 8);
		printf("맞았습니다."); // 성공했을 때 출력
		j += 1;
		if (j == 2) {
			*hit += 1;
			j = 1;
		}
		gotoxy(49, 6);
		printf("%d", *hit); //성공횟수 출력
	}

	else if (rnd2 == i) // ■ 맞았을 때
	{
		if (*hit == -1 || *hit == -2) {
			gotoxy(49, 6);
			printf("  ");
		}
		
		*hit += 2; //성공횟수 2증가
		gotoxy(i, 2);
		printf("☆");
		gotoxy(42, 8);
		printf("맞았습니다."); //성공했을때 출력
		j += 1;
		if (j == 2) {
			*hit += 1; //추가 점수
			j = 1;
		}
		gotoxy(49, 6);
		printf("%d", *hit); //점수출력
		
	}
	else if (rnd3 == i) { //▣ 맞았을 때
		*hit -= 1; //성공횟수 1 감소
		gotoxy(i, 2);
		printf("☆");
		gotoxy(42, 8);
		printf("맞았습니다."); //성공했을때 출력
		gotoxy(49, 6);
		printf("%d", *hit); //성공횟수 출력
	}
	else {
		gotoxy(42, 8);
		printf("맞지않았습니다."); //성공못했을때 출력
	}
	
}

int main(void)
{
	int i = 0, num1, num2, num3;
	printf("미사일 게임\n\n비행기를 이동하면서\n목표물<□>을 맞추는 게임입니다.\n미사일은 스페이스키로 발사합니다.\n \n아무키나 누르면 시작합니다.\n");
	printf("미사일은 스페이스키를 발사합니다.\n< □:1점 ■:2점 ▣:-1점 >\n\n아무키나 누르면 시작합니다.\n"); //초기화면 출력

	for (int k = 0; k < 10; k++)
	{
		if (getch())//아무키나 눌렀을때
			system("cls"); //화면 reset
		srand((unsigned)time(NULL)); //매번 다르게 출력
		num1 = (rand() % 18) * 2 + 3;
		num2 = (rand() % 18) * 2 + 3;
		//3~37 무작위 출력
		while (1) {
			if (num1 == num2) // □, ■ 겹친다면
				num2 = (rand() % 18) * 2 + 3; //■ 위치 재설정
			else
				break;
		}
		num3 = (rand() % 18) * 2 + 3;
		while (1) {
			if (num3 == num1 || num3 == num2) // □, ■, ▣ 겹친다면
				num3 = (rand() % 18) * 2 + 3; //▣ 위치 재설정
			else
				break;
		}
		draw_rectangle(20, 20); //20x20 사각형 출력
		game_control(&i, k, num1, num2, num3); // *hit = i(성공 횟수)
	}

	gotoxy(42, 5);
	printf("횟수 : %d", 10);
	gotoxy(42, 8);
	printf("최종 점수: %d", i);
	gotoxy(1, 22);
	return 0; // 0의 반환
}//main함수 종료