/*
제목: c프_5주차_2017202087_홍세정_
수정날짜: 2017.04.24
작성자: 홍세정
*/

#include<stdio.h> //해더파일 선언
int main(void) //main함수의 시작
{
	int num; //num 변수선언
	printf("숫자를 입력하시오: "); //숫자출력
	scanf("%d", &num); //숫자 입력

	while (num>=0) // while 반복문 0일때까지 반복
	{
		printf("%d\n", num); // num값 출력
		num--; //선감소 후 연산
	}
	return 0; //0의 반환
} //main함수의 끝