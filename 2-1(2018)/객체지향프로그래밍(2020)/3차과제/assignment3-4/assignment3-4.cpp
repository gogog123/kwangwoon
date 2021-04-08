#include <iostream>
#include "OthelloBoard.h"
using namespace std;

////////////////////////Stone change///////////////////////////////
bool Game_Up(int player, OthelloBoard* put_stone)
{
	if (put_stone->GetUp() == NULL)
		return false; // does not exist

	OthelloBoard* temp = put_stone->GetUp();
	if (temp->GetPlayer() != player && temp->GetPlayer() != 0)
	{
		while (1)
		{
			if (temp->GetUp() == NULL)
				return false; // does not exist

			temp = temp->GetUp();
			if (temp->GetPlayer() == 0)
				return false; //No stone to change
			else if (temp->GetPlayer() == player)
				break;  //find player stone
		}

		while (1)
		{
			temp = temp->GetDown();
			if (temp->GetPlayer() == 0)
			{
				temp->SetPlayer(player); 
				break;
			}
			temp->SetPlayer(player);
		} //change player stone 
	}
	else
		return false;

	return true; //when changed
}

bool Game_Down(int player, OthelloBoard* put_stone)
{
	if (put_stone->GetDown() == NULL)
		return false; // does not exist

	OthelloBoard* temp = put_stone->GetDown();
	if (temp->GetPlayer() != player && temp->GetPlayer() != 0)
	{
		while (1)
		{
			if (temp->GetDown() == NULL)
				return false; // does not exist

			temp = temp->GetDown();
			if (temp->GetPlayer() == 0)
				return false; //No stone to change
			else if (temp->GetPlayer() == player)
				break;  //find player stone
		}

		while (1)
		{
			temp = temp->GetUp();
			if (temp->GetPlayer() == 0)
			{
				temp->SetPlayer(player);
				break;
			}
			temp->SetPlayer(player);
		} //change player stone 
	}
	else
		return false;

	return true; //when changed
}

bool Game_Right(int player, OthelloBoard* put_stone)
{
	if (put_stone->GetRight() == NULL)
		return false; // does not exist

	OthelloBoard* temp = put_stone->GetRight();
	if (temp->GetPlayer() != player && temp->GetPlayer() != 0)
	{
		while (1)
		{
			if (temp->GetRight() == NULL)
				return false; // does not exist

			temp = temp->GetRight();
			if (temp->GetPlayer() == 0)
				return false; //No stone to change
			else if (temp->GetPlayer() == player)
				break;  //find player stone
		}

		while (1)
		{
			temp = temp->GetLeft();
			if (temp->GetPlayer() == 0)
			{
				temp->SetPlayer(player);
				break;
			}
			temp->SetPlayer(player);
		} //change player stone 
	}
	else
		return false;

	return true; //when changed
}

bool Game_Left(int player, OthelloBoard* put_stone)
{
	if (put_stone->GetLeft() == NULL)
		return false; // does not exist

	OthelloBoard* temp = put_stone->GetLeft();
	if (temp->GetPlayer() != player && temp->GetPlayer() != 0)
	{
		while (1)
		{
			if (temp->GetLeft() == NULL)
				return false; // does not exist

			temp = temp->GetLeft();
			if (temp->GetPlayer() == 0)
				return false; //No stone to change
			else if (temp->GetPlayer() == player)
				break;  //find player stone
		}
		while (1)
		{
			temp = temp->GetRight();
			if (temp->GetPlayer() == 0)
			{
				temp->SetPlayer(player);
				break;
			}
			temp->SetPlayer(player);
		} //change player stone 
	}
	else
		return false;

	return true; //when changed
}

bool Game_Up_Left(int player, OthelloBoard* put_stone)
{
	if (put_stone->GetUp() == NULL|| put_stone->GetLeft()==NULL)
		return false; // does not exist

	OthelloBoard* temp = put_stone->GetUp()->GetLeft();
	if (temp->GetPlayer() != player && temp->GetPlayer() != 0)
	{
		while (1)
		{
			if (temp->GetUp() == NULL || temp->GetLeft() == NULL)
				return false; // does not exist

			temp = temp->GetUp()->GetLeft();
			if (temp->GetPlayer() == 0)
				return false; //No stone to change
			else if (temp->GetPlayer() == player)
				break;  //find player stone
		}
		while (1)
		{
			temp = temp->GetDown()->GetRight();
			if (temp->GetPlayer() == 0)
			{
				temp->SetPlayer(player);
				break;
			}
			temp->SetPlayer(player);
		} //change player stone 
	}
	else
		return false;

	return true; //when changed
}

