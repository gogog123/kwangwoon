#include<stdio.h> //�ش����� ����
int main() //main�Լ��� ����
{
	int i; //i ���� ����
	int arr[9] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 }; //���̰� 9�� arr�� �迭
	printf("Original number: "); 
	for (i = 0; i < 9; i++) //0��°���� 8��°���� �ݺ�
	{
		printf("%d ", arr[i]); //arr�迭 ���

	}
	printf("\nNew numvers: "); 
	for (i = 0; i < 9; i++) //0��°���� 8��°���� �ݺ�
	{
		printf("%d ", arr[i]+i);//�迭��Ҹ�ŭ ����
	}
	printf("\n"); // �ٶ���
	return 0; //0�� ��ȯ
}//main�Լ��� ��
