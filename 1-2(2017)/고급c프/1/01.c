#include<stdio.h> //해더파일 선언
void Menu1(num) //16진수 --> 2진수, 10진수 변환시키는 함수
{
	int a;
	int i, j;
	int result[4]; //변수 선언
	printf("Please insert a hexadecimal number: "); 
	scanf("%X", &a); //16진수 값 입력
	int n = a; //n에 a값 저장
	
	for (i = 0; a > 0; i++) //i=0부터 a>0일때 까지 반복
	{
		result[i] = a % 2; //2로 나눈 나머지 배열에 저장
		a = a / 2;  

	} //2진수 거꾸로 배열에 저장
	printf("Hexadecimal '%X'is ", n); //%X 16진수 반환
	
	for (j = i - 1; j >= 0; j--)
	{
		printf("%d", result[j]); //배열에 저장된 값 거꾸로 출력
	}
	printf(" in binary\n"); 
	printf("Hexadecimal '%X'is %d in decimal\n", n, n); //16 -->10진수 출력
}

void Menu2(num) //10진수 --> 2진수,16진수 변환시키는 함수
{
	int a;
	int i, j; //변수 선언
	int result[4];
	printf("Please insert a decimal number: "); 
	scanf("%d", &a); //10진수 값 입력
	int n = a; //n에 a값 저장 
	for (i = 0; a > 0; i++) //i=0부터 a>0일때 까지 반복
	{
		result[i] = a % 2; //2로 나눈 나머지 배열에 저장
		a = a / 2; 
	}//2진수 거꾸로 배열에 저장

	printf("Decimal '%d'is ", n); //10진수 출력

	for (j = i - 1; j >= 0; j--)
	{
		printf("%d", result[j]); //배열에 저장된 값 거꾸로 출력
	}
	printf(" in binary\n");
	printf("Decimal '%d'is %X in hexadecimal\n", n, n); //10진수 --> 16진수 출력
}

void Menu3(num) //2진수 --> 16진수, 10진수 변환시키는 함수
{
	int a;
	int result = 0, temp = 1; //변수 선언
	printf("Please insert a decimal number: ");
	scanf("%d", &a); //2진수 값 입력
	int n = a; //n에 a값 저장 

	while (a > 0) //a>0 일때까지 반복
	{
		if (a % 10==1) //나머지가 1일때
		{
			result += temp; //temp값 추가
		}
		a /= 10; //2진수 10으로 나눔
		temp *= 2; //temp*2
	}
	printf("Binary '%d'is %X in hexadecimal\n", n, result); //2진수 --> 16진수 출력
	printf("Binary '%d'is %d in decimal\n", n, result ); //2진수 --> 10진수 출력

}

void Menu4(num) //프로그램 종료하는 함수
{
	printf("Exiting\n");
	return 0;
}

int main(void) //main 함수 시작
{
	int num = 0; //변수 선언

	while (1) // 계속해서 반복
	{
		printf("--Menu--\n");
		printf("1. Convert Hexadecimal to Binary and Decinal\n"); //16진수 --> 2진수 10진수
		printf("2. Convert Decimal to Binary and Hexadecimal\n"); //10진수 --> 2진수 16진수
		printf("3. Convert Binary to Decimal and Hexadecimal\n"); //2진수 --> 10진수 16진수
		printf("4. Exit\n"); //Menu 출력
		printf("Choose the menu you want:"); //번호 선택 출력

		scanf("%d", &num); //번호 입력

		switch (num) //switch문 num값에 따라 실행
		{
		case 1:
			Menu1(); //1입력했을때 Menu1함수가 실행
			break; 
		case 2:
			Menu2(); //2입력했을때 Menu2함수가 실행
			break; 
		case 3:
			Menu3(); //3입력했을때 Menu3함수가 실행
			break;
		case 4:
			Menu4(); //4입력했을때 Menu4함수가 실행
			return 0; //종료
		default:
			printf("1~4 입력하세요\n"); //다른 숫자를 입력했을때 출력
			break;
		}
	}
	return 0; //0의 반환
} //main 함수의 끝