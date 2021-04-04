#include <iostream>
#include "ThreeSixNine.h"
using namespace std;
int main()
{
	int num;
	ThreeSixNine game;
	
	while (1)
	{
		cout << "input your number" << endl;
		cin >> num;
		if (num >= 1 && num <= 300)
			break;
		cout << "wrong input\n\n";
	} //exception


	game.print369(num); //print369
	cout << endl;

	return 0;
}