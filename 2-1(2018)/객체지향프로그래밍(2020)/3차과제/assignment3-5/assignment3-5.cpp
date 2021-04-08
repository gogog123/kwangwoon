#include <iostream>
#include "MyBoard.h"
using namespace std;

int main()
{
	MyBoard* m_Board;
	m_Board = new MyBoard();
	int move_check = 0;

	while (1)
	{
		if(move_check == 0)
			m_Board->Random_two();
		m_Board->Print_Board();

		move_check = 0;

		int input_num;
		cout << "[Menu]" << endl;
		cout << "1. Up  " << "2. Down  " << "3. Left  " << "4. Right  " << endl;
		cout << "Input >> ";
		cin >> input_num;
		switch (input_num)
		{
		case 1: //direction UP
			if (m_Board->Up() == false)
				move_check = 1;
			break;
		case 2: //direction Down
			if (m_Board->Down() == false)
				move_check = 1;
			break;
		case 3: //direction Left
			if (m_Board->Left() == false)
				move_check = 1;
			break;
		case 4: //direction Right
			if (m_Board->Right() == false)
				move_check = 1;
			break;
		case -1:
			cout << "[program exit]" << endl;
			return 0;
		default:
			break;
		}
		cout << endl;

		if (m_Board->Win() == 1)
		{
			cout << "Win!!" << endl;
			cout << "[Program exit]" << endl;
			return 0;
		}//create 2048

		if (m_Board->Lose() == true && m_Board->Win() == 2)
		{
			cout << "Lose!!" << endl;
			cout << "[Program exit]" << endl;
			return 0;
		} //can't move

		system("cls");

	}
	return 0;
}