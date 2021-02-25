#include <iostream>
using namespace std;

void Function_G(int *bitstream, int count) //reverse the bitstream.
{
	int temp;
	for (int i = 0; i < count / 2; i++)
	{
		temp = bitstream[i];
		bitstream[i] = bitstream[count - i - 1];
		bitstream[count - i - 1] = temp;
	}
}// Function_G

void Function_F(int bitstream[], int count)  //bitwise NOT.
{
	for (int i = 0; i < count; i++)
	{
		if (bitstream[i] == 0)
		{
			bitstream[i] = 1;
		}
		else
		{
			bitstream[i] = 0;
		}
	}
}// Function_F

int Decimal_change(int bitstream[], int count)
{
	unsigned int a = 1;
	int dec = 0;
	for (int i = count-1; i >=0; i--)
	{
		if (bitstream[i] == 1)
		{
			dec = dec + a;
		}
		a = a * 2;
	}
	return dec;
} // change from decimal to binary


int main()
{
	int N;
	int check = 1;

	int temp = 0;
	int count = 0;

	unsigned int Bitstream;
	int arr_bitstream[64] = {};

	cout << "Input N: ";
	cin >> N;

	while (check == 1)
	{
		check = 0;
		count = 0;
		cout << endl << "Input Bitstream: ";
		cin >> Bitstream;

		for (int i = 0; Bitstream >= 1; i++)
		{
			if (Bitstream % 10 == 1)
				arr_bitstream[i] = 1;

			else if (Bitstream % 10 == 0)
				arr_bitstream[i] = 0;

			else
				check = 1;

			Bitstream = Bitstream / 10;
			count++;
		}
		if (check == 1)
		{
			cout << "please input binary number";
		}//no binary
	}// put a decimal number(Bitstream) in array.

	Function_G(arr_bitstream, count); //reverse

	cout << endl;

	for (int i = 1; i < N + 1; i++)
	{
		if (i % 2 == 1) // N is odd 
		{
			Function_G(arr_bitstream, count);
			Function_F(arr_bitstream, count);
			arr_bitstream[count] = 1;	//"+ 1"
		}
		else if (i % 2 == 0)// N is even
		{
			Function_G(arr_bitstream, count);
			Function_F(arr_bitstream, count);
			arr_bitstream[count] = 0;//"+ 0"
		}
		count++;

		cout << i << ":";
		for (int j = 0; j < count; j++)
		{
			cout << arr_bitstream[j];
			if (j == 31) //print 32bit
				break;
		}
		int decimal = Decimal_change(arr_bitstream, count); //return decimal

		cout << "\n\n" << decimal << endl;

		cout << endl;
	}

	cout << endl;

	return 0;

}