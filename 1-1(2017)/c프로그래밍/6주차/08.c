#include<stdio.h> //�ش����� ����
int main() //main�Լ��� ����
{
	int i; //i���� ����
	int arr[5] = {1,2,3,4,5}; //arr�迭 
	int n = sizeof(arr) / sizeof(int); //�迭 arr�� ���� ���
	double sum=0, average, v; //sum=��, average=���, v=�л�
	printf("Array : "); //�迭arr���
	for (i = 0; i < n; i++) //0��°���� arr���̱��� �ݺ�
		printf("%d ", arr[i]); //arr[i]���
	printf("\n"); // �ٶ���
	for (i = 0; i < n; i++)//0��°���� arr���̱��� �ݺ�
	{
		sum += arr[i]; //arr�迭�� ��
	}
	average = sum / n; //���=��/����
	sum = 0; //���ʱ�ȭ
	for (i = 0; i < n; i++) //0��°���� arr���̱��� �ݺ�
		sum += (arr[i] - average)*(arr[i] - average);// (�迭-���)����
	v = sum / n; //sum/����
	printf("��� = %4.6f\n", average); //������
	printf("�л� = %4.6f\n", v); //�л� ���
	return 0; //0�� ��ȯ
} //main�Լ��� ����
