#include <iostream>
using namespace std;

char arr[2187][2187];

int main(void)
{
	int N;
	int count = 1;
	while (1)
	{
		cout << "Enter the power of 3: ";
		cin >> N;
		int check = N;
		while (1)
		{
			if (check <= 3)
				break;
			check = check / 3;
		}

		if (check % 3 == 0)
			break; //when, multiple of 3

		cout << "please input N is a power of 3\n\n"; 
		//when not a multiple of 3
	}

	int n = N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = '$'; 
		}
	}// Enter $ in all array

	while (1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if ((n / 3)<= i && (n / 3) * 2 > i && n / 3 <= j && (n / 3) * 2 > j)
				{
					int l = 0;
					while (1)
					{
						int k = 0;
						while (1)
						{
							arr[i+l][j + k] = ' ';
							k = k + (N / count);

							if (k > N)
								break;
						}
						l = l + (N / count);
						if (k > N && l > N)
							break;
					}
				}
			}
		}
		n = n / 3;
		count = count * 3;
		if (n == 1)
			break;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}//print

	return 0;
}
