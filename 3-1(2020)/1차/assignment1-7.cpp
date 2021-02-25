#include <iostream>
using namespace std;

int main()
{
	int p1_x, p1_y;
	int p2_x, p2_y;
	int p3_x, p3_y;

	while (1)
	{
		cout << "P1: ";
		cin >> p1_x >> p1_y;
		cout << "P2: ";
		cin >> p2_x >> p2_y;
		cout << "P3: ";
		cin >> p3_x >> p3_y;
		if ((p1_x != p2_x || p1_y != p2_y)
			&& (p1_x != p3_x || p1_y != p3_y)
			&& (p2_x != p3_x || p2_y != p3_y))
			break; //exception
		cout << "Please input different number\n\n";
	}

	int p1_to_p2_x = p2_x - p1_x; //AB vector x
	int p1_to_p2_y = p2_y - p1_y; //AB vector y
	int p1_to_p3_x = p3_x - p1_x; //AC vector x
	int p1_to_p3_y = p3_y - p1_y; //AC vector y
	
	int check1 = p1_to_p2_x * p1_to_p3_y;
	int check2 = p1_to_p3_x * p1_to_p2_y;
	int cross_product = (p1_to_p2_x * p1_to_p3_y) - (p1_to_p3_x * p1_to_p2_y);
	
	//value cross product

	if (cross_product < 0) // when negative clockwise
		cout << "Clockwise" << endl;
	else if (cross_product > 0) // when positive counter clockwise
		cout << "Counter-Clockwise" << endl;
	else // when zero straight
		cout << "Straight" << endl;

	return 0;
}