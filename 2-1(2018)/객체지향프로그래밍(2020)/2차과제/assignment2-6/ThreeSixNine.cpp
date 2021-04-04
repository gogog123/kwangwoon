#include "ThreeSixNine.h"
#include <iostream>
#include <iomanip>
using namespace std;

ThreeSixNine::ThreeSixNine()
{
}

ThreeSixNine::~ThreeSixNine()
{
}

int ThreeSixNine::print369(int num)
{
	for (int i = 1; i <= num; i++)
	{
		if (i < 10)
		{
			if (i % 3 == 0)
			{
				cout << left << setw(7) << "!";
			}
			else 
				cout << left << setw(7) << i;
		}//digits of 1

		else if (i < 100)
		{
			int a = i / 10;
			int b = i % 10;
			if (a % 3 == 0 && (b % 3 == 0 && b != 0))
				cout << left << setw(7) << "!!";
			else if (a % 3 == 0 || (b % 3 == 0 && b != 0))
				cout << left << setw(7) << "!";
			else 
				cout << left << setw(7) << i;
		}//digits of 10

		else
		{
			int a = i / 100; // 100 digit
			int b = (i % 100) / 10; // 10 digit
			int c = i % 10; //1 digit
			if (a % 3 == 0 && (b % 3 == 0 && b != 0) && (c % 3 == 0 && c != 0))
				cout << left << setw(7) << "!!!"; 
			else if ((a % 3 == 0 || (b % 3 == 0 && b != 0)) &&
			     	(a % 3 == 0 || (c % 3 == 0 && c != 0)) &&
				    ((b % 3 == 0 && b != 0) || (c % 3 == 0 && c != 0))) //include 2 out of 3,6,9 
				cout << left << setw(7) << "!!";
			else if (a % 3 == 0 || (b % 3 == 0 && b != 0) || (c % 3 == 0 && c != 0))
				cout << left << setw(7) << "!"; //included 1 of 3,6,9 
			else
				cout << left << setw(7) << i;
		}//digits of 100

		if (i % 10 == 0)
			cout << endl;
		//line break;

	}
	return 0;
}
