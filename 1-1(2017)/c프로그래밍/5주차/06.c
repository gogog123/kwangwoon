#include<stdio.h> //�ش����� ����
int main(void) //main�Լ��� ����
{
	int num, a, b; //���� ����
	printf("Input : "); //input ���
	scanf("%d", &num); //num�� �Է�

	for (a = 0; a < num; a++) //�� num�ٸ����
	{
		for (b = num - a; b > 0; b--) //*�ݺ��ؼ� ���
			printf("*"); //*���
		printf("\n"); //�� ����
	}
	return 0; //0�� ��ȯ
} //main �Լ��� ��