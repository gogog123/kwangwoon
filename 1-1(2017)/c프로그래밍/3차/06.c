#include <stdio.h> //해더파일 선언
int get_array(int *arr,int i) //5개의 정수를 입력하는 함수
{
	int a; //변수 선언
	printf("%d개의 정수를 입력하시오\n",i);
	for (a = 0; a < i; a++)
		scanf("%d\n", &arr[a]); //배열에 정수 입력
}
int prt_array(int *arr, int i) //모든 수를 출력하는 함수
{
	int a; //변수 선언
	printf("모든 수 출력: "); 

	for (a = 0; a < i; a++) 
		printf("%d ", arr[a]); //모든 수를 출력
}
int main() //main함수의 시작
{
	int arr[5]; //배열 선언 
	get_array(arr, 5); //5개 정수 입력
	prt_array(arr, 5); //모든 수를 출력하는 함수 
	return 0; //0의 반환
} //main함수의 끝
