#include<stdio.h> // �ش����� ����
int main(void) //main�Լ��� ����
{
	int a = 0;
	int b = 0;
	int c = 1;
	int d, num; //���� ����
	printf("Input : "); //Input�� ���
	scanf("%d", &num); // �� �Է�
	for (d = 1; d <= num; d++)
	{
		printf("%d ", c); //����� c ���
		a = b; 
		b = c; 
		c = a + b; //�Ǻ���ġ ����
	}
	printf("\n"); //�� ����

	return 0; //0�� ��ȯ 
} //main�Լ��� ��