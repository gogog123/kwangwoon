#include<stdio.h> //�ش����� ����
void Recursive(int a) //Recursive ���� ����
{
	if (a == 0) //a=0�϶� ����
		return 0;
	int b = (a / 10) * 10; //�������ڸ���=0
	printf("%d", a-b); //�������� ���
	Recursive(a / 10); //�� �ڸ��� ���
}
int main() //main�Լ��� ����
{
	int a; //a���� ����
	printf("Input : ");
	scanf("%d", &a);

	printf("Output: ");
	Recursive(a); //Recursive�Լ�ȣ��
	printf("\n"); //�� ����
	return 0; //0�� ��ȯ
}//main�Լ��� ��
