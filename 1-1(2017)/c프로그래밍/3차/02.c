#include <stdio.h> //해더파일 선언
void main() //main 함수의 시작
{
	char ch = 'C'; //문자'C'변수 선언
	int n1 = 100; //n1=100 변수 선언
	double n2 = 3.3; //n2변수 선언

	char *pCh = &ch; //포인터 pCh는 문자'C'를 가리킴
	int *pN1 = &n1; //포인터 pN1은 
	double *pN2 = &n2;

	printf("ch의 값 : %c\t주소 : %p\n", ch, &ch); //ch는 가리키는 값 , &ch는 주소값
	printf("n1의 값 : %d\t주소 : %p\n", n1, &n1); //n1은 가리키는 값, &n1은 주소값
	printf("n2의 값 : %.1f\t주소 : %p\n", n2, &n2); //n2는 가리키는 값, &n2는 주소값

	printf("pCh의 값 : %p\t가리키는 곳의 값 : %c\n", pCh, *pCh); //pCh는 주소값, *pCh는 가리키는 값
	printf("pN1의 값 : %p\t가리키는 곳의 값 : %c\n", pN1, *pN1); //pN1은 주소값, *pN1은 가리키는 값
	printf("pN2의 값 : %p\t가리키는 곳의 값 : %c\n", pN2, *pN2); //pN2는 주소값, *pN2는 가리키는 값

	*pCh = 'E'; //*pCh(주소값)는 'E'로 값 변경
	*pN1 = 200; //*pN1(주소값)는 '200'으로 값 변경
	*pN2 = 4.4; //*pN2(주소값)는 '4.4'로 값 변경

	printf("ch의 값 : %c\t주소 : %p\n", ch, &ch); //ch는 가리키는 값 , &ch는 주소값                 
	printf("n1의 값 : %d\t주소 : %p\n", n1, &n1); //n1은 가리키는 값, &n1은 주소값
	printf("n2의 값 : %.1f\t주소 : %p\n", n2, &n2); //n2는 가리키는 값, &n2는 주소값
}//main함수의 끝