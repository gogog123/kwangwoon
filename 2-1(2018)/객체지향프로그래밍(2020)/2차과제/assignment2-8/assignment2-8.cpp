#include <iostream>
#include <cstring>
#include "Exchange.h"
using namespace std;

int main()
{
	double price;
	char restart;
	char before_country[5] = { 0, };
	char after_country[5] = { 0, };
	char to[5] = { 0, };


	while (1)
	{
		int a = 0;
		system("cls");
		cout << "★Currency Converter★" << endl;
		cout << "e.g [Price] KRW to USD\n\n";

		cin >> price >> before_country >> to >> after_country;

		if (strcmp(to, "to") != 0)
		{
			cout << "input error" << endl;
			return 0;
		} // wrong input 'to'

		ToKRW X;
		price = X.Con_KRW(price, before_country); // convert to KRW

		if (strcmp(after_country, "USD") == 0) 
		{
			ToUSD Y;
			Y.Print(Y.Con_USD(price), "USD"); // convert to USD
		}
		else if (strcmp(after_country, "JPY") == 0)
		{
			ToJPY Y;
			Y.Print(Y.Con_JPY(price), "JPY"); // convert to JPY
		}
		else if (strcmp(after_country, "EUR") == 0)
		{
			ToEUR Y;
			Y.Print(Y.Con_EUR(price), "EUR"); // convert to EUR
		}
		else if (strcmp(after_country, "CNY") == 0)
		{
			ToCNY Y;
			Y.Print(Y.Con_CNY(price), "CNY"); // convert to CNY
		}
		else if (strcmp(after_country, "KRW") == 0)
		{
			X.Print(price, "KRW"); // convert to KRW
		}
		else
		{
			cout << "input error" << endl;
			return 0;
		}

		if (price == 0)
		{
			cout << "input error" << endl;
			return 0;
		}



		while (1)
		{
			if (a == 1) { break; }
			cout << "Would you like to continue? (Y/N)" << endl;
			cin >> restart;

			if (restart == 'n')
			{
				cout << "Bye!" << endl; //end
				return 0;
			}

			else if (restart == 'y')     a = 1; //restrat
			else                         cout << "input y or n\n"; 
		}
	}

	return 0;
}