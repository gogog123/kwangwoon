#include<stdio.h> //해더파일 선언
int main(void) //main함수의 시작
{
	int num, a, b; //변수 선언
	printf("Input : "); //Input 출력
	scanf("%d", &num); //값 입력

	for (a=1; a<=num; a++) // a가 1씩커짐 
	{
		for (b = 0; b < num; b++) //b가 1씩커짐
		{
			printf("%5d", num*a-b); // 5칸띄우고 값 출력
		}
		printf("\n"); //줄띄우기
	} //for문 끝
	return 0; //0의 반환

} //main 함수의 끝