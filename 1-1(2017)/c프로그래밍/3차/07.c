#include <stdio.h> //�ش����� ����
void reverse(int *num) //reverse�Լ��� ����
{
	int temp; //���� temp����
	for (int i = 0; i < 5; i++) //0~4���� �ݺ�
	{
		temp = num[i]; 
		num[i] = num[9 - i]; //�迭 0~4���� ���� �ٲ�
		num[9 - i] = temp; //�迭 5~9���� ���� �ٲ�
	}
}//reverse�Լ��� ��

int main() //main �Լ��� ����
{
	int arr[10]; // �迭 ����
 	int i = 0; //���� i����
	
	printf("10���� ���� �Է�\n>> "); //10���� ���� ���
	for (i = 0; i < 10; i++) 
		scanf("%d", &arr[i]); //10���� ���� �Է�

	reverse(arr); //������ ������ �ڹٲ�

	printf(">> "); 
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]); //������ �ڹٲ� �迭 ���
	printf("\n"); //�ٶ���
	return 0; //0�� ��ȯ
} //main�Լ��� ��
