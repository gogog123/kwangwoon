#include<stdio.h> // 해더파일 선언
int main(void) //main함수의 시작
{
	int a = 0;
	int b = 0;
	int c = 1;
	int d, num; //변수 선언
	printf("Input : "); //Input값 출력
	scanf("%d", &num); // 값 입력
	for (d = 1; d <= num; d++)
	{
		printf("%d ", c); //결과값 c 출력
		a = b; 
		b = c; 
		c = a + b; //피보나치 수열
	}
	printf("\n"); //줄 띄우기

	return 0; //0의 반환 
} //main함수의 끝