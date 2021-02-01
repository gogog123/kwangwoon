#include<stdio.h> //�ش����ϼ���
int factorial(int n) //factorial�Լ� ����
{
	if (n == 0) //n�� 0
		return 1; //1�϶� ����
	else
		return n*factorial(n - 1); //����Լ� Ȱ��
}
int combination(int n, int r) //combination�Լ� ����
{
	if (n<r) //n<r�ϋ�
		return -1;
	if (n == 0 && r == 0) //n,r=0�϶�
		return 1;
	return (factorial(n) / (factorial(n - r))) / (factorial(r)); //
}
void pascalTri(int n) //�Ľ�Į �ﰢ�� �Լ� ����
{
	int i = 0, j = 0; //i, j���� ����
	for (i = 0; i<n; i++) //i�� 0���� n���� �ݺ�
	{
		for (j = 0; j<n - i; j++) //��°��� ���� �۾���
			printf("   "); // '    '���
		for (j = 0; j<i; j++) //j�� 0���� i���� �ݺ�
			printf("%-6d", combination(i, j)); // �ڸ� ������
		
		printf("%-6d \n", combination(i, i));
	}
}
int main() //main�Լ��� ����
{
	int input; //input���� ����
	printf("Input: "); //'input'���
	scanf_s("%d", &input); //�� �Է�
	pascalTri(input); //pascalTri�Լ� ���
	return 0; //0�� ��ȯ
} //main �Լ��� ��