//�̻����� �߻��Ͽ� ��ǥ���� ���ߴ� �����̴�.

#include <stdio.h> 
#include <conio.h> //gotoxy �Լ�
#include <Windows.h>
#include <stdlib.h>
#include <time.h>  //�ش����� ����

void gotoxy(int x, int y) //
{
	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_rectangle(int row, int col)
{
	gotoxy(1, 1);
	printf("��"); // '��' ���
	for (int i = 2; i < row; i++)
		printf("����");
	printf("��");
	printf("��\n");
	for (int i = 2; i < col; i++)
	{
		printf("��");
		gotoxy(39, i);
		printf("��\n");
	}
	printf("��");
	for (int i = 2; i < row; i++)
		printf("����");
	printf("��");
	printf("��");

	//���� Ʋ ���
}

void game_control(int* hit, int k, int rnd1, int rnd2, int rnd3)
{
	gotoxy(42, 2);
	printf("�����̽�Ű�� ������");
	gotoxy(42, 3);
	printf("�̻����� �߻�˴ϴ�.");
	gotoxy(42, 5);
	printf("Ƚ�� : %d", k);
	gotoxy(42, 6);
	printf("���� : %d", *hit);

	gotoxy(rnd1,2);
	printf("��");
	gotoxy(rnd2, 2);
	printf("��");
	gotoxy(rnd3, 2);
	printf("��");

	int i = 0;
	int j = 0;
	while (1) {
		if (i % 68 + 3 < 37)
		{
			gotoxy(i % 68 + 3, 19);
			printf("  ");
			i += 2;
			printf("��");
			gotoxy(1, 22);
			Sleep(100 - *hit * 5);
			if (kbhit()) //Ű �Է� ���� Ȯ��
				if (getch() == 32) //�����̽��� ������ ��
					break; //����
		}
		if (i % 68 + 3 >= 37)
		{
			gotoxy(72 - (i % 68 + 3), 19);
			printf("��");
			i += 2;
			printf("  ");
			gotoxy(1, 22);
			Sleep(100 - *hit * 5); 
			if (kbhit())
				if (getch() == 32)
					break;
		}
	}// ����� ������ ����

	if (i % 68 + 3 < 37)
		i = i % 68 + 3;
	else
		i = 72 - ((i-2) % 68 + 3);


	for (int a = 18; a > 2; a--) {
		gotoxy(i, a);
		printf("��");
		Sleep(100);
		gotoxy(i, a);
		printf("  ");
	}
	
	if (rnd1 == i) // �� �¾��� ��
	{
		if (*hit == -1) {
			gotoxy(49, 6);
			printf("  ");
		}
		*hit += 1; //����Ƚ�� 1 ����
		gotoxy(i, 2);
		printf("��"); //�� ���
		gotoxy(42, 8);
		printf("�¾ҽ��ϴ�."); // �������� �� ���
		j += 1;
		if (j == 2) {
			*hit += 1;
			j = 1;
		}
		gotoxy(49, 6);
		printf("%d", *hit); //����Ƚ�� ���
	}

	else if (rnd2 == i) // �� �¾��� ��
	{
		if (*hit == -1 || *hit == -2) {
			gotoxy(49, 6);
			printf("  ");
		}
		
		*hit += 2; //����Ƚ�� 2����
		gotoxy(i, 2);
		printf("��");
		gotoxy(42, 8);
		printf("�¾ҽ��ϴ�."); //���������� ���
		j += 1;
		if (j == 2) {
			*hit += 1; //�߰� ����
			j = 1;
		}
		gotoxy(49, 6);
		printf("%d", *hit); //�������
		
	}
	else if (rnd3 == i) { //�� �¾��� ��
		*hit -= 1; //����Ƚ�� 1 ����
		gotoxy(i, 2);
		printf("��");
		gotoxy(42, 8);
		printf("�¾ҽ��ϴ�."); //���������� ���
		gotoxy(49, 6);
		printf("%d", *hit); //����Ƚ�� ���
	}
	else {
		gotoxy(42, 8);
		printf("�����ʾҽ��ϴ�."); //������������ ���
	}
	
}

int main(void)
{
	int i = 0, num1, num2, num3;
	printf("�̻��� ����\n\n����⸦ �̵��ϸ鼭\n��ǥ��<��>�� ���ߴ� �����Դϴ�.\n�̻����� �����̽�Ű�� �߻��մϴ�.\n \n�ƹ�Ű�� ������ �����մϴ�.\n");
	printf("�̻����� �����̽�Ű�� �߻��մϴ�.\n< ��:1�� ��:2�� ��:-1�� >\n\n�ƹ�Ű�� ������ �����մϴ�.\n"); //�ʱ�ȭ�� ���

	for (int k = 0; k < 10; k++)
	{
		if (getch())//�ƹ�Ű�� ��������
			system("cls"); //ȭ�� reset
		srand((unsigned)time(NULL)); //�Ź� �ٸ��� ���
		num1 = (rand() % 18) * 2 + 3;
		num2 = (rand() % 18) * 2 + 3;
		//3~37 ������ ���
		while (1) {
			if (num1 == num2) // ��, �� ��ģ�ٸ�
				num2 = (rand() % 18) * 2 + 3; //�� ��ġ �缳��
			else
				break;
		}
		num3 = (rand() % 18) * 2 + 3;
		while (1) {
			if (num3 == num1 || num3 == num2) // ��, ��, �� ��ģ�ٸ�
				num3 = (rand() % 18) * 2 + 3; //�� ��ġ �缳��
			else
				break;
		}
		draw_rectangle(20, 20); //20x20 �簢�� ���
		game_control(&i, k, num1, num2, num3); // *hit = i(���� Ƚ��)
	}

	gotoxy(42, 5);
	printf("Ƚ�� : %d", 10);
	gotoxy(42, 8);
	printf("���� ����: %d", i);
	gotoxy(1, 22);
	return 0; // 0�� ��ȯ
}//main�Լ� ����