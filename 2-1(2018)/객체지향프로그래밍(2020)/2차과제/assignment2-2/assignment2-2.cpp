#include <iostream>
using namespace std;

int main()
{
	int two_d_array[2][3] = { 1,2,3,4,5,6 };
	int* a = &two_d_array[0][0];
	int* b = &two_d_array[1][0];
	int* c = &two_d_array[0][1];
	int* d = &two_d_array[0][2];
	int* e = two_d_array[0];
	int* f = two_d_array[1];
	int* g = *two_d_array;
	int** h = &a;
	int** i = &a;
	int** j = &c;
	//variable declaration

	cout << "First Condition" << endl;
	cout << "a: " << *a << endl;
	cout << "b: " << *b << endl;
	cout << "c: " << *c << endl;
	cout << "d: " << *d << endl;
	cout << "h: " << **h << endl;
	cout << "i: " << **i << endl;
	cout << "j: " << **j << endl;
	cout << endl;
	//values represented
	
	cout << "Second Condition" << endl;
	cout << "1-a: " << a << endl;
	cout << "1-h: " << *h << endl;
	cout << "1-i: " << *i << endl;
	cout << "2-c: " << c << endl;
	cout << "2-j: " << *j << endl;
	cout << "3-d: " << d << endl;
	cout << "4-b: " << b << endl;
	cout << "5-?: " << b + 1 << endl;
	cout << "6-?: " << b + 2 << endl;
	cout << endl;
	//the address of 1 to 6 in "two_d_array" with the pointer 

	cout << "Third Condition" << endl;
	cout << e << endl;
	cout << f << endl;
	cout << g << endl;	
	cout << endl;
	//values of the pointer

	return 0;
}