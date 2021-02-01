#include<stdio.h> //해더파일 선언
int main(void) //main함수의 시작
{
	int num = 2; //num=2변수 선언
	while (num!=16) //while문 16일때 정지
	{
		// num규칙
		printf(" %d", num*(-1)+1); //num값 출력

		num = num*(-1) + 3; //num규칙
		printf(" %d",num); //num값 출력
	}
	printf("\n"); //줄 띄우기

	return 0; //0의 반환
	
} //main함수의 끝