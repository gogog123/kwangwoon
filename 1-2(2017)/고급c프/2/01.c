#include <stdio.h> //해더파일 선언
#include <stdlib.h> //난수 발생
#include <time.h> //시간 표시

int a = 0;  
int random[10];
int arr[10]; //전역변수 선언

void Random(num) //난수를 생성하는 함수
{
	int ranNum = 0;
	srand((unsigned)time(NULL));

	for (int i = 0; i < a; i++) //a에 입력한 값 만큼 난수 발생
	{
		ranNum = rand() % 100; //0~99 범위 내의 난수 생성
		random[i] = ranNum; //생성한 난수 random[]배열에 저장
		arr[i] = ranNum;
	}
}

void Menu1(num) //Menu1 함수
{
	int ranNum = 0; 

	printf("Input the length of the random list: ");
	scanf("%d", &a); //생성할 난수의 개수 입력
	printf("Generated random list:"); 
	Random(); //난수 저장
	
	for (int i = 0; i < a; i++) //a에 입력한 값 만큼 난수 발생
	{
		printf(" %d", random[i]); //배열 출력
	}

	printf("\n\n\n");
}

void Menu2(num) //오름차순으로 정렬하는 함수
{
	int i, j, temp; 
	float gap;
	time_t startTime = 0, endTime = 0; //변수 선언
	printf("- sorting in ascending order\n");
	printf("Original random list:"); 
	

	for (i = 0; i < a; i++)//처음 생성한 난수 출력
	{
		printf(" %d", random[i]); 
	}
	printf("\n");

	startTime = clock(); //수행시간 측정 시작
	
	for (i = 1; i < a; i++) //반복문 사용 1~a까지 반복
	{
		for (j = 0; j < i; j++) //for문 사용 
		{
			if (random[j] >= random[i]) 
				//이웃해있는 두 수 비교 뒤의 숫자가 앞의 숫자보다 작을 때
			{
				temp = random[i]; //뒤의 숫자 저장 
				random[i] = random[j];
				random[j] = temp; //두 수 위치 바꿈
			}
		}
		printf("Pass %d: %d %d %d %d %d\n", i, random[0], random[1], random[2], random[3], random[4]);
		//오름차순의 과정 출력
	
	}
	
	endTime = clock(); //수행시간 측정 끝
	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC); // 수행 끝 부분에서 수행 시작 부분을 뺌
	printf("Time elapsed: %.3fs\n", gap); //걸린 시간 출력

	printf("\n\n\n");

}

void Menu3(num)
{
	int i, j, temp;
	float gap;
	time_t startTime = 0, endTime = 0; //변수 선언
	printf("- sorting in ascending order\n");
	printf("Original random list:");


	for (i = 0; i < a; i++)//처음 생성한 난수 출력
	{
		printf(" %d", arr[i]);
	}
	printf("\n");

	startTime = clock(); //수행시간 측정 시작

	for (i = 1; i < a; i++) //반복문 사용 1~a까지 반복
	{
		for (j = 0; j < i; j++) //for문 사용 
		{
			if (arr[j] <= arr[i])
				//이웃해있는 두 수 비교 뒤의 숫자가 앞의 숫자보다 작을 때
			{
				temp = arr[i]; //뒤의 숫자 저장 
				arr[i] = arr[j];
				arr[j] = temp; //두 수 위치 바꿈
			}
		}
		printf("Pass %d: %d %d %d %d %d\n", i, arr[0], arr[1], arr[2], arr[3], arr[4]);
		//오름차순의 과정 출력

	}

	endTime = clock(); //수행시간 측정 끝
	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC); // 수행 끝 부분에서 수행 시작 부분을 뺌
	printf("Time elapsed: %.3fs\n", gap); //걸린 시간 출력

	printf("\n\n\n");
}

void Menu4(num) //프로그램을 종료하는 함수
{
	printf("Exiting\n");
	return 0;
}

int main(void) //main함수
{
	int num = 0;

	while (1)
	{
		printf("--Menu--\n");
		printf("1. Random List Generation\n");
		printf("2. Insertion Sort in Ascending Order\n");
		printf("3. Insertion Sort in Descending Order\n");
		printf("4. Exit\n");
		printf("Choose the item you want:"); 
		//MENU반복해서 출력

		scanf("%d", &num); //Menu 번호 입력

		switch (num) //switch문 num값에 따라 실행
		{
		case 1:
			Menu1(); //1입력했을 때 Menu1함수가 실행
			break;

		case 2:
			if (a != 0) //난수값을 입력받았을때
			{
				Menu2();
			}
			else
			{
				printf("Error: Random list is not ready");
				//난수값을 입력받지 않았을 떄 출력
				printf("\n\n\n");
			}
			break;

		case 3:
			if (a != 0) //난수값을 입력받았을때
			{
				Menu3();
			}
			else
			{
				printf("Error: Random list is not ready");
				//난수값을 입력받지 않았을 떄 출력
				printf("\n\n\n");
			}
			break;

		case 4:
			Menu4(); //4입력했을 때 Menu4함수가 실행
			return 0;
		}
	}

	return 0; //0의 반환
}//main 함수의 끝