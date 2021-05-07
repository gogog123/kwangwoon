#include <iostream>
#include <fstream> // file input/output
#include "encode.h"
using namespace std;

int k;
char str_input[10000] = { 0, };
int huffman_tree[300] = { 0, };
int encode[128][20];
int ascii[128];	
int len_code[128]; //���� ���� ����

void Sort(int sort_freq[128], int sort_ch[128], int ascii[], int* num)
{
	*num = 0;
	for (int i = 0; i < 128; i++)
	{
		if (ascii[i] != NULL)
		{
			sort_freq[*num] = ascii[i];
			sort_ch[*num] = i;
			(*num)++;
		}
	} //���� ���ڵ� ����.

	for (int i = 0; i < *num; i++)
	{
		for (int j = (*num) - 1; j >= i; j--)
		{
			if (sort_freq[j] < sort_freq[j - 1])
			{
				int temp = sort_freq[j];
				sort_freq[j] = sort_freq[j - 1];
				sort_freq[j - 1] = temp;
				int temp_ch = sort_ch[j];
				sort_ch[j] = sort_ch[j - 1];
				sort_ch[j - 1] = temp_ch;
			}
		}
	}// ���� ���ڵ� �󵵼� ��� ����.
}


void Add_Sort(int add_sort_freq[128], int add_sort_ch[128], int num)
{
	int add_freq[128] = { 0, }; // ���ĵ� �󵵼�
	int add_ch[128] = { 0, }; //���ĵ� ����
	int plus = 1;

	for (int i = 0; i < num-1; i++)
	{
		int a = num;
		add_freq[i] = add_sort_freq[0] + add_sort_freq[1];
		//�������� �󵵼� �ΰ� ����.
		huffman_tree[add_sort_ch[0]] = -plus; //�� �� �� ���� ��.
		huffman_tree[add_sort_ch[1]] = plus;  //�� �� �� ū �� .

		for (int j = 0; j < num - 2 - i; j++)
		{
			add_sort_freq[j] = add_sort_freq[j + 2];
			add_sort_ch[j] = add_sort_ch[j + 2];
		} //2�� ���� ����ŭ ������ �����.
		add_sort_freq[num - i - 2] = 0; add_sort_ch[num - i - 2] = 0;
		add_sort_freq[num - i - 1] = 0; add_sort_ch[num - i - 1] = 0;
		//������ reset.

	
		for (int k = 0; k < num-2; k++)
		{
			if (add_freq[i] <= add_sort_freq[k])
			{
				while (1)
				{
					add_sort_freq[a - 2] = add_sort_freq[a - 3];
					add_sort_ch[a - 2] = add_sort_ch[a - 3];
					a--;
					if ((a - 2) == k)
						break;
				}// ���� �󵵼��� ���� ������ ����ΰ� ��ĭ�� ������ ä����.

				add_sort_freq[k] = add_freq[i]; // ���� �󵵼��� �˸��� ��ġ�� ����
				add_sort_ch[k] = plus + 200; // ���� tree�� node ����
				break;
			}
		}
		if (add_freq[i] > add_sort_freq[num - i - 3])
		{
			add_sort_freq[num - i - 2] = add_freq[i];
			add_sort_ch[num - i - 2] = plus + 200;
		}//���� �󵵼��� ���� ū �󵵼����� ū ���

		plus++;

		for (int x = 0; x < num - i - 1; x++)
		{
		//	printf("%d %d   ", add_sort_freq[x], add_sort_ch[x]);
		}
	//	cout << endl;
	}
}

void Huffman_code(int ascii[], int code[][20], int len[], int num)
{
	for (int i = 0; i < 128; i++)
	{
		int a = i;
		int binary = 1;

		if (ascii[i] != NULL)
		{
			int j = 0;
			while (1)
			{
				int t = huffman_tree[a]; //������ ��ġ
				if (t < 0)
				{
					t = -t;
					code[i][j] = 0; // Ʈ������ ���� �κ�
					a = t + 200; //�θ� ���� �ö�.
				}
				else
				{
					code[i][j] = 1; // Ʈ������ ������ �κ�
					a = t + 200; //�θ� ���� �ö�.
				}
				j++;
				if (a == 200 + num - 1) // ���� ���� ���.
					break;
			}
			len[i] = j; // codeword ����.
		}
	}
}
void Change_binary(int num, int change_num[])
{
	for (int i = 7; i >= 0; i--)
	{
		if (num < 2)
			change_num[i] = num;
		else {
			change_num[i] = num % 2;
		}
		num = num / 2;
	}
}//10������ 2������ ��ȯ.

int main()
{
	int count = 0;
	char str[100] = { 0, };
	int sort_freq[128] = { 0, };
	int sort_ch[128] = { 0, };
	int change_num[8] = { 0, };

	ifstream fin("input.txt");
	ofstream fout("Huffman_code.hbs");
	ofstream fout_table("Huffman_table.txt");

	if ((!fin.is_open()))
	{
		cout << "No file!" << endl;
		return 0;
	}

	int k = 0;
	while (1)
	{
		if (!fin.eof())
		{
			fin.getline(str, 100); //���پ� �о����
			for (int i = 0; i < 100; i++)
			{
				if (str[i] == NULL)
				{
					ascii[10]++; //����
					str_input[k] = 10;
			//		printf("%c", str_input[k]);
					k++;
					break;
				}
				ascii[str[i]]++; //�󵵼� 1�� ����
				str_input[k] = str[i];
		//		printf("%c", str_input[k]);
				k++;
			}
		}
		else
			break;
	}
	ascii['+'] ++; // ������ EOD ǥ��


	Sort(sort_freq, sort_ch, ascii, &count); //�󵵼� ����

	Add_Sort(sort_freq, sort_ch, count); // tree ����

	Huffman_code(ascii, encode, len_code, count); //codeword
	
	for (int i = 0; i < 128; i++)
	{
		if (ascii[i] == NULL)
			continue;
		printf("'%c'      %d           ", i, ascii[i]);
		for (int j = len_code[i] - 1; j >= 0; j--)
		{
			printf("%d", encode[i][j]);
		}
		cout << endl;
	} // huffman_table c print

	for (int i = 0; i < 128; i++)
	{
		if (ascii[i] == NULL)
			continue;
		Change_binary(i, change_num); //���� 8bit 2������ ����

		for (int j = 0; j < 8; j++)
		{
			fout_table << change_num[j]; //table ����
		}

		Change_binary(len_code[i], change_num); //�ڵ���� 8bit 2������ ����
		for (int j = 0; j < 8; j++)
		{
			fout_table << change_num[j]; //table ����
		}

		for (int j = len_code[i] - 1; j >= 0; j--)
		{
			fout_table << encode[i][j]; //table ����
		}
		fout_table << "\n";
	}


	str_input[k] = '+'; //End of data

	for (int i = 0; i <= k; i++)
	{
		int a = str_input[i];
		for (int j = len_code[a] - 1; j >= 0; j--)
		{
		//	printf("%d", encode[a][j]);
			fout << encode[a][j];
		}
	}
	
	
	fin.close();
	fout.close();
	fout_table.close();

	return 0;
}
