#include<stdio.h> //�ش����� ����
int main(void) //main�Լ��� ����
{
	int num, a, b; //���� ����
	printf("Input : "); //Input���
	scanf("%d", &num); //�� �Է�

	for (a = 0; a < num; a++) //for�� ����
	{
		for (b = num - a; b > 0; b--) //��ĭ �ϳ��� �پ���
			printf(" "); //��ĭ ���
		for (b = 0; b < a*2+1; b++) //*�ΰ��� ����
			printf("*"); //*���
		
		printf("\n"); //�� ����
	
	}//for�� ��
	return 0; //0�� ��ȯ
} //main�Լ��� ��