#include<stdio.h> //�ش����� ����
int setID() //�Լ� setID ����
{
	int id; //id ���� ����
	printf("�й� �Է� : "); //�й� ���
	scanf("%d", &id); //�й� �Է�
	return id; //id ��ȯ
}
void printTimeTable(mID) //���������ϴ� �Լ� printTImeTable�Լ� ����
{
	printf("\n============= �ð�ǥ (�й� : %d) ============\n", mID); 
	printf("\t%-20s%-12s%-12s\n", "�������", "���ǽð�", "���ǽ�");
	printf("=====================================================\n");
	printf("\t%-20s%-12s%-12s\n", "C���α׷���", "��6��5", "��204");
	printf("\t%-20s%-12s%-12s\n", "������α׷���", "��01", "��514");
	printf("\n"); //�ð�ǥ ���
}
int main() //main �Լ� ����
{
	int id = 0, sel = 0; // ���� ����
	printf("1. �й� �Է�\n");
	printf("2. �ð�ǥ Ȯ��\n");
	printf("3. ����\n"); 
	//�ð�ǥ���
	
	while (1) 
	{
		printf(">> select : "); //sel�� ���
		scanf("%d", &sel); //sel�� �Է�


		switch (sel) //switch�� Ȱ��
		{
		case 1:
			id=setID(); //setID �Լ� ���
			break;
		case 2:
			if (id != 0) //id�� 0�� �ƴҶ�
				printTimeTable(); //printTimeTable �Լ� ���
			else //������ �϶�
				printf("�й��� ���� �Է��ϼ���.\n"); //���
			break;
		case 3:
			return 0; //switch�� ���� ����
		} 
	}
	return 0; //0�� ��ȯ
}//main �Լ��� ��