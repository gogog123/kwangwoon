#include<stdio.h> //�ش����� ����
int main(void) //main�Լ��� ����
{
	int num, a, b; //���� ����
	printf("Input : "); //Input ���
	scanf("%d", &num); //�� �Է�

	for (a=1; a<=num; a++) // a�� 1��Ŀ�� 
	{
		for (b = 0; b < num; b++) //b�� 1��Ŀ��
		{
			printf("%5d", num*a-b); // 5ĭ���� �� ���
		}
		printf("\n"); //�ٶ���
	} //for�� ��
	return 0; //0�� ��ȯ

} //main �Լ��� ��