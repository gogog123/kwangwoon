#include<stdio.h> //�ش����� ����
int main(void) //main�Լ��� ����
{
	int num, a, b; //���� ����
	printf("Input : "); //input ���
	scanf("%d", &num); //num�� �Է�

	for (b =0; b < num; b++) //�� num�� �����
	{
		for (a = 0; a <= b; a++) //*�ϳ��� �߰� �ϱ�
			printf("*"); //* ���
		printf("\n"); //�ٶ���ֱ�
	}
	return 0; //0�� ��ȯ
} //main�Լ��� ��