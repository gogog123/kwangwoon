#include <stdio.h> //�ش����� ����
#include <stdlib.h> 
#include <time.h> //�����Լ� �ش�����

int main(void) //main �Լ��� ����
{
	int i, ranNum, num = 0; //���� ����
	srand((unsigned)time(NULL)); //�Ź� �ٸ� ������ �������� ��
	ranNum = rand() % 10 +1; 
	//1���� 10������ ������ ������ ranNum�� ���, rand()%10�� 0~9�� ������ ����
	printf("Input <1~10>: "); //Input���
	scanf("%d", &i); //i�� �Է�
	while (1)
	{
		if (i < ranNum)
			printf("random number�� %d���� Ů�ϴ�\n", i); //ranNum�� �Է°����� Ŭ�� ���
		else if (i > ranNum)
			printf("random number�� %d���� �۽��ϴ�\n", i); //ranNum�� �Է°����� ������ ���
		else
		{
			printf("random number�� %d�Դϴ�\n", i); //ranNum�� �Է°����� ������ ���
			return 0; //ranNum�� �Է°��� �Ȱ��� �� ����
		}
		printf("Input <1~10>: "); 
		scanf("%d", &i); //i=ranNum�϶����� �ݺ�
	}
	return 0; //0�� ��ȯ
} //main �Լ��� ����