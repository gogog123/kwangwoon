#include<stdio.h> //해더파일 선언
int main() //main 함수의 시작
{
	char ch; 
	int num = 0; //변수 선언

	printf("문자 입력 : "); //'문자입력' 출력
	scanf("%c", &ch, sizeof(ch)); //문자 입력
	printf("높이 입력 : "); //'높이 입력' 출력
	scanf("%d", &num); //num값 입력
	Tree(ch, num); //Tree함수 출력

	return 0; //0의 반환
} //main 함수의 끝
int Tree(char ch, int num) //Tree함수 정의
{ 
	int i, j; //변수 i,j 선언
	for (i = 0; i < num; i++) //i는0부터 num까지 반복
	{
		for (j = 0; j <= i; j++) //j는 0부터 i까지 반복
			printf(" "); // ' '출력
		for (j = (num - i) * 2 - 1; j > 0; j--) //j는 2개씩 작아짐
			printf("%c", ch); //문자출력
		printf("\n"); //줄 띄우기
	}
}//Tree함수의 끝