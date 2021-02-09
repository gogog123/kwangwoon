#include <stdio.h> //해더파일 선언
#include <stdlib.h> 
#include <time.h> //랜덤함수 해더파일

int main(void) //main 함수의 시작
{
	int i, ranNum, num = 0; //변수 선언
	srand((unsigned)time(NULL)); //매번 다른 난수가 나오도록 함
	ranNum = rand() % 10 +1; 
	//1부터 10사이의 범위를 가지는 ranNum값 출력, rand()%10은 0~9의 범위를 가짐
	printf("Input <1~10>: "); //Input출력
	scanf("%d", &i); //i값 입력
	while (1)
	{
		if (i < ranNum)
			printf("random number는 %d보다 큽니다\n", i); //ranNum이 입력값보다 클때 출력
		else if (i > ranNum)
			printf("random number는 %d보다 작습니다\n", i); //ranNum이 입력값보다 작을때 출력
		else
		{
			printf("random number는 %d입니다\n", i); //ranNum이 입력값보다 작을때 출력
			return 0; //ranNum이 입력값과 똑같을 때 종료
		}
		printf("Input <1~10>: "); 
		scanf("%d", &i); //i=ranNum일때까지 반복
	}
	return 0; //0의 반환
} //main 함수의 종료