bool Game_Up_Right(int player, OthelloBoard* put_stone)
{
	if (put_stone->GetUp() == NULL || put_stone->GetRight() == NULL)
		return false; // does not exist

	OthelloBoard* temp = put_stone->GetUp()->GetRight();
	if (temp->GetPlayer() != player && temp->GetPlayer() != 0)
	{
		while (1)
		{
			if (temp->GetUp() == NULL || temp->GetRight() == NULL)
				return false; // does not exist

			temp = temp->GetUp()->GetRight();
			if (temp->GetPlayer() == 0)
				return false; //No stone to change
			else if (temp->GetPlayer() == player)
				break;  //find player stone
		}
		while (1)
		{
			temp = temp->GetDown()->GetLeft();
			if (temp->GetPlayer() == 0)
			{
				temp->SetPlayer(player);
				break;
			}
			temp->SetPlayer(player);
		} //change player stone 
	}
	else
		return false;

	return true; //when changed
}

bool Game_Down_Left(int player, OthelloBoard* put_stone)
{
	if (put_stone->GetDown() == NULL || put_stone->GetLeft() == NULL)
		return false; // does not exist

	OthelloBoard* temp = put_stone->GetDown()->GetLeft();
	if (temp->GetPlayer() != player && temp->GetPlayer() != 0)
	{
		while (1)
		{
			if (temp->GetDown() == NULL || temp->GetLeft() == NULL)
				return false; // does not exist

			temp = temp->GetDown()->GetLeft();
			if (temp->GetPlayer() == 0)
				return false; //No stone to change
			else if (temp->GetPlayer() == player)
				break;  //find player stone
		}
		while (1)
		{
			temp = temp->GetUp()->GetRight();
			if (temp->GetPlayer() == 0)
			{
				temp->SetPlayer(player);
				break;
			}
			temp->SetPlayer(player);
		} //change player stone 
	}
	else
		return false;

	return true; //when changed
}

bool Game_Down_Right(int player, OthelloBoard* put_stone)
{
	if (put_stone->GetDown() == NULL || put_stone->GetRight() == NULL)
		return false; // does not exist

	OthelloBoard* temp = put_stone->GetDown()->GetRight();
	if (temp->GetPlayer() != player && temp->GetPlayer() != 0)
	{
		while (1)
		{
			if (temp->GetDown() == NULL || temp->GetRight() == NULL)
				return false; // does not exist

			temp = temp->GetDown()->GetRight();
			if (temp->GetPlayer() == 0)
				return false; //No stone to change
			else if (temp->GetPlayer() == player)
				break;  //find player stone
		}
		while (1)
		{
			temp = temp->GetUp()->GetLeft();
			if (temp->GetPlayer() == 0)
			{
				temp->SetPlayer(player);
				break;
			}
			temp->SetPlayer(player);
		} //change player stone 
	}
	else
		return false;

	return true; //when changed
}

bool Game(int player, OthelloBoard* put_stone)
{
	int check = 0;

	if (Game_Up(player, put_stone) == true)
		check = 1;
	if (Game_Down(player, put_stone) == true)
		check = 1;
	if (Game_Right(player, put_stone) == true)
		check = 1;
	if (Game_Left(player, put_stone) == true)
		check = 1;
	if (Game_Up_Left(player, put_stone) == true)
		check = 1;
	if (Game_Up_Right(player, put_stone) == true)
		check = 1;
	if (Game_Down_Left(player, put_stone) == true)
		check = 1;
	if (Game_Down_Right(player, put_stone) == true)
		check = 1;


	if (check == 0)
		return false;

	return true;

}

int Winner(OthelloBoard* start)
{
	int check = 0;
	int check_1 = 0;
	int check_2 = 0; // When all plates are filled,
	int check_all = 0; // Make sure the stone fills the plate

	OthelloBoard* temp;
	for (int i = 0; i < 8; i++)
	{
		temp = start->GetHead();
		for (int k = 6 - i; k >= 0; k--)
		{
			temp = temp->GetUp();
		}
		for (int j = 0; j < 8; j++)
		{
			if (temp->GetPlayer() == 1)
				check_1++;
			if (temp->GetPlayer() == 2)
				check_2++;
			if (temp->GetPlayer() == 0)
				check_all = 1;
			temp = temp->GetRight();
		}
	}

	if (check_1 == 0)
		return 2;  // win player2
	//player1 no stone

	if (check_2 == 0)
		return 1; // win player1
	

	if (check_all == 0)
	{
		if (check_1 > check_2) // When all plates are filled,
			return 1; //win player1
		else if (check_1 < check_2) // When all plates are filled,
			return 2;  // win player2
		else // When all plates are filled,
			return 3; // draw
	}
	return 0;
}

