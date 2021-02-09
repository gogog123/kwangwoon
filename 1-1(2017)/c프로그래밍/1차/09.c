#include<stdio.h> //해더파일 선언
int main(void) //main 함수의 시작
{
	int num, a; //변수 선언
	printf("Input : "); //Input 출력
	scanf("%d", &num); //값 입력 
	printf("%d의 약수 : ", num); //num의 약수

	for (a = num; a > 0; a--) //for문 a가 1일때까지 반복
	{
		if (num%a == 0) //num을 a로 나눴을때 나머지가 0
		printf("%d ", num/a); //num의 약수 출력
	
	}//for문의 끝
	printf("\n"); //줄 띄우기

	return 0; //0의 반환
} //main함수의 끝