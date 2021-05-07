#include <iostream>
#include <fstream> // file input/output
using namespace std;

int k;
char str_input[10000] = { 0, };
int huffman_tree[300] = { 0, };
int encode[128][20];
int ascii[128];
int len_code[128]; //전역 변수 선언
int adap_len_code[128][128] = { 0, };
int adaptive_code[128][128][20] = { 0, };

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
	} //사용된 문자들 정렬.

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
	}// 사용된 문자들 빈도수 대로 정렬.
}


void Add_Sort(int add_sort_freq[128], int add_sort_ch[128], int num)
{
	int add_freq[128] = { 0, }; // 정렬된 빈도수
	int add_ch[128] = { 0, }; //정렬된 문자
	int plus = 1;

	for (int i = 0; i < num - 1; i++)
	{
		int a = num;
		add_freq[i] = add_sort_freq[0] + add_sort_freq[1];
		//가장작은 빈도수 두개 선택.
		huffman_tree[add_sort_ch[0]] = -plus; //둘 중 더 작은 수.
		huffman_tree[add_sort_ch[1]] = plus;  //둘 중 더 큰 수 .

		for (int j = 0; j < num - 2 - i; j++)
		{
			add_sort_freq[j] = add_sort_freq[j + 2];
			add_sort_ch[j] = add_sort_ch[j + 2];
		} //2개 값을 뺀만큼 앞으로 당겨줌.
		add_sort_freq[num - i - 2] = 0; add_sort_ch[num - i - 2] = 0;
		add_sort_freq[num - i - 1] = 0; add_sort_ch[num - i - 1] = 0;
		//나머지 reset.


		for (int k = 0; k < num - 2; k++)
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
				}// 더한 빈도수를 넣을 공간을 비워두고 한칸씩 옆으로 채워줌.

				add_sort_freq[k] = add_freq[i]; // 더한 빈도수를 알맞은 위치에 삽입
				add_sort_ch[k] = plus + 200; // 더한 tree의 node 생성
				break;
			}
		}
		if (add_freq[i] > add_sort_freq[num - i - 3])
		{
			add_sort_freq[num - i - 2] = add_freq[i];
			add_sort_ch[num - i - 2] = plus + 200;
		}//더한 빈도수가 가장 큰 빈도수보다 큰 경우

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
	int i = 0;
	if (num == 1)
	{
		for (int i = 0; i < 128; i++)
		{
			if (ascii[i] != NULL)
			{
				len[i] = 1;
				code[i][0] = 0;
			}
		}
	}

	else {
		for (int i = 0; i < 128; i++)
		{
			int a = i;
			int binary = 1;

			if (ascii[i] != NULL)
			{
				int j = 0;
				while (1)
				{
					int t = huffman_tree[a]; //문자의 위치
					if (t < 0)
					{
						t = -t;
						code[i][j] = 0; // 트리에서 왼쪽 부분
						a = t + 200; //부모 노드로 올라감.
					}
					else
					{
						code[i][j] = 1; // 트리에서 오른쪽 부분
						a = t + 200; //부모 노드로 올라감.
					}
					j++;
					if (a == 200 + num - 1) // 제일 위의 노드.
						break;
				}
				len[i] = j; // codeword 길이.
			}
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
}//10진수를 2진수로 변환.

/////////////////////main함수 시작/////////////////
int main()
{
	int count = 0;
	char str[100] = { 0, };
	int sort_freq[128] = { 0, };
	int sort_ch[128] = { 0, };
	int change_num[8] = { 0, };

	ifstream fin("training_input.txt");
	ofstream fout("Huffman_code.txt");
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
			fin.getline(str, 100); //한줄씩 읽어오기
			for (int i = 0; i < 100; i++)
			{
				if (str[i] == NULL)
				{
					ascii[10]++; //개행
					str_input[k] = 10;
					//		printf("%c", str_input[k]);
					k++;
					break;
				}
				ascii[str[i]]++; //빈도수 1씩 증가
				str_input[k] = str[i];
				//		printf("%c", str_input[k]);
				k++;
			}
		}
		else
			break;
	}
	ascii['+'] ++; // 마지막 EOD 표시


	Sort(sort_freq, sort_ch, ascii, &count); //빈도수 정렬

	Add_Sort(sort_freq, sort_ch, count); // tree 생성

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
		Change_binary(i, change_num); //문자 8bit 2진수로 변경

		for (int j = 0; j < 8; j++)
		{
			fout_table << change_num[j]; //table 저장
		}

		Change_binary(len_code[i], change_num); //코드길이 8bit 2진수로 변경
		for (int j = 0; j < 8; j++)
		{
			fout_table << change_num[j]; //table 저장
		}

		for (int j = len_code[i] - 1; j >= 0; j--)
		{
			fout_table << encode[i][j]; //table 저장
		}
		fout_table << "\n";
	}
	str_input[k] = '+'; //End of data