/////////////////////Check if there is a stone to change/////////////////////////////////////

bool lose_up(OthelloBoard* position, int player)
{
	if (position->GetUp() == NULL)
		return false; //No value above
	
	position = position->GetUp();
	if (position->GetPlayer() != player && position->GetPlayer() != 0) //When it is another play stone
	{
		while (1)
		{
			position = position->GetUp();
			if (position->GetUp() == NULL) //If you can't let go of the stone
				return false;
			if (position->GetUp()->GetPlayer() == 0) //If you can put stones
				return true;
			else if (position->GetUp()->GetPlayer() == player) //If you can't let go of the stone
				return false;
		}
	}
	return false;
}

bool lose_down(OthelloBoard* position, int player)
{
	if (position->GetDown() == NULL)
		return false; //No value above

	position = position->GetDown();
	if (position->GetPlayer() != player && position->GetPlayer() != 0) //When it is another play stone
	{
		while (1)
		{
			position = position->GetDown();
			if (position->GetDown() == NULL) //If you can't let go of the stone
				return false;
			if (position->GetDown()->GetPlayer() == 0) //If you can put stones
				return true;
			else if (position->GetDown()->GetPlayer() == player) //If you can't let go of the stone
				return false;
		}
	}
	return false;
}

bool lose_left(OthelloBoard* position, int player)
{
	if (position->GetLeft() == NULL)
		return false; //No value above

	position = position->GetLeft();
	if (position->GetPlayer() != player && position->GetPlayer() != 0) //When it is another play stone
	{
		while (1)
		{
			position = position->GetLeft();
			if (position->GetLeft() == NULL) //If you can't let go of the stone
				return false;
			if (position->GetLeft()->GetPlayer() == 0) //If you can put stones
				return true;
			else if (position->GetLeft()->GetPlayer() == player) //If you can't let go of the stone
				return false;
		}
	}
	return false;
}

bool lose_right(OthelloBoard* position, int player)
{
	if (position->GetRight() == NULL)
		return false; //No value above

	position = position->GetRight();
	if (position->GetPlayer() != player && position->GetPlayer() != 0) //When it is another play stone
	{
		while (1)
		{
			position = position->GetRight();
			if (position->GetRight() == NULL) //If you can't let go of the stone
				return false;
			if (position->GetRight()->GetPlayer() == 0) //If you can put stones
				return true;
			else if (position->GetRight()->GetPlayer() == player) //If you can't let go of the stone
				return false;
		}
	}
	return false;
}

bool lose_up_right(OthelloBoard* position, int player)
{
	if (position->GetRight() == NULL || position->GetUp() == NULL)
		return false; //No value above

	position = position->GetRight()->GetUp();
	if (position->GetPlayer() != player && position->GetPlayer() != 0) //When it is another play stone
	{
		while (1)
		{
			position = position->GetRight()->GetUp();
			if (position->GetRight() == NULL || position->GetUp() == NULL) //If you can't let go of the stone
				return false;
			if (position->GetRight()->GetUp()->GetPlayer() == 0) //If you can put stones
				return true;
			else if (position->GetRight()->GetUp()->GetPlayer() == player) //If you can't let go of the stone
				return false;
		}
	}
	return false;
}

bool lose_up_left(OthelloBoard* position, int player)
{
	if (position->GetLeft() == NULL || position->GetUp() == NULL)
		return false; //No value above

	position = position->GetLeft()->GetUp();
	if (position->GetPlayer() != player && position->GetPlayer() != 0) //When it is another play stone
	{
		while (1)
		{
			position = position->GetLeft()->GetUp();
			if (position->GetLeft() == NULL || position->GetUp() == NULL) //If you can't let go of the stone
				return false;
			if (position->GetLeft()->GetUp()->GetPlayer() == 0) //If you can put stones
				return true;
			else if (position->GetLeft()->GetUp()->GetPlayer() == player) //If you can't let go of the stone
				return false;
		}
	}
	return false;
}

bool lose_down_right(OthelloBoard* position, int player)
{
	if (position->GetRight() == NULL || position->GetDown() == NULL)
		return false; //No value above

	position = position->GetRight()->GetDown();
	if (position->GetPlayer() != player && position->GetPlayer() != 0) //When it is another play stone
	{
		while (1)
		{
			position = position->GetRight()->GetDown();
			if (position->GetRight() == NULL || position->GetDown() == NULL) //If you can't let go of the stone
				return false;
			if (position->GetRight()->GetDown()->GetPlayer() == 0) //If you can put stones
				return true;
			else if (position->GetRight()->GetDown()->GetPlayer() == player) //If you can't let go of the stone
				return false;
		}
	}
	return false;
}

