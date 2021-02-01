#include<stdio.h> //해더파일 선언
int main() //main함수의 시작
{
	int i; //i 변수 선언
	int arr[9] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 }; //길이가 9인 arr의 배열
	printf("Original number: "); 
	for (i = 0; i < 9; i++) //0번째부터 8번째까지 반복
	{
		printf("%d ", arr[i]); //arr배열 출력

	}
	printf("\nNew numvers: "); 
	for (i = 0; i < 9; i++) //0번째부터 8번째까지 반복
	{
		printf("%d ", arr[i]+i);//배열요소만큼 더함
	}
	printf("\n"); // 줄띄우기
	return 0; //0의 반환
}//main함수의 끝
