#include<stdio.h> //�ش����� ����
int main() //main �Լ��� ����
{
	char ch; 
	int num = 0; //���� ����

	printf("���� �Է� : "); //'�����Է�' ���
	scanf("%c", &ch, sizeof(ch)); //���� �Է�
	printf("���� �Է� : "); //'���� �Է�' ���
	scanf("%d", &num); //num�� �Է�
	Tree(ch, num); //Tree�Լ� ���

	return 0; //0�� ��ȯ
} //main �Լ��� ��
int Tree(char ch, int num) //Tree�Լ� ����
{ 
	int i, j; //���� i,j ����
	for (i = 0; i < num; i++) //i��0���� num���� �ݺ�
	{
		for (j = 0; j <= i; j++) //j�� 0���� i���� �ݺ�
			printf(" "); // ' '���
		for (j = (num - i) * 2 - 1; j > 0; j--) //j�� 2���� �۾���
			printf("%c", ch); //�������
		printf("\n"); //�� ����
	}
}//Tree�Լ��� ��