#include <iostream>
using namespace std;

void Game_board(int location[3][3])
{
	cout << " X  0   1   2" << endl;
	cout << "Y  --- --- ---" << endl;
	for (int row = 0; row < 3; row++)
	{
		cout << row << " | ";
		for (int col = 0; col < 3; col++)
		{
			if (location[row][col] == 1) //player 1
			{
				cout << "o";
			}
			else if (location[row][col] == 2) //player 2
			{
				cout << "x";
			}
			else
				cout << " ";
			cout << " | ";
		}
		cout << endl;
		cout << "   --- --- ---" << endl;
	}
}//Print Game board

bool  Winner(int location[][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (location[0][i] != 0 && location[0][i] == location[1][i] && location[1][i] == location[2][i])
		{
			if (location[0][i] == 1)
			{
				cout << "Winner is [Player 1]" << endl;
			}
			else if (location[0][i] == 2)
			{
				cout << "Winner is [Player 2]" << endl;
			}
			return true;
		} // column bingo.

		else if (location[i][0] != 0 && location[i][0] == location[i][1] && location[i][1] == location[i][2])
		{
			if (location[i][0] == 1)
			{
				cout << "Winner is [Player 1]" << endl;
			}
			else if (location[i][0] == 2)
			{
				cout << "Winner is [Player 2]" << endl;
			}
			return true;
		} // row bingo.
	}

	if (location[0][0] != 0 && location[0][0] == location[1][1] && location[1][1] == location[2][2])
	{
		if (location[0][0] == 1)
		{
			cout << "Winner is [Player 1]" << endl;
		}
		else if (location[0][0] == 2)
		{
			cout << "Winner is [Player 2]" << endl;
		}
		return true;
	} //diagonal bingo.


	if (location[0][2] != 0 && location[0][2] == location[1][1] && location[1][1] == location[2][0])
	{
		if (location[0][2] == 1)
		{
			cout << "Winner is [Player 1]" << endl;
		}
		else if (location[0][2] == 2)
		{
			cout << "Winner is [Player 2]" << endl;
		}
		return true;
	}//diagonal bingo.

	return false; // false bigo
}

int main()
{
	int x, y;
	int count = 0;
	int location[3][3] = { 0 };
	bool result;

	Game_board(location); //Print Game board


	while (1)
	{
		while (1)
		{
			cout << "[Play 1] Enter your location [x y] : ";
			cin >> x >> y;
			if (x > 2 || y > 2 || location[x][y] != 0) //input is wrong
			{
				cout << "Please input again\n\n";
			}
			else
				break;
		}
		location[y][x] = 1;
		cout << endl;
		Game_board(location);
		if (Winner(location) == true) //check the winner
			break;
		count++;

		if (count == 9)
		{
			cout << "Draw";
			break;
		} //when drawing.

		while (1)
		{
			cout << "[Play 2] Enter your location [x y] : ";
			cin >> x >> y;
			if (x > 2 || y > 2 || location[x][y] != 0) //input is wrong
			{
				cout << "Please input again\n\n";
			}
			else
				break;
		}

		location[y][x] = 2;
		cout << endl;
		Game_board(location);
		if (Winner(location) == true) //check the winner
			break;
		count++;
	}

	cout << endl;

	return 0;
}