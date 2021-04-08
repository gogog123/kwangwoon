#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class MyBlock
{
private:
	int m_number, m_x, m_y;;
	MyBlock* m_pUp;
	MyBlock* m_pDown;
	MyBlock* m_pLeft;
	MyBlock* m_pRight;

public:
	MyBlock()
	{
		m_number = 0;
		m_x = 0;
		m_y = 0;
		m_pUp = NULL;
		m_pDown = NULL;
		m_pLeft = NULL;
		m_pRight = NULL;
	} // initial setting
	MyBlock(int x, int y)
	{
		m_number = 0;
		m_x = x;
		m_y = y;
		m_pUp = NULL;
		m_pDown = NULL;
		m_pLeft = NULL;
		m_pRight = NULL;
	} //initial setting
	~MyBlock() {}

	void SetNumber(int num) { m_number = num; }
	void Set_X(int x) { m_x = x; }
	void Set_Y(int y) { m_y = y; }
	void SetUp(MyBlock* up) { m_pUp = up; }
	void SetDown(MyBlock* down) { m_pDown = down; }
	void SetLeft(MyBlock* left) { m_pLeft = left; }
	void SetRight(MyBlock* right) { m_pRight = right; }
	//input finction

	int GetNumber() { return m_number; }
	int Get_X() { return m_x; }
	int Get_Y() { return m_y; }
	MyBlock* GetUp() { return m_pUp; }
	MyBlock* GetDown() { return m_pDown; }
	MyBlock* GetLeft() { return m_pLeft; }
	MyBlock* GetRight() { return m_pRight; }
	//return value

	void Insert(int x, int y, MyBlock* Add, MyBlock* Head)
	{
		if (x == 0 && y == 0)
		{
			Head = Add;
			return;
		} //Head setting

		MyBlock* temp_i = new MyBlock;
		MyBlock* temp_j = new MyBlock;
		temp_i = Head;
		temp_j = Head;

		for (int i = 0; i < x; i++)
			temp_i = temp_i->m_pDown;
		for (int j = 0; j < y - 1; j++)
			temp_i = temp_i->m_pRight;
		//Connect with the left side of the side to be added
		for (int i = 0; i < x - 1; i++)
			temp_j = temp_j->m_pDown;
		for (int j = 0; j < y; j++)
			temp_j = temp_j->m_pRight;
		//Connect with the top of the side to be added

		if (x != 0)
		{
			temp_j->m_pDown = Add;
			Add->m_pUp = temp_j;
		} //Connect up and down
		if (y != 0)
		{
			temp_i->m_pRight = Add;
			Add->m_pLeft = temp_i;
		} //Connect right and left
	}
};

