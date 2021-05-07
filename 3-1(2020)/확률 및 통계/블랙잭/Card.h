#pragma once
#include <iostream>
using namespace std;

class Card
{
private:
	int value;
	string rank;
	string suit;

public:
	void set_rank(string r) { rank = r; }
	void set_suit(string s) { suit = s; }
	void set_value(int v) { value = v; }

	string get_rank() { return rank; }
	string get_suit() { return suit; }
	int get_value() { return value; }

	void display() { cout << value << " - " << rank << " of " << suit << endl; }

};

