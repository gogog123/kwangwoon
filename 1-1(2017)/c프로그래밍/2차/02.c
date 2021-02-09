#include<stdio.h> //해더파일 선언
int setID() //함수 setID 정의
{
	int id; //id 변수 선언
	printf("학번 입력 : "); //학번 출력
	scanf("%d", &id); //학번 입력
	return id; //id 반환
}
void printTimeTable(mID) //인자전달하는 함수 printTImeTable함수 선언
{
	printf("\n============= 시간표 (학번 : %d) ============\n", mID); 
	printf("\t%-20s%-12s%-12s\n", "교과목명", "강의시간", "강의실");
	printf("=====================================================\n");
	printf("\t%-20s%-12s%-12s\n", "C프로그래밍", "월6수5", "연204");
	printf("\t%-20s%-12s%-12s\n", "고급프로그래밍", "월01", "비514");
	printf("\n"); //시간표 출력
}
int main() //main 함수 시작
{
	int id = 0, sel = 0; // 변수 선언
	printf("1. 학번 입력\n");
	printf("2. 시간표 확인\n");
	printf("3. 종료\n"); 
	//시간표출력
	
	while (1) 
	{
		printf(">> select : "); //sel값 출력
		scanf("%d", &sel); //sel값 입력


		switch (sel) //switch문 활용
		{
		case 1:
			id=setID(); //setID 함수 출력
			break;
		case 2:
			if (id != 0) //id가 0이 아닐때
				printTimeTable(); //printTimeTable 함수 출력
			else //나머지 일때
				printf("학번을 먼저 입력하세요.\n"); //출력
			break;
		case 3:
			return 0; //switch문 빠져 나감
		} 
	}
	return 0; //0의 반환
}//main 함수의 끝