#pragma once
#include <iostream>
using namespace std;

class Buyer
{
private:
	int mask_num = 0;
	int money = 3000; //fix

public:
	Buyer(void) {};
	~Buyer(void) {};

	int Num_mask() { return mask_num; }
	void Purchase(int num) { mask_num = mask_num + num; } // Increase when purchased
	int Change_money() { return money; }
	void After_money(int price, int num)
	{
		money = money - (price * num); // decrease when purchased
	}
};

