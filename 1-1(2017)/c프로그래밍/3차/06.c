#include <stdio.h> //�ش����� ����
int get_array(int *arr,int i) //5���� ������ �Է��ϴ� �Լ�
{
	int a; //���� ����
	printf("%d���� ������ �Է��Ͻÿ�\n",i);
	for (a = 0; a < i; a++)
		scanf("%d\n", &arr[a]); //�迭�� ���� �Է�
}
int prt_array(int *arr, int i) //��� ���� ����ϴ� �Լ�
{
	int a; //���� ����
	printf("��� �� ���: "); 

	for (a = 0; a < i; a++) 
		printf("%d ", arr[a]); //��� ���� ���
}
int main() //main�Լ��� ����
{
	int arr[5]; //�迭 ���� 
	get_array(arr, 5); //5�� ���� �Է�
	prt_array(arr, 5); //��� ���� ����ϴ� �Լ� 
	return 0; //0�� ��ȯ
} //main�Լ��� ��
