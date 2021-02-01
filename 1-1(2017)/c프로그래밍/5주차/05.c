#include<stdio.h> //해더파일 선언
int main(void) //main함수의 시작
{
	int num, a, b; //변수 선언
	printf("Input : "); //input 출력
	scanf("%d", &num); //num값 입력

	for (b =0; b < num; b++) //총 num줄 만들기
	{
		for (a = 0; a <= b; a++) //*하나씩 추가 하기
			printf("*"); //* 출력
		printf("\n"); //줄띄워주기
	}
	return 0; //0의 반환
} //main함수의 끝