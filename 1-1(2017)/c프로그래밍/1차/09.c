#include<stdio.h> //�ش����� ����
int main(void) //main �Լ��� ����
{
	int num, a; //���� ����
	printf("Input : "); //Input ���
	scanf("%d", &num); //�� �Է� 
	printf("%d�� ��� : ", num); //num�� ���

	for (a = num; a > 0; a--) //for�� a�� 1�϶����� �ݺ�
	{
		if (num%a == 0) //num�� a�� �������� �������� 0
		printf("%d ", num/a); //num�� ��� ���
	
	}//for���� ��
	printf("\n"); //�� ����

	return 0; //0�� ��ȯ
} //main�Լ��� ��