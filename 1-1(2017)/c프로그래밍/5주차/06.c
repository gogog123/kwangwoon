#include<stdio.h> //해더파일 선언
int main(void) //main함수의 시작
{
	int num, a, b; //변수 선언
	printf("Input : "); //input 출력
	scanf("%d", &num); //num값 입력

	for (a = 0; a < num; a++) //총 num줄만들기
	{
		for (b = num - a; b > 0; b--) //*반복해서 출력
			printf("*"); //*출력
		printf("\n"); //줄 띄우기
	}
	return 0; //0의 반환
} //main 함수의 끝