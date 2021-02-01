#include <stdio.h> //해더파일 선언
int main() //main함수의 시작
{
	int num[10] = { 0 }; //num배열 선언
	int i; //i변수 선언
	int *pMax = NULL; 
	int *pMin = NULL; 

	printf("Input: "); //Input출력
	for (i = 0; i < 10; i++) //0~9까지 배열num에 값 저장
	{
		scanf("%d", &num[i]); 
	}
	pMax = &num[0]; //초기 Max값 지정
	pMin = &num[0]; //초기 MIn값 지정
	
	for (i = 0; i < 10; i++) //0~9까지 반복
	{
		if (*pMax < num[i]) //배열 중 가장 큰 값 탐색
			pMax = &num[i]; //pMax 지정
		if (*pMin > num[i]) //배열 중 가장 작은 값 탐색
			pMin = &num[i]; //pMin 지정
	}

	printf("Max: %d\n", *pMax); //가장 큰 값 출력
	printf("Min: %d\n", *pMin); //가장 작은 값 출력
	return 0; //0의 반환
} //main함수의 끝