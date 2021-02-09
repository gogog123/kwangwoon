#include<stdio.h> //해더파일 선언
int main() //main함수의 시작
{
	int i; //i변수 선언
	int arr[5] = {1,2,3,4,5}; //arr배열 
	int n = sizeof(arr) / sizeof(int); //배열 arr의 길이 계산
	double sum=0, average, v; //sum=합, average=평균, v=분산
	printf("Array : "); //배열arr출력
	for (i = 0; i < n; i++) //0번째부터 arr길이까지 반복
		printf("%d ", arr[i]); //arr[i]출력
	printf("\n"); // 줄띄우기
	for (i = 0; i < n; i++)//0번째부터 arr길이까지 반복
	{
		sum += arr[i]; //arr배열의 합
	}
	average = sum / n; //평균=합/개수
	sum = 0; //합초기화
	for (i = 0; i < n; i++) //0번째부터 arr길이까지 반복
		sum += (arr[i] - average)*(arr[i] - average);// (배열-평균)제곱
	v = sum / n; //sum/개수
	printf("평균 = %4.6f\n", average); //평균출력
	printf("분산 = %4.6f\n", v); //분산 출력
	return 0; //0의 반환
} //main함수의 시작