//////////////////////////////////////adaptive Huffman coding////////////////////////////////////

	int adap[128][128] = { 0, };
	
	for (int i = 0; i < 128; i++)
	{
		if (ascii[i] == NULL)
			continue;
		int j = 0;
		while (1)
		{
			if (str_input[j] == NULL)
				break;
			if (i == str_input[j])
				adap[i][str_input[j + 1]]++;
			j++;
		}
	} //다음 알파벳의 빈도수.

	int adap_sort_freq[128] = { 0, };
	int adap_sort_ch[128] = { 0, };

	for (int i = 0; i < 128; i++)
	{
		if (ascii[i] == NULL)
			continue;

		Sort(adap_sort_freq, adap_sort_ch, adap[i], &count); //빈도수 정렬

		Add_Sort(adap_sort_freq, adap_sort_ch, count); // tree 생성

		Huffman_code(adap[i], adaptive_code[i], adap_len_code[i], count); //codeword

		printf("table : '%c'\n", i);
		for (int j = 0; j < 128; j++)
		{
			if (adap[i][j] == NULL)
				continue;
			printf("'%c'        %d      ", j, adap[i][j]);

			for (int k = adap_len_code[i][j] - 1; k >= 0; k--)
			{
				printf("%d", adaptive_code[i][j][k]);
			}
			cout << endl;
		}
		cout << endl;
	} //adaptive한 table 생성


	for (int i = 0; i < k-1; i++)
	{
		int a = str_input[i];
		int b = str_input[i + 1];

		if (i == 0)
		{
			for (int j = len_code[a] - 1; j >= 0; j--)
			{
				//printf("%d", encode[a][j]);
				fout << encode[a][j];
			}
		}

		for (int j = adap_len_code[a][b] - 1; j >= 0; j--)
		{
			//printf("%d", adaptive_code[a][b][j]);
			fout << adaptive_code[a][b][j];
		}
	}

	ifstream fin_test1("test_input1.txt");
	ifstream fin_test2("test_input2.txt");
	ifstream fin_test3("test_input3.txt");
	//file read

	if ((!fin_test1.is_open()) || !fin_test2.is_open() || !fin_test3.is_open())
	{
		cout << "No file!" << endl;
		return 0;
	}

	ofstream fout_test1("test_input1_code.txt");
	ofstream fout_test2("test_input2_code.txt");
	ofstream fout_test3("test_input3_code.txt");

	char str_adap[100];

	while (1)
	{
		if (!fin_test1.eof())
		{
			fin_test1.getline(str_adap, 100);
			for (int i = 0; i < 100; i++)
			{
				if (str_adap[i] == NULL)
					break;

				int a = str_adap[i];
				int b = str_adap[i + 1];
				if (i == 0)
				{
					for (int j = len_code[a] - 1; j >= 0; j--)
					{
						//printf("%d", encode[a][j]);
						fout_test1 << encode[a][j];
					}
				} // 가장 첫번째 문자.
				if (adap_len_code[a][b] == 0)
				{
					for (int j = len_code[b] - 1; j >= 0; j--)
					{
						//printf("%d", encode[a][j]);
						fout_test1 << encode[b][j];
					}
					continue;
				}// training된 알파벳이 없을 때
				for (int j = adap_len_code[a][b] - 1; j >= 0; j--)
				{
				//	printf("%d", adaptive_code[a][b][j]);
					fout_test1 << adaptive_code[a][b][j];
				} // traning된 알파벳이 존재할 때.

			}
		}
		else
			break;
	}


	while (1)
	{
		if (!fin_test2.eof())
		{
			fin_test2.getline(str_adap, 100);
			for (int i = 0; i < 100; i++)
			{
				if (str_adap[i] == NULL)
					break;

				int a = str_adap[i];
				int b = str_adap[i + 1];
				if (i == 0)
				{
					for (int j = len_code[a] - 1; j >= 0; j--)
					{
						//printf("%d", encode[a][j]);
						fout_test2 << encode[a][j];
					}
				} // 가장 첫번째 문자.
				if (adap_len_code[a][b] == 0)
				{
					for (int j = len_code[b] - 1; j >= 0; j--)
					{
						//printf("%d", encode[a][j]);
						fout_test2 << encode[b][j];
					}
					continue;
				}// training된 알파벳이 없을 때
				for (int j = adap_len_code[a][b] - 1; j >= 0; j--)
				{
					//printf("%d", adaptive_code[a][b][j]);
					fout_test2 << adaptive_code[a][b][j];
				} // traning된 알파벳이 존재할 때.

			}
		}
		else
			break;
	}


	while (1)
	{
		if (!fin_test3.eof())
		{
			fin_test3.getline(str_adap, 100);
			for (int i = 0; i < 100; i++)
			{
				if (str_adap[i] == NULL)
					break;

				int a = str_adap[i];
				int b = str_adap[i + 1];
				if (i == 0)
				{
					for (int j = len_code[a] - 1; j >= 0; j--)
					{
						//printf("%d", encode[a][j]);
						fout_test3 << encode[a][j];
					}
				} // 가장 첫번째 문자.
				if (adap_len_code[a][b] == 0)
				{
					for (int j = len_code[b] - 1; j >= 0; j--)
					{
						//printf("%d", encode[a][j]);
						fout_test3 << encode[b][j];
					}
					continue;
				}// training된 알파벳이 없을 때
				for (int j = adap_len_code[a][b] - 1; j >= 0; j--)
				{
					//printf("%d", adaptive_code[a][b][j]);
					fout_test3 << adaptive_code[a][b][j];
				} // traning된 알파벳이 존재할 때.

			}
		}
		else
			break;
	}


	fin.close();
	fout.close();
	fout_table.close();
	fin_test1.close();
	fin_test2.close();
	fin_test3.close();
	fout_test1.close();
	fout_test2.close();
	fout_test3.close();

	return 0;
}
