#include <iostream>
#include <iomanip> //sort
using namespace std;

int main()
{
	int row, col;
	int array_2D[10][10] = { 0, };
	
	while (1)
	{
		cout << "Please input 2D array size: ";
		cin >> row >> col;
		if (row >= 1 && row <= 10 && col >= 1 && col <= 10)
			break;

		cout << "Please input 1~10\n\n"; //when wrong input
	}

	int i = 0;
	int j = -1;
	int row_copy = row;
	int col_copy = col;
	int way = 0;

	for (int k = 1; k <= row * col; k++)
	{
		if (way == 0) // way '→'
		{
			j++;
			if (j == col_copy-1)
			{
				way++;
				col_copy--;
			}
		}
		else if (way == 1) // way '↓'
		{
			i++;
			if (i == row_copy-1)
			{
				way++;
				row_copy--;
			}
		}
		else if (way == 2) // way '←'
		{
			j--;
			if (j == col-col_copy-1)
				way++;
		}
		else // way '↑'
		{
			i--;
			if (i == row - row_copy)
				way = 0;
		}
		
		array_2D[i][j] = k;

	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << right << setw(5) << array_2D[i][j];
		}
		cout << endl;
	} //print array_2D

	return 0;
}