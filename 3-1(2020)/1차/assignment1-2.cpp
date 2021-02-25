#include<iostream>
#include<cmath> //use root
using namespace std;

int main()
{
	int n;
	int  num = 0;
	cout << "Enter the n: ";
	cin >> n; // user command

	cout << "\n";

	int* prime_number = new int[n]; 
	//initializing dynamically allocated arrys

	for (int i = 0; i < n; i++)
	{
		prime_number[i] = i;
	}//prime_number[0] = 0 ...

	for (int i = 2; i < sqrt(n); i++) // run to 2~root(n) 
	{
		for (int j = 2; j < n; j++)
		{ 
			if (j != i && prime_number[j] % i == 0) // multiples of p = 0
				prime_number[j] = 0;
		}
	}

	for (int i = 2; i < n; i++)
	{
		if (prime_number[i] == i) //when i != 0
		{
			cout << i << " ";
			num++;
		}
	}

	cout << "\n\n" << "The number of Prime numbers: " << num << endl;
	//print

	return 0;
}