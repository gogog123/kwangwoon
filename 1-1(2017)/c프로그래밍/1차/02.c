#include<stdio.h> //�ش����� ����
int main(void) //main�Լ��� ����
{
	int a; //���� a�� ����
	int b = 1; //���� b=1����
	int result = 1; //result=1����

	printf("���ڸ� �Է��Ͻÿ� : "); //���� ���
	scanf("%d", &a); //�����Է�

	while (b <= a) //while�� b<=a �϶����� ����
	{
		result *= b; //���Կ����� ���
		b++; //���� ������ ���
	}
	printf("%d! = %d\n", a, result); //���丮�� �� ���
	return 0; //0�� ��ȯ

} //main�Լ��� ��