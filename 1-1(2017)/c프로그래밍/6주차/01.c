#include<stdio.h> //해더파일 선언
int Sum(int mA, int mB); //Sum함수 만들기
double Average(int mA, int mB); //Average함수 만들기
char Compare(int num1, int num2); //Compare함수 만들기

int main(void) // main 함수의 시작
{
	int a, b; //변수 a,b 선언
	printf("정수 두 개 입력 : "); //정수 두개 출력
	scanf("%d %d", &a, &b); // 정수 두개 입력
	printf(">> Sum : %d\n", Sum(a, b)); //함수 Sum값 출력
	printf(">> Average : %.1f\n", (Average(a, b))); //함수 Average값 출력
	printf(">> Compare : %d %c %d\n", a, Compare(a, b), b); //함수 Compare값 출력
	return 0; // 0의반환
} //main 함수의 끝

int Sum(int mA, int mB) //Sum함수의 정의
{
	return mA + mB; //정수 두 개 더한값 반환

}

double Average(int mA, int mB) //Average함수의 정의
{
	return (mA + mB) / (2.0); //정수 두개 평균
}

char Compare(int num1, int num2) //Compare함수의 정의
{
	if (num1 < num2) //num1<num2일때 '<' 반환
		return '<';
	
	else if (num1 == num2) //num1==num2 일때 '=' 반환
		return '=';
	
	else //위 두 경우도 아닐떄 '>' 반환
		return '>';
}
