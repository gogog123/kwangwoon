#pragma once
#include <iostream>
using namespace std;

class Pharmacist
{
private:
	int mask_num = 5;
	int mask_price = 1000; //fix

public:
	Pharmacist(void) {};
	~Pharmacist(void) {};

	int Num_mask() { return mask_num; } //return mask num
	int Mask_price() { return mask_price; } // return price
	void Purchase(int num) { mask_num = mask_num - num; } //decrease when purchased

};


