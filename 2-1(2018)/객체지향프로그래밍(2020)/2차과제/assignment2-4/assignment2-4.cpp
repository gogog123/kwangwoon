#include <iostream>
using namespace std;

int str_length, search_length, change_length;
int find_str;

int Str_Length(char *str)
{
	int i = 0;
	while (1)
	{
		if (str[i] == NULL)
			break;
		i++;
	}
	return i;
} //string length output function

int Find_str(char* str, char* strSearch)
{
	int i = 0;
	int j = 0;
	int i_copy=0;

	while (1)
	{
		if (str[i] == strSearch[j])
		{
			i_copy = i;
			for (int k = 0; k < search_length; k++)
			{
				if (str[i_copy] == strSearch[j])
				{
					i_copy++;
					j++;
				}
				else
				{
					j = 0; //reset , different string
					break;
				}
			}
		}

		i++;

		if (j == search_length)
		{
			find_str = i_copy - j;
			break;
		} //string found 

		else if (i == str_length)
		{
			find_str = -1;
			break;
		} //string not found
	}
	return 0;
}//find string 

int Change_str(char *str, char* strChange)
{
	int distance = change_length - search_length;
	int a = find_str + search_length;
	char temp_arr[100];
	
	int i = 0;
	while(str[a + i] != NULL)
	{
		temp_arr[i] = str[a+i];
		i++;
	} // save after string to change
	temp_arr[i] = '\0'; //end

	for (int i = 0; i < change_length + 1; i++)
	{
		str[find_str+i] = strChange[i];
	} // insert string after chanege
	
	i = 0;
	while (1)
	{
		str[find_str + change_length + i] = temp_arr[i];
		i++;
		if (temp_arr[i] == '\0')
			break;
	} // insert string after string to change

	return 0; 
}

char* my_strstr(char* str, char* strSearch, char* strChange)
{

	Find_str(str, strSearch);

	cout << "\n변경된 결과는 다음과 같습니다.\n\n";

	if (find_str == -1)
	{
		cout << "일치하는 문자열이 없습니다.\n";
	}
	else
	{
		Change_str(str, strChange);
		str[str_length - search_length + change_length] = '\0';
		cout << "변경된 문자열: \n";
		puts(str);
	}
	return 0;
}//function with changing a specific string

int main()
{
	char str[100];
	char strSearch[100];
	char strChange[100];

	cout << "원본 문자열을 입력하세요." << endl;
	cin.getline(str, 100); //input original string

	cout << "\n변경 전 문자열을 입력하세요." << endl;
	cin.getline(strSearch, 100); //input string before change

	cout << "\n변경 후 문자열을 입력하세요." << endl;
	cin.getline(strChange, 100); //input string after change
	
	str_length = Str_Length(str);
	search_length = Str_Length(strSearch);
	change_length = Str_Length(strChange);

	
	my_strstr(str, strSearch, strChange);


	return 0;
}