#include<stdio.h> //해더파일 선언
void Recursive(int a) //Recursive 인자 전달
{
	if (a == 0) //a=0일때 종료
		return 0;
	int b = (a / 10) * 10; //마지막자릿수=0
	printf("%d", a-b); //나머지값 출력
	Recursive(a / 10); //각 자릿수 출력
}
int main() //main함수의 시작
{
	int a; //a변수 선언
	printf("Input : ");
	scanf("%d", &a);

	printf("Output: ");
	Recursive(a); //Recursive함수호출
	printf("\n"); //줄 띄우기
	return 0; //0의 반환
}//main함수의 끝
