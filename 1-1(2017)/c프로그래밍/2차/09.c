#include<stdio.h> //해더파일 선언
int main() //main 함수의 시작
{
	int a, arr[10]; // 변수 선언, 배열 선언
	printf("숫자를 10개 입력하시오.\n"); //숫자 10개 출력
	for (a = 0; a < 10; a++) //a는 0부터 9까지 반복 
	{
		printf("%d: ", a + 1); //10개 숫자 입력
		scanf("%d", &arr[a]); //배열 입력
	}

	printf("짝수: "); 
	for (a = 0; a < 10; a++) //숫자 10개 반복
	{
		if (arr[a] % 2 == 0) //arr[]%2=0 : 짝수
			printf("%d ", arr[a]); //짝수 출력
	}
	printf("\n"); //줄띄우기
	printf("홀수: "); 
	for (a = 0; a <= 9; a++) //숫자 10개 반복
	{
		if (arr[a] % 2 == 1) //arr[]%2=1 : 홀수
			printf("%d ", arr[a]); //홀수 출력
	}
	printf("\n");//줄띄우기
	return 0; //0의 반환
} //main 함수의 끝