#include <stdio.h> 
#include <stdlib.h> //�ش����� ����

int a = 0;
int randomX[5][5];
int randomY[5][5]; //�������� ����

void Menu1(num) //Menu1 �Լ�(X,Y������� ���)
{
	int ranNum; //���� ����
	srand((unsigned)time(NULL)); //���� �߻�
	printf("Input the number of rows (2~5): "); 
	scanf("%d", &a); //������� ũ�� �Է�
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			ranNum = rand() % 100; //0~99 ���� ���� ���� ����
			randomX[i][j] = ranNum; //������ ���� randomX[][]�� ����
		}
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			ranNum = rand() % 100;
			randomY[i][j] = ranNum; //������ ���� randomY[][]�� ����
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
	} //������� X ���
	printf("Y =\n");
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			printf("%4d", randomY[i][j]);
		}
		printf("\n");
	} 
	//������� Y���
	printf("\n\n\n");
}

void Menu2(num) //Menu2 �Լ�(X, Y�� ��ġ��� ���)
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
	}//X�� ��ġ ��� ���

	printf("Y^T =\n");
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			printf("%4d", TransposeY[i][j]);
		}
		printf("\n");
	}//Y�� ��ġ ��� ���
	printf("\n\n\n");
}

void Menu3(num) //Menu3 �Լ�(�Է¹��� ������ŭ ȸ���ϴ� ��� ���)
{
	int rotate;
	printf("Input the degree to rotate:");
	scanf("%d", &rotate); //ȸ���� ���� �Է�
	if (rotate == 90) //�Է¹��� ���� 90�� �϶�
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
	else if (rotate == 180)//�Է¹��� ���� 180�� �϶�
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
	else if (rotate == 270) //�Է¹��� ���� 270�� �϶�
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
	else if (rotate == 360) ////�Է¹��� ���� 360�� �϶�
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

void Menu4(num) //Menu4 �Լ�(X, Y�� ����� ���)
{

}

void Menu5(num) //Menu5 �Լ�(�����ȣ�� �Է� �޾� �������� ���)
{
	int calculation;
	int Calculation[5][5]; 
	printf("Input the calculation (+, - , *):");
	calculation = getch(); //�����ȣ �ν�
	if (calculation == '+') //+���� �Է¹޾��� ��
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
	else if (calculation == '-') //-���� �Է¹޾��� ��
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

	else if (calculation == '*') //*���� �Է¹޾��� ��
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

void Menu6(num) //Menu6�Լ�(���α׷��� �����ϴ� �Լ�)
{
	printf("Exiting\n");
	return 0;
}

int main(void) //main�Լ��� ����
{
	int num = 0;
	while (1) //�ݺ���
	{
		printf("--Menu--\n");
		printf("1. Random Square Matrix Generation\n");
		printf("2. Transpose(T)\n");
		printf("3. Rotation(90, 180, 270, 360 degree)\n");
		printf("4. Inverse (^-1)\n");
		printf("5. Calculation (+, - , *)\n");
		printf("6. Exit\n");
		printf("Choose the item you want: ");
		//Menu �ݺ��ؼ� ���
	
		
		scanf("%d", &num); //Menu ��ȣ �Է�

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
		} //�Է¹޴� num���� ���� �� �Լ��� �̵�
	}

	return 0; //0�� ��ȯ
} //main �Լ��� ��