bool lose_down_left(OthelloBoard* position, int player)
{
	if (position->GetLeft() == NULL || position->GetDown() == NULL)
		return false; //No value above

	position = position->GetLeft()->GetDown();
	if (position->GetPlayer() != player && position->GetPlayer() != 0) //When it is another play stone
	{
		while (1)
		{
			position = position->GetLeft()->GetDown();
			if (position->GetLeft() == NULL || position->GetDown() == NULL) //If you can't let go of the stone
				return false;
			if (position->GetLeft()->GetDown()->GetPlayer() == 0) //If you can put stones
				return true;
			else if (position->GetLeft()->GetDown()->GetPlayer() == player) //If you can't let go of the stone
				return false;
		}
	}
	return false;
}

bool lose(OthelloBoard* start, int player)
{
	int check = 0;
	OthelloBoard* temp;
	for (int i = 0; i < 8; i++)
	{
		temp = start->GetHead();
		for (int k = 6 - i; k >= 0; k--)
		{
			temp = temp->GetUp();
		}
		for (int j = 0; j < 8; j++)
		{
			if (temp->GetPlayer() == player)
			{
				if (lose_up(temp, player) == true)
					check++;
				if (lose_down(temp, player) == true)
					check++;
				if (lose_left(temp, player) == true)
					check++;
				if (lose_right(temp, player) == true)
					check++;
				if (lose_up_right(temp, player) == true)
					check++;
				if (lose_down_right(temp, player) == true)
					check++;
				if (lose_up_left(temp, player) == true)
					check++;
				if (lose_down_left(temp, player) == true)
					check++;
				//Check diagonally up, down, left, right
			}
			temp = temp->GetRight();
		}
	}

	if(check >0)
		return true; //posible

	return false; //impossible
}

////////////////////////////main/////////////////////////////////////////
int main()
{
	OthelloBoard* new_board;
	new_board = new OthelloBoard();
	OthelloBoard* m_Board;
	m_Board = new OthelloBoard();
	m_Board->SetHead(NULL);
	//List* Board;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			new_board = new OthelloBoard();
			new_board->SetHead(NULL);
			new_board->SetUp(NULL);
			new_board->SetDown(NULL);
			new_board->SetLeft(NULL);
			new_board->SetRight(NULL);
			if ((i == 3 && j == 3) || (i == 4 && j == 4))
				new_board->SetPlayer(1);
			else if ((i == 3 && j == 4) || (i == 4 && j == 3))
				new_board->SetPlayer(2);
			else
				new_board->SetPlayer(0);
			new_board->Insert(i, j, new_board, m_Board);
		}
	}
	int game_player = 1; //current playing player
	int x;
	int y;
	while (1)
	{
		if (game_player == 1)
			cout << "Player1" << endl;
		else if (game_player == 2)
			cout << "Player2" << endl;
		else
			cout << "error" << endl;
		
		m_Board->Print_Board(m_Board);

		if (lose(m_Board, game_player) == false)
		{
			cout << "Lose " << game_player << endl;
			return 0;
		} //When there is no place to put

		while (1)
		{
			cout << "Select Position : ";
 			cin >> x >> y;
			if (x == -1 && y == -1)
			{
				cout << "Game End!" << endl;
				return 0;
			}

			if (x > 0 && x < 9 && y>0 && y < 9)
				break;
			//x, y : 1~8 input
		}

		OthelloBoard* temp = new OthelloBoard();
		temp = m_Board->GetHead();
		for (int i = 1; i < x; i++)
			temp = temp->GetRight();
		
		for (int j = 1; j < y; j++)
			temp = temp->GetUp();
		//temp : position move
		if (temp->GetPlayer() != 0)
		{
			system("cls");
			cout << "Wrong position!" << endl;
			continue;
		}

		system("cls");


		if (Game(game_player, temp) == true)
		{
			if (game_player == 1)
				game_player = 2;
			else
				game_player = 1;
		}
		else
			cout << "Wrong position!" << endl;

		if (Winner(m_Board) == 1)
		{
			cout << "Win player1" << endl;
			break;
		}
		else if (Winner(m_Board) == 2)
		{
			cout << "Win player2" << endl;
			break;
		}
		else if (Winner(m_Board) == 3)
		{
			cout << "Draw" << endl;
			break;
		}
		// Win or lose
	}

	return 0;
}