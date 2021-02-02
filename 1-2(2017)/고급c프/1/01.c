#include<stdio.h> //�ش����� ����
void Menu1(num) //16���� --> 2����, 10���� ��ȯ��Ű�� �Լ�
{
	int a;
	int i, j;
	int result[4]; //���� ����
	printf("Please insert a hexadecimal number: "); 
	scanf("%X", &a); //16���� �� �Է�
	int n = a; //n�� a�� ����
	
	for (i = 0; a > 0; i++) //i=0���� a>0�϶� ���� �ݺ�
	{
		result[i] = a % 2; //2�� ���� ������ �迭�� ����
		a = a / 2;  

	} //2���� �Ųٷ� �迭�� ����
	printf("Hexadecimal '%X'is ", n); //%X 16���� ��ȯ
	
	for (j = i - 1; j >= 0; j--)
	{
		printf("%d", result[j]); //�迭�� ����� �� �Ųٷ� ���
	}
	printf(" in binary\n"); 
	printf("Hexadecimal '%X'is %d in decimal\n", n, n); //16 -->10���� ���
}

void Menu2(num) //10���� --> 2����,16���� ��ȯ��Ű�� �Լ�
{
	int a;
	int i, j; //���� ����
	int result[4];
	printf("Please insert a decimal number: "); 
	scanf("%d", &a); //10���� �� �Է�
	int n = a; //n�� a�� ���� 
	for (i = 0; a > 0; i++) //i=0���� a>0�϶� ���� �ݺ�
	{
		result[i] = a % 2; //2�� ���� ������ �迭�� ����
		a = a / 2; 
	}//2���� �Ųٷ� �迭�� ����

	printf("Decimal '%d'is ", n); //10���� ���

	for (j = i - 1; j >= 0; j--)
	{
		printf("%d", result[j]); //�迭�� ����� �� �Ųٷ� ���
	}
	printf(" in binary\n");
	printf("Decimal '%d'is %X in hexadecimal\n", n, n); //10���� --> 16���� ���
}

void Menu3(num) //2���� --> 16����, 10���� ��ȯ��Ű�� �Լ�
{
	int a;
	int result = 0, temp = 1; //���� ����
	printf("Please insert a decimal number: ");
	scanf("%d", &a); //2���� �� �Է�
	int n = a; //n�� a�� ���� 

	while (a > 0) //a>0 �϶����� �ݺ�
	{
		if (a % 10==1) //�������� 1�϶�
		{
			result += temp; //temp�� �߰�
		}
		a /= 10; //2���� 10���� ����
		temp *= 2; //temp*2
	}
	printf("Binary '%d'is %X in hexadecimal\n", n, result); //2���� --> 16���� ���
	printf("Binary '%d'is %d in decimal\n", n, result ); //2���� --> 10���� ���

}

void Menu4(num) //���α׷� �����ϴ� �Լ�
{
	printf("Exiting\n");
	return 0;
}

int main(void) //main �Լ� ����
{
	int num = 0; //���� ����

	while (1) // ����ؼ� �ݺ�
	{
		printf("--Menu--\n");
		printf("1. Convert Hexadecimal to Binary and Decinal\n"); //16���� --> 2���� 10����
		printf("2. Convert Decimal to Binary and Hexadecimal\n"); //10���� --> 2���� 16����
		printf("3. Convert Binary to Decimal and Hexadecimal\n"); //2���� --> 10���� 16����
		printf("4. Exit\n"); //Menu ���
		printf("Choose the menu you want:"); //��ȣ ���� ���

		scanf("%d", &num); //��ȣ �Է�

		switch (num) //switch�� num���� ���� ����
		{
		case 1:
			Menu1(); //1�Է������� Menu1�Լ��� ����
			break; 
		case 2:
			Menu2(); //2�Է������� Menu2�Լ��� ����
			break; 
		case 3:
			Menu3(); //3�Է������� Menu3�Լ��� ����
			break;
		case 4:
			Menu4(); //4�Է������� Menu4�Լ��� ����
			return 0; //����
		default:
			printf("1~4 �Է��ϼ���\n"); //�ٸ� ���ڸ� �Է������� ���
			break;
		}
	}
	return 0; //0�� ��ȯ
} //main �Լ��� ��