#include<stdio.h> //�ش����� ����
int Sum(int mA, int mB); //Sum�Լ� �����
double Average(int mA, int mB); //Average�Լ� �����
char Compare(int num1, int num2); //Compare�Լ� �����

int main(void) // main �Լ��� ����
{
	int a, b; //���� a,b ����
	printf("���� �� �� �Է� : "); //���� �ΰ� ���
	scanf("%d %d", &a, &b); // ���� �ΰ� �Է�
	printf(">> Sum : %d\n", Sum(a, b)); //�Լ� Sum�� ���
	printf(">> Average : %.1f\n", (Average(a, b))); //�Լ� Average�� ���
	printf(">> Compare : %d %c %d\n", a, Compare(a, b), b); //�Լ� Compare�� ���
	return 0; // 0�ǹ�ȯ
} //main �Լ��� ��

int Sum(int mA, int mB) //Sum�Լ��� ����
{
	return mA + mB; //���� �� �� ���Ѱ� ��ȯ

}

double Average(int mA, int mB) //Average�Լ��� ����
{
	return (mA + mB) / (2.0); //���� �ΰ� ���
}

char Compare(int num1, int num2) //Compare�Լ��� ����
{
	if (num1 < num2) //num1<num2�϶� '<' ��ȯ
		return '<';
	
	else if (num1 == num2) //num1==num2 �϶� '=' ��ȯ
		return '=';
	
	else //�� �� ��쵵 �ƴҋ� '>' ��ȯ
		return '>';
}
