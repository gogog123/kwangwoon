#include<stdio.h> //해더파일 선언
int Recursive(int n) //Recursive함수 시작
{
	if (n <= 0)//0보다 작을때 종료 
 		return 0;
	return (n + Recursive(n - 1)); //재귀함수 1씩 작아지면서 더함
}
int main() //main 함수의 시작
{
	int n; //n변수 선언
	printf("1부터 n까지의 합 구하기\n");//printf 출력
	printf("n 입력 : "); 
	scanf("%d", &n); //n값 입력
	printf("결과 : %d\n", Recursive(n)); //Recursive함수 출력
	return 0; //0의반환
}//main함수의 선언