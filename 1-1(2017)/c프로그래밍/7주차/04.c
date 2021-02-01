#include <stdio.h> //해더파일 선언
int main() //main함수의 시작
{
	int num[7] = { 0 }; //배열 num 선언
	int *pNum = num; 
	int i = 0; //변수 선언

	printf("일곱 개의 정수 입력: "); //일곱 개의 정수 출력
	for (i = 0; i < 7; i++) //0~7까지 배열num에 값 저장
	{
		scanf("%d", &num[i]); //정수 값 입력
	}
	printf("결과(x3): "); // 결과(x3)출려
	for (i = 0; i < 7; i++) 
	{
		*pNum = num[i] * 3; //배열 X3
		printf("%d ", *pNum); //배열 X3 출력
	}
	printf("\n"); //줄 띄우기
	return 0; //0의 반환
} //main 함수의 시작