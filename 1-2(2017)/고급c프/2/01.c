#include <stdio.h> //�ش����� ����
#include <stdlib.h> //���� �߻�
#include <time.h> //�ð� ǥ��

int a = 0;  
int random[10];
int arr[10]; //�������� ����

void Random(num) //������ �����ϴ� �Լ�
{
	int ranNum = 0;
	srand((unsigned)time(NULL));

	for (int i = 0; i < a; i++) //a�� �Է��� �� ��ŭ ���� �߻�
	{
		ranNum = rand() % 100; //0~99 ���� ���� ���� ����
		random[i] = ranNum; //������ ���� random[]�迭�� ����
		arr[i] = ranNum;
	}
}

void Menu1(num) //Menu1 �Լ�
{
	int ranNum = 0; 

	printf("Input the length of the random list: ");
	scanf("%d", &a); //������ ������ ���� �Է�
	printf("Generated random list:"); 
	Random(); //���� ����
	
	for (int i = 0; i < a; i++) //a�� �Է��� �� ��ŭ ���� �߻�
	{
		printf(" %d", random[i]); //�迭 ���
	}

	printf("\n\n\n");
}

void Menu2(num) //������������ �����ϴ� �Լ�
{
	int i, j, temp; 
	float gap;
	time_t startTime = 0, endTime = 0; //���� ����
	printf("- sorting in ascending order\n");
	printf("Original random list:"); 
	

	for (i = 0; i < a; i++)//ó�� ������ ���� ���
	{
		printf(" %d", random[i]); 
	}
	printf("\n");

	startTime = clock(); //����ð� ���� ����
	
	for (i = 1; i < a; i++) //�ݺ��� ��� 1~a���� �ݺ�
	{
		for (j = 0; j < i; j++) //for�� ��� 
		{
			if (random[j] >= random[i]) 
				//�̿����ִ� �� �� �� ���� ���ڰ� ���� ���ں��� ���� ��
			{
				temp = random[i]; //���� ���� ���� 
				random[i] = random[j];
				random[j] = temp; //�� �� ��ġ �ٲ�
			}
		}
		printf("Pass %d: %d %d %d %d %d\n", i, random[0], random[1], random[2], random[3], random[4]);
		//���������� ���� ���
	
	}
	
	endTime = clock(); //����ð� ���� ��
	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC); // ���� �� �κп��� ���� ���� �κ��� ��
	printf("Time elapsed: %.3fs\n", gap); //�ɸ� �ð� ���

	printf("\n\n\n");

}

void Menu3(num)
{
	int i, j, temp;
	float gap;
	time_t startTime = 0, endTime = 0; //���� ����
	printf("- sorting in ascending order\n");
	printf("Original random list:");


	for (i = 0; i < a; i++)//ó�� ������ ���� ���
	{
		printf(" %d", arr[i]);
	}
	printf("\n");

	startTime = clock(); //����ð� ���� ����

	for (i = 1; i < a; i++) //�ݺ��� ��� 1~a���� �ݺ�
	{
		for (j = 0; j < i; j++) //for�� ��� 
		{
			if (arr[j] <= arr[i])
				//�̿����ִ� �� �� �� ���� ���ڰ� ���� ���ں��� ���� ��
			{
				temp = arr[i]; //���� ���� ���� 
				arr[i] = arr[j];
				arr[j] = temp; //�� �� ��ġ �ٲ�
			}
		}
		printf("Pass %d: %d %d %d %d %d\n", i, arr[0], arr[1], arr[2], arr[3], arr[4]);
		//���������� ���� ���

	}

	endTime = clock(); //����ð� ���� ��
	gap = (float)(endTime - startTime) / (CLOCKS_PER_SEC); // ���� �� �κп��� ���� ���� �κ��� ��
	printf("Time elapsed: %.3fs\n", gap); //�ɸ� �ð� ���

	printf("\n\n\n");
}

void Menu4(num) //���α׷��� �����ϴ� �Լ�
{
	printf("Exiting\n");
	return 0;
}

int main(void) //main�Լ�
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
		//MENU�ݺ��ؼ� ���

		scanf("%d", &num); //Menu ��ȣ �Է�

		switch (num) //switch�� num���� ���� ����
		{
		case 1:
			Menu1(); //1�Է����� �� Menu1�Լ��� ����
			break;

		case 2:
			if (a != 0) //�������� �Է¹޾�����
			{
				Menu2();
			}
			else
			{
				printf("Error: Random list is not ready");
				//�������� �Է¹��� �ʾ��� �� ���
				printf("\n\n\n");
			}
			break;

		case 3:
			if (a != 0) //�������� �Է¹޾�����
			{
				Menu3();
			}
			else
			{
				printf("Error: Random list is not ready");
				//�������� �Է¹��� �ʾ��� �� ���
				printf("\n\n\n");
			}
			break;

		case 4:
			Menu4(); //4�Է����� �� Menu4�Լ��� ����
			return 0;
		}
	}

	return 0; //0�� ��ȯ
}//main �Լ��� ��