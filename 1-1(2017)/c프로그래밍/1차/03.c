#include<stdio.h> //�ش����� ����
int main(void) //main�Լ��� ����
{
	int num; //num���� ����

	do //do~while�� ���
	{
		printf("input : "); //���� ���
		scanf("%d", &num); //���� �Է�

	} while (num != -1); //-1�϶� ����
	return 0; //0�� ��ȯ
} //main�Լ��� ��