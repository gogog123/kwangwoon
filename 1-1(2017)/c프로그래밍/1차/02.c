#include<stdio.h> //해더파일 선언
int main(void) //main함수의 시작
{
	int a; //변수 a의 선언
	int b = 1; //변수 b=1선언
	int result = 1; //result=1선언

	printf("숫자를 입력하시오 : "); //숫자 출력
	scanf("%d", &a); //숫자입력

	while (b <= a) //while문 b<=a 일때까지 실행
	{
		result *= b; //대입연산자 사용
		b++; //증가 연산자 사용
	}
	printf("%d! = %d\n", a, result); //팩토리얼 값 출력
	return 0; //0의 반환

} //main함수의 끝