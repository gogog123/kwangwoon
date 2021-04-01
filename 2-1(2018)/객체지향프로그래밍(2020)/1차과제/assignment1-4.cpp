#include <iostream>
using namespace std;

int main()
{
	int i;
	int len;
	char str[128];
	char temp;

	cout << "Enter the string : ";
	cin.getline(str, 128);

	for (len = 0; str[len] != '\0'; len++); // len = string size

	for (int i = 0; i < len ; i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		//convert lowercase letters to uppercase letters
		else if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		//convert uppercase letters to lowercase letters
	}

	for (int i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	} // string reverse

	cout << "Result : " << str << endl;
	return 0;
}