class MyBoard
{
private:
	MyBlock* m_pHead;

public:
	MyBoard()
	{
		m_pHead = new MyBlock();
		MyBlock* new_block;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				new_block = new MyBlock(i, j);
				new_block->Insert(i, j, new_block, m_pHead);
			}
		}
	}

	~MyBoard() {}

	void SetHead(MyBlock* board) { m_pHead = board; }
	MyBlock* GetHead() { return m_pHead; }

	bool Up()
	{
		int check = 0;
		MyBlock* temp = GetHead(); //Location before change
		MyBlock* temp_sub = GetHead();

		for (int i = 0; i < 4; i++)
		{
			temp_sub = GetHead();
			for (int k = 0; k < i; k++)
				temp_sub = temp_sub->GetRight();
			//Move right

			for (int j = 0; j < 3; j++)
			{
				temp = temp_sub;
				for (int m = 0; m <= j; m++)
					temp = temp->GetDown();

				if (temp->GetNumber() != 0)
				{
					while (1)
					{
						if (temp->GetUp()->GetNumber() == 0)
						{
							temp->GetUp()->SetNumber(temp->GetNumber());
							temp->SetNumber(0);
							// Value change
							check++; // Change value check
						}
						if (temp->GetUp()->GetNumber() == temp->GetNumber())
						{
							temp->GetUp()->SetNumber((temp->GetNumber()) * 2); //Multiply by 2
							temp->SetNumber(0);
							check++;
							break;
						} // At the same value

						temp = temp->GetUp(); 
						if (temp->GetUp() == NULL) //the end 
							break;
					}
				}
			}
		}
		if(check == 0)
			return false; // When there is no changed value

		return true;
	}

	bool Down()
	{
		int check = 0;
		MyBlock* temp = GetHead(); //Location before change
		MyBlock* temp_sub = GetHead();

		for (int i = 0; i < 4; i++)
		{
			temp_sub = GetHead()->GetDown()->GetDown()->GetDown(); //Move to the starting position

			for (int k = 0; k < i; k++)
				temp_sub = temp_sub->GetRight();
			//Move right

			for (int j = 0; j < 3; j++)
			{
				temp = temp_sub;
				for (int m = 0; m <= j; m++)
					temp = temp->GetUp();

				if (temp->GetNumber() != 0)
				{
					while (1)
					{
						if (temp->GetDown()->GetNumber() == 0)
						{
							temp->GetDown()->SetNumber(temp->GetNumber());
							temp->SetNumber(0);
							// Value change
							check++; // Change value check
						}
						if (temp->GetDown()->GetNumber() == temp->GetNumber())
						{
							temp->GetDown()->SetNumber((temp->GetNumber()) * 2); //Multiply by 2
							temp->SetNumber(0);
							check++;
							break;
						} // At the same value

						temp = temp->GetDown();
						if (temp->GetDown() == NULL) //the end 
							break;
					}
				}
			}
		}
		if (check == 0)
			return false; // When there is no changed value

		return true;
	}

	bool Left()
	{
		int check = 0;
		MyBlock* temp = GetHead(); //Location before change
		MyBlock* temp_sub = GetHead();

		for (int i = 0; i < 4; i++)
		{
			temp_sub = GetHead();
			for (int k = 0; k < i; k++)
				temp_sub = temp_sub->GetDown();
			//Move Down

			for (int j = 0; j < 3; j++)
			{
				temp = temp_sub;
				for (int m = 0; m <= j; m++)
					temp = temp->GetRight();

				if (temp->GetNumber() != 0)
				{
					while (1)
					{
						if (temp->GetLeft()->GetNumber() == 0)
						{
							temp->GetLeft()->SetNumber(temp->GetNumber());
							temp->SetNumber(0);
							// Value change
							check++; // Change value check
						}
						if (temp->GetLeft()->GetNumber() == temp->GetNumber())
						{
							temp->GetLeft()->SetNumber((temp->GetNumber()) * 2); //Multiply by 2
							temp->SetNumber(0);
							check++;
							break;
						} // At the same value

						temp = temp->GetLeft();
						if (temp->GetLeft() == NULL) //the end 
							break;
					}
				}
			}
		}
		if (check == 0)
			return false; // When there is no changed value

		return true;
	}

	bool Right()
	{
		int check = 0;
		MyBlock* temp = GetHead(); //Location before change
		MyBlock* temp_sub = GetHead();

		for (int i = 0; i < 4; i++)
		{
			temp_sub = GetHead()->GetRight()->GetRight()->GetRight();
			for (int k = 0; k < i; k++)
				temp_sub = temp_sub->GetDown();
			//Move right

			for (int j = 0; j < 3; j++)
			{
				temp = temp_sub;
				for (int m = 0; m <= j; m++)
					temp = temp->GetLeft();

				if (temp->GetNumber() != 0)
				{
					while (1)
					{
						if (temp->GetRight()->GetNumber() == 0)
						{
							temp->GetRight()->SetNumber(temp->GetNumber());
							temp->SetNumber(0);
							// Value change
							check++; // Change value check
						}
						if (temp->GetRight()->GetNumber() == temp->GetNumber())
						{
							temp->GetRight()->SetNumber((temp->GetNumber()) * 2); //Multiply by 2
							temp->SetNumber(0);
							check++;
							break;
						} // At the same value

						temp = temp->GetRight();
						if (temp->GetRight() == NULL) //the end 
							break;
					}
				}
			}
		}
		if (check == 0)
			return false; // When there is no changed value

		return true;
	}

	void Random_two() // function to make 2
	{
		int x;
		int y;
		while (1)
		{
			srand(time(NULL));
			x = rand() % 4;
			y = rand() % 4;
			//random make in range

			MyBlock* temp = GetHead();
			for (int i = 0; i < x; i++)
				temp = temp->GetDown();
			for (int j = 0; j < y; j++)
				temp = temp->GetRight();
			//move to space to put value

			if (temp->GetNumber() == 0) // empty space
			{
				temp->SetNumber(2); //input 2
				break;
			}
		}
	}

	void Print_Board() //print game board
	{
		MyBlock* temp = new MyBlock; // output in order

		cout << "[Board]" << endl;
		for (int i = 0; i < 4; i++)
		{
			temp = m_pHead;
			for (int k = 0; k < i; k++)
				temp = temp->GetDown();
			cout << "[    ";
			for (int j = 0; j < 4; j++)
			{
				cout.setf(ios::left);
				if (temp->GetNumber() == 0) // No value
					cout << setw(6) << "-";
				else
					cout << setw(6) << temp->GetNumber(); //print number
				temp = temp->GetRight();
			}
			cout << " ]" << endl;
		}
	}

	int Win()
	{
		MyBlock* temp = GetHead();

		int check = 0;

		for (int i = 0; i < 4; i++)
		{
			temp = GetHead();
			for (int k = 0; k < i; k++)
				temp = temp->GetDown(); // next row

			for (int j = 0; j < 4; j++)
			{
				if (temp->GetNumber() == 2048)
					return 1; // Returns true if 2048 (win!)
				if (temp->GetNumber() == 0)
					check++;
				temp = temp->GetRight(); // next colum
			}
		}
		if (check == 0)
			return 2; //All the fields are filled
		return 0; 
	}

	bool Lose()
	{
		int check = 0;
		MyBlock* temp = GetHead();

		for (int i = 0; i < 3; i++)
		{
			temp = GetHead();
			for (int k = 0; k < i; k++)
				temp = temp->GetDown(); // next row

			for (int j = 0; j < 3; j++)
			{
				if (temp->GetNumber() == temp->GetRight()->GetNumber() && temp->GetNumber() != 0)
					check++;
				if (temp->GetNumber() == temp->GetDown()->GetNumber() && temp->GetNumber() != 0)
					check++; 
				//check the same number of linkedlist
			}
		}
		if (check == 0)
			return true;

		return false;
	}
};

