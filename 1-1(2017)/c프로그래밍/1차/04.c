#include<stdio.h> //�ش����� ����
int main(void) //main�Լ��� ����
{
	int num = 2; //num=2���� ����
	while (num!=16) //while�� 16�϶� ����
	{
		// num��Ģ
		printf(" %d", num*(-1)+1); //num�� ���

		num = num*(-1) + 3; //num��Ģ
		printf(" %d",num); //num�� ���
	}
	printf("\n"); //�� ����

	return 0; //0�� ��ȯ
	
} //main�Լ��� ��