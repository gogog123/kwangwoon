#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int decode[7000] = { 0, };


int Change_decimal(char binary[])
{
	int decimal = 0;
	int plus = 1;

	for (int i = 7; i >= 0; i--)
	{
		if (binary[i] == '1')
			decimal = decimal + plus;
		plus = plus * 2;
	}

	return decimal;
}// 2진수를 10진수로 변환.

int main ()
{
	int a = 0;
	int num = 0;
	char str[30] = { 0, };
	char change_num[8] = { 0, };
	int len_code[128] = { 0, };
	char huffman_code[128][20] = { 0, };

	ifstream fin_table("Huffman_table.txt");

	if ((!fin_table.is_open()))
	{
		cout << "No file!" << endl;
		return 0;
	}

	while (1)
	{
		if (!fin_table.eof())
		{
			fin_table.getline(str, 100); //한줄씩 read

			for (int i = 0; i < 8; i++) //8bit
			{
				change_num[i] = str[i];
			}
			a = Change_decimal(change_num); //ascii 문자 read.

			for (int i = 0; i < 8; i++) //8bit
			{
				change_num[i] = str[8 + i];
			}
			len_code[a] = Change_decimal(change_num); //길이 read.

			for (int i = 0; i < 20; i++) 
			{
				if (str[16 + i] == NULL)
					break;
				huffman_code[a][i] = str[16 + i]; //codeword read.
				printf("%c", huffman_code[a][i]);
			}
			cout << endl;
		}

		else
			break;
	}


	ifstream fin_code("Huffman_code.txt");
	char decode = 0;

	while (1)
	{
		if (!fin_code.eof())
		{ 
			fin_code.get(decode); //한글자씩 읽어오기
			printf("%c", decode);
		}
		else
			break;
	}


	fin_table.close();
	fin_code.close();

	return 0;
}