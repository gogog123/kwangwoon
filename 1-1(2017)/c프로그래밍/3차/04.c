#include <stdio.h> //�ش����� ����
int main() //main�Լ��� ����
{
	int num[7] = { 0 }; //�迭 num ����
	int *pNum = num; 
	int i = 0; //���� ����

	printf("�ϰ� ���� ���� �Է�: "); //�ϰ� ���� ���� ���
	for (i = 0; i < 7; i++) //0~7���� �迭num�� �� ����
	{
		scanf("%d", &num[i]); //���� �� �Է�
	}
	printf("���(x3): "); // ���(x3)���
	for (i = 0; i < 7; i++) 
	{
		*pNum = num[i] * 3; //�迭 X3
		printf("%d ", *pNum); //�迭 X3 ���
	}
	printf("\n"); //�� ����
	return 0; //0�� ��ȯ
} //main �Լ��� ����