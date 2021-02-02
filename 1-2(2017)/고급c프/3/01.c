#include <stdio.h> 
#include <stdlib.h> //해더파일 선언

int a = 0;
int randomX[5][5];
int randomY[5][5]; //전역변수 선언

void Menu1(num) //Menu1 함수(X,Y정방행렬 출력)
{
	int ranNum; //변수 선언
	srand((unsigned)time(NULL)); //난수 발생
	printf("Input the number of rows (2~5): "); 
	scanf("%d", &a); //정방행렬 크기 입력
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			ranNum = rand() % 100; //0~99 범위 내의 난수 생성
			randomX[i][j] = ranNum; //생성한 난수 randomX[][]에 저장
		}
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			ranNum = rand() % 100;
			randomY[i][j] = ranNum; //생성한 난수 randomY[][]에 저장
		}
	}
	printf("X =\n");
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			printf("%4d", randomX[i][j]);
		}
		printf("\n");
	} //정방행렬 X 출력
	printf("Y =\n");
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			printf("%4d", randomY[i][j]);
		}
		printf("\n");
	} 
	//정방행렬 Y출력
	printf("\n\n\n");
}

void Menu2(num) //Menu2 함수(X, Y의 전치행렬 출력)
{
	int TransposeX[5][5];
	int TransposeY[5][5];

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			TransposeX[j][i] = randomX[i][j];
			TransposeY[j][i] = randomY[i][j];
		}
	}
	printf("Transpose X and Y\n");
	printf("X^T =\n");

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			printf("%4d", TransposeX[i][j]);
		}
		printf("\n");
	}//X의 전치 행렬 출력

	printf("Y^T =\n");
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			printf("%4d", TransposeY[i][j]);
		}
		printf("\n");
	}//Y의 전치 행렬 출력
	printf("\n\n\n");
}

void Menu3(num) //Menu3 함수(입력받은 각도만큼 회전하는 행렬 출력)
{
	int rotate;
	printf("Input the degree to rotate:");
	scanf("%d", &rotate); //회전할 각도 입력
	if (rotate == 90) //입력받은 값이 90도 일때
	{
		printf("X =\n");
		for (int j = 0; j < a; j++)
		{
			for (int i = a -1; i >= 0; i--)
			{
				printf("%4d", randomX[i][j]);
			}
			printf("\n");
		}

		printf("Y =\n");
		for (int j = 0; j < a; j++)
		{
			for (int i = a - 1; i >= 0; i--)
			{
				printf("%4d", randomY[i][j]);
			}
			printf("\n");
		}
	}
	else if (rotate == 180)//입력받은 값이 180도 일때
	{
		printf("X =\n");
		for (int i = a - 1; i >= 0; i--)
		{
			for (int j = a - 1; j >= 0; j--)
			{
				printf("%4d", randomX[i][j]);
			}
			printf("\n");
		}
		printf("Y =\n");
		for (int i = a - 1; i >= 0; i--)
		{
			for (int j = a - 1; j >= 0; j--)
			{
				printf("%4d", randomY[i][j]);
			}
			printf("\n");
		}
	}
	else if (rotate == 270) //입력받은 값이 270도 일때
	{
		printf("X =\n");
		for (int i = a - 1; i >= 0; i--)
		{
			for (int j = a - 1; j >= 0; j--)
			{
				printf("%4d", randomX[i][j]);
			}
			printf("\n");
		}
		printf("Y =\n");
		for (int j = a-1; j >= 0; j--)
		{
			for (int i = 0; i < a; i++)
			{
				printf("%4d", randomY[i][j]);
			}
			printf("\n");
		}

	}
	else if (rotate == 360) ////입력받은 값이 360도 일때
	{
		printf("X =\n");
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				printf("%4d", randomX[i][j]);
			}
			printf("\n");
		}
		printf("Y =\n");
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				printf("%4d", randomY[i][j]);
			}
			printf("\n");
		}

	}
	else
	{
		printf("Error: select 90, 180, 270, 360\n");
	}
	printf("\n\n\n");
}

void Menu4(num) //Menu4 함수(X, Y의 역행렬 출력)
{

}

void Menu5(num) //Menu5 함수(연산기호를 입력 받아 결과행렬을 출력)
{
	int calculation;
	int Calculation[5][5]; 
	printf("Input the calculation (+, - , *):");
	calculation = getch(); //연산기호 인식
	if (calculation == '+') //+연산 입력받았을 때
	{
		printf("+\n");
		printf("X + Y =\n");
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				printf("%4d", randomX[i][j] + randomY[i][j]);
			}
			printf("\n");
		}
	}
	else if (calculation == '-') //-연산 입력받았을 때
	{
		printf("-\n");
		printf("X - Y =\n");
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				printf("%4d", randomX[i][j] - randomY[i][j]);
			}
			printf("\n");
		}
	}

	else if (calculation == '*') //*연산 입력받았을 때
	{
		printf("*\n");
		printf("X * Y =\n");
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				int sum = 0;
				for (int k = 0; k < a; k++)
				{
					sum += randomX[i][k] * randomY[k][j];
				}
				Calculation[i][j] = sum;
			}
		}
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				printf("%6d", Calculation[i][j]);
			}
			printf("\n");
		}
	}
	printf("\n\n\n");
}

void Menu6(num) //Menu6함수(프로그램을 종료하는 함수)
{
	printf("Exiting\n");
	return 0;
}

int main(void) //main함수의 시작
{
	int num = 0;
	while (1) //반복문
	{
		printf("--Menu--\n");
		printf("1. Random Square Matrix Generation\n");
		printf("2. Transpose(T)\n");
		printf("3. Rotation(90, 180, 270, 360 degree)\n");
		printf("4. Inverse (^-1)\n");
		printf("5. Calculation (+, - , *)\n");
		printf("6. Exit\n");
		printf("Choose the item you want: ");
		//Menu 반복해서 출력
	
		
		scanf("%d", &num); //Menu 번호 입력

		switch (num)
		{
		case 1:
			Menu1();
			break;

		case 2:
			Menu2();
			break;
		
		case 3:
			Menu3();
			break;

		case 4:
			Menu4();
			break;

		case 5:
			Menu5();
			break;

		case 6:
			Menu6();
			return 0;
		} //입력받는 num값에 따라 각 함수로 이동
	}

	return 0; //0의 반환
} //main 함수의 끝