#include <stdio.h> //�ش����� ����
int main() //main�Լ��� ����
{
	int num[10] = { 0 }; //num�迭 ����
	int i; //i���� ����
	int *pMax = NULL; 
	int *pMin = NULL; 

	printf("Input: "); //Input���
	for (i = 0; i < 10; i++) //0~9���� �迭num�� �� ����
	{
		scanf("%d", &num[i]); 
	}
	pMax = &num[0]; //�ʱ� Max�� ����
	pMin = &num[0]; //�ʱ� MIn�� ����
	
	for (i = 0; i < 10; i++) //0~9���� �ݺ�
	{
		if (*pMax < num[i]) //�迭 �� ���� ū �� Ž��
			pMax = &num[i]; //pMax ����
		if (*pMin > num[i]) //�迭 �� ���� ���� �� Ž��
			pMin = &num[i]; //pMin ����
	}

	printf("Max: %d\n", *pMax); //���� ū �� ���
	printf("Min: %d\n", *pMin); //���� ���� �� ���
	return 0; //0�� ��ȯ
} //main�Լ��� ��