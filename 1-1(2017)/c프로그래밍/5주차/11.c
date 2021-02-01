#include <stdio.h> //해더파일 선언
int main(void) //main 함수의 시작
{
	char num; //num 변수 선언
	printf("알파벳 입력 : "); //'알파벳 입력' 출력 
	scanf("%c", &num); //num값 입력

	if ('A'<=num&&'Z'>=num) //A~Z일때 소문자로 변경
	{
		printf("대소문자 변경 : %c", num+32); //대문자+32 = 소문자 

	}
	else if ('a'<=num&&'z'>=num) //a~z일때 대문자로 변경
	{
		
		printf("대소문자 변경 : %c", num-32); //소문자-32 = 대문자

	}
	else // 대문자, 소문자 아닐경우
	{  
		printf("대소문자 변경 : 알파벳이 아닙니다"); //대소문자가 아닐경우 출력
	}
	printf("\n"); //줄 띄우기
	return 0; //0의 반환
}//main함수의 끝