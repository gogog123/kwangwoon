#include<stdio.h> //해더파일 선언
int main(void) //main함수의 시작
{
	int num; //num변수 선언

	do //do~while문 사용
	{
		printf("input : "); //숫자 출력
		scanf("%d", &num); //숫자 입력

	} while (num != -1); //-1일때 종료
	return 0; //0의 반환
} //main함수의 끝