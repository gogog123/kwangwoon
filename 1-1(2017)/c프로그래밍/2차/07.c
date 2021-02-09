#include<stdio.h> //해더파일선언
int factorial(int n) //factorial함수 정의
{
	if (n == 0) //n이 0
		return 1; //1일때 종료
	else
		return n*factorial(n - 1); //재귀함수 활용
}
int combination(int n, int r) //combination함수 정의
{
	if (n<r) //n<r일떄
		return -1;
	if (n == 0 && r == 0) //n,r=0일때
		return 1;
	return (factorial(n) / (factorial(n - r))) / (factorial(r)); //
}
void pascalTri(int n) //파스칼 삼각형 함수 정의
{
	int i = 0, j = 0; //i, j변수 선언
	for (i = 0; i<n; i++) //i는 0부터 n까지 반복
	{
		for (j = 0; j<n - i; j++) //출력값이 점점 작아짐
			printf("   "); // '    '출력
		for (j = 0; j<i; j++) //j는 0부터 i까지 반복
			printf("%-6d", combination(i, j)); // 자리 맞춰줌
		
		printf("%-6d \n", combination(i, i));
	}
}
int main() //main함수의 시작
{
	int input; //input변수 선언
	printf("Input: "); //'input'출력
	scanf_s("%d", &input); //값 입력
	pascalTri(input); //pascalTri함수 출력
	return 0; //0의 반환
} //main 함수의 끝