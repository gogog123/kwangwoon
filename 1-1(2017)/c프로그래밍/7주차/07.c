#include <stdio.h> //해더파일 선언
void reverse(int *num) //reverse함수의 시작
{
	int temp; //변수 temp선언
	for (int i = 0; i < 5; i++) //0~4까지 반복
	{
		temp = num[i]; 
		num[i] = num[9 - i]; //배열 0~4까지 순서 바꿈
		num[9 - i] = temp; //배열 5~9까지 순서 바꿈
	}
}//reverse함수의 끝

int main() //main 함수의 시작
{
	int arr[10]; // 배열 선언
 	int i = 0; //변수 i선언
	
	printf("10개의 정수 입력\n>> "); //10개의 정수 출력
	for (i = 0; i < 10; i++) 
		scanf("%d", &arr[i]); //10개의 정수 입력

	reverse(arr); //정수의 순서를 뒤바꿈

	printf(">> "); 
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]); //순서를 뒤바꾼 배열 출력
	printf("\n"); //줄띄우기
	return 0; //0의 반환
} //main함수의 끝
