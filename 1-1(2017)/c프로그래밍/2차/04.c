#include<stdio.h> //�ش����� ����
int Recursive(int n) //Recursive�Լ� ����
{
	if (n <= 0)//0���� ������ ���� 
 		return 0;
	return (n + Recursive(n - 1)); //����Լ� 1�� �۾����鼭 ����
}
int main() //main �Լ��� ����
{
	int n; //n���� ����
	printf("1���� n������ �� ���ϱ�\n");//printf ���
	printf("n �Է� : "); 
	scanf("%d", &n); //n�� �Է�
	printf("��� : %d\n", Recursive(n)); //Recursive�Լ� ���
	return 0; //0�ǹ�ȯ
}//main�Լ��� ����