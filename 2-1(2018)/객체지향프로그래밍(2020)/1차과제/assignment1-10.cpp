#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Hit(int user_number[4], int random_number[4], int* hit)
{
	*hit = 0;
	for (int i = 0; i < 4; i++)
	{
		if (random_number[i] == user_number[i])
			*hit += 1;
	}
} //Get hit

void Blow(int user_number[4], int random_number[4], int* blow)
{
	*blow = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i != j && random_number[i] == user_number[j])
				*blow += 1;
		}
	}
}//Get blow

int main(void)
{
	int random_number[4] = { 0, };
	int user_number[4];
	int input_number;
	int hit = 0, blow = 0;

	srand(time(NULL));
	cout << "Random numbers: ";
	for (int i = 0; i < 4; i++)
	{
		random_number[i] = rand() % 10; //0~9 random number
		for (int j = 0; j < i; j++)
		{
			if (random_number[i] == random_number[j])
			{
				random_number[i] = rand() % 10;
			}
		} // NO same number
		//cout << random_number[i]; // check
	}
	cout << endl;

	
	for (int i = 0; i < 10; i++) // perform 10games
	{
		int zero = 0;
		cout << "Your number: ";
		cin >> input_number;
		if (input_number > 9999)
			zero = 1;
		for (int j = 3; j >= 0; j--)
		{
			user_number[j] = input_number % 10;
			input_number = input_number / 10;
			for (int k = 3; k > j; k--)
			{
				if (user_number[j] == user_number[k])
				{
					zero = 1;
					break;
				}
			}
		}
		if (zero == 1)
		{
			cout << "Please input again\n"; //print again input.
			i--;
			continue;
		}// NO same number, over 9999.

		Hit(random_number, user_number, &hit);
		Blow(random_number, user_number, &blow);

		cout << ">> HIT: " << hit << ",BLOW: " << blow << endl;

		if (hit == 4)
		{
			cout << "Win" << endl;
			break;
		} //Win
	}

	if (hit != 4)
	{
		cout << "Lose" << endl;
	} //Lose
	
	return 0;
}