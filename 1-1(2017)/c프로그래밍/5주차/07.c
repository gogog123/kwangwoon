#include<stdio.h> //해더파일 선언
int main(void) //main함수의 선언
{
	int num, a, b; //변수 선언
	printf("Input : "); //Input출력
	scanf("%d", &num); //값 입력

	for (a = 0; a < num; a++) //for문 시작
	{
		for (b = num - a; b > 0; b--) //빈칸 하나씩 줄어들기
			printf(" "); //빈칸 출력
		for (b = 0; b < a*2+1; b++) //*두개씩 증가
			printf("*"); //*출력
		
		printf("\n"); //줄 띄우기
	
	}//for문 끝
	return 0; //0의 반환
} //main함수의 끝