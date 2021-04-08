#pragma once
#include <iostream>
using namespace std;

class OthelloBoard
{
	int m_player;
	OthelloBoard* m_pHead;
	OthelloBoard* m_pUp;
	OthelloBoard* m_pDown;
	OthelloBoard* m_pLeft;
	OthelloBoard* m_pRight;

public:
	OthelloBoard() {}
	~OthelloBoard() {}

	void SetHead(OthelloBoard* head) { m_pHead = head; }
	void SetUp(OthelloBoard* up) { m_pUp = up; }
	void SetDown(OthelloBoard* down) { m_pDown = down; }
	void SetLeft(OthelloBoard* left) { m_pLeft = left; }
	void SetRight(OthelloBoard* right) { m_pRight = right; }
	void SetPlayer(int player) { m_player = player; }
	// input function

	OthelloBoard* GetHead() { return m_pHead; }
	OthelloBoard* GetUp() { return m_pUp; }
	OthelloBoard* GetDown() { return m_pDown; }
	OthelloBoard* GetLeft() { return m_pLeft; }
	OthelloBoard* GetRight() { return m_pRight; }
	int GetPlayer() { return m_player; }
	// function that return

	void Insert(int x, int y, OthelloBoard* Add, OthelloBoard* start)
	{
		OthelloBoard* temp_i = new OthelloBoard;
		OthelloBoard* temp_j = new OthelloBoard;

		if (x == 0 && y == 0)
		{
			start->m_pHead = Add;
			start->m_pUp = Add;
			start->m_pDown = Add;
			start->m_pRight = Add;
			start->m_pLeft = Add;
			return;
		}

		temp_i = start->m_pHead;
		temp_j = start->m_pHead;

		for (int i = 0; i < x; i++)
			temp_i = temp_i->m_pRight;

		for (int j = 0; j < y - 1; j++)
			temp_i = temp_i->m_pUp;
		//Connect with the left side of the side to be added

		for (int i = 0; i < x - 1; i++)
			temp_j = temp_j->m_pRight;

		for (int j = 0; j < y; j++)
			temp_j = temp_j->m_pUp;
		//Connect with the top of the side to be added



		if (x != 0)
		{
			temp_j->m_pRight = Add;
			Add->m_pLeft = temp_j;
		} //Connect right and left
		if (y != 0)
		{
			temp_i->m_pUp = Add;
			Add->m_pDown = temp_i;
		} //Connect up and down

	}

	void Print_Board(OthelloBoard* start)
	{
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
				if (temp->GetPlayer() == 0)
					cout << "¡à";
				else if (temp->GetPlayer() == 1)
					cout << "¡Ü"; //player 1
				else
					cout << "¡Û"; //player 2
				temp = temp->GetRight();
			}
			cout << endl;
		} // print game board
	}

};