#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <iomanip> // setw() function
using namespace std;

int main()
{
	int row, col;
	int matrix[200][200];
	int matrix_arr1[10000];
	int check=0;
	while (1)
	{
		cout << "Enter the row: ";
		cin >> row; // input row
		if (row <= 100 && row >= 0)
			break;
		cout << "Please input row 0~100\n\n";
	}

	while (1)
	{
		cout << "Enter the colunm: ";
		cin >> col; // input colum
		if (col <= 100 && col >= 0)
			break;
		cout << "Please input col 0~100\n\n";
	}

	srand((unsigned int)time(NULL));
	for (int i = 0; i < row * col; i++)
	{
		while (1)
		{
			check = 0;
			matrix_arr1[i] = (rand() % (row * col)); //random numbers ranging from 0~(row*col-1)
			for (int j = 0; j < i; j++)
			{
				if (matrix_arr1[i] == matrix_arr1[j])
					check = 1;
			}
			if (check == 0)
				break; // when, No duplication
		}
		//cout << matrix_arr1[i] << " ";
	}
	cout << endl;

	cout << "Origin Matrix>>>" << endl;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = matrix_arr1[j + i * col];
			cout << right << setw(5) << matrix[i][j]; //rigt set output
		}
		cout << endl;
	}

	cout << endl << "Transpose Matrix >>> " << endl;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << right << setw(5) << matrix[j][i] ; //rigt set output
		}
		cout << endl;
	}
	
	return 0;
}