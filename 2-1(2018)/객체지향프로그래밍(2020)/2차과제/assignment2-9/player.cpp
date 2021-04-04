#include "player.h"

player::player(int pNum)
{
	if (pNum == 1)
	{
		playerNumber = pNum; 
		name = new char[10];
		strcpy(name, "player1");
	}
	else
	{
		playerNumber = pNum;
		name = new char[10];
		strcpy(name, "player2");
	}
	C = new Charmander(pNum); 
	S = new Squirtle(pNum);
	B = new Bulbasaur(pNum);
	P = new Pikachu(pNum);
	//Dynamic allocation
}

player::player(char* N, int pNum)
{
	if (pNum == 1)
	{
		name = N;
		playerNumber = pNum;
	}
	else
	{
		name = N;
		playerNumber = pNum;
	}
	C = new Charmander(pNum);
	S = new Squirtle(pNum);
	B = new Bulbasaur(pNum);
	P = new Pikachu(pNum); //alloc
}


void player::battle(int(*field)[9], player* plr, int select, char direction) 
{
	int a = 0;
	int check_attack;
	if (select == 1) //Charmander
	{
		check_attack = C->Attack(field, direction);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (field[i][j] == 2)
				{
					if (plr->C->get_x() == j && plr->C->get_y() == i) { // enemy C
						plr->C->set_hp(plr->C->get_hp() - 2);
						if (plr->C->get_hp() <= 0)
						{
							delete(plr->C); //dynamic allocation release
							plr->C->~Charmander();
							field[i][j] = 0;
						}
						else
							field[i][j] = 1;
						a++;
					}
					else if (plr->S->get_x() == j && plr->S->get_y() == i) { //enemy S
						plr->S->set_hp(plr->S->get_hp() - 1);
						if (plr->S->get_hp() <= 0)
						{
							delete(plr->S); //dynamic allocation release
							plr->S->~Squirtle();
							field[i][j] = 0;
						}
						else
							field[i][j] = 1;
						a++;
					}
					else if (plr->B->get_x() == j && plr->B->get_y() == i) { //enemy B
						plr->B->set_hp(plr->B->get_hp() - 3);
						if (plr->B->get_hp() <= 0)
						{
							delete(plr->B); //dynamic allocation release
							plr->B->~Bulbasaur();
							field[i][j] = 0;
						}
						else
							field[i][j] = 1;
						a++;

					}
					else if (plr->P->get_x() == j && plr->P->get_y() == i) { //enemy P
						plr->P->set_hp(plr->P->get_hp() - 2);
						if (plr->P->get_hp() <= 0)
						{
							delete(plr->P); //dynamic allocation release
							plr->P->~Pikachu();
							field[i][j] = 0;
						}
						else
							field[i][j] = 1;
						a++;

					}
					else { // friendly, no enemy
						check_attack = false;
						field[i][j] = 1;
					}
				}
			}
		}

		if (check_attack == true || a > 0)//attack success
		{
			cout << name << "ÀÇ ÆÄÀÌ¸®ÀÇ ºÒ²É¼¼·Ê!" << endl;
			plr->~player();
		}
		
		else //attack fail
			cout << name << "ÀÇ ÆÄÀÌ¸®ÀÇ °ø°ÝÀÌ ºø³ª°¬´Ù..." << endl;
		
	}


	else if (select == 2) //Squirtle
	{
		check_attack = S->Attack(field, direction);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (field[i][j] == 2)
				{
					if (plr->C->get_x() == j && plr->C->get_y() == i) { // enemy C
						plr->C->set_hp(plr->C->get_hp() - 3);
						if (plr->C->get_hp() <= 0)
						{
							delete(plr->C); //dynamic allocation release
							plr->C->~Charmander();
							field[i][j] = 0;
						}
						else
							field[i][j] = 1;
						a++;

					}
					else if (plr->S->get_x() == j && plr->S->get_y() == i) { //enemy S
						plr->S->set_hp(plr->S->get_hp() - 2);
						if (plr->S->get_hp() <= 0)
						{
							delete(plr->S); //dynamic allocation release
							plr->S->~Squirtle();
							field[i][j] = 0;
						}
						else
							field[i][j] = 1;
						a++;

					}
					else if (plr->B->get_x() == j && plr->B->get_y() == i) { //enemy B
						plr->B->set_hp(plr->B->get_hp() - 1);
						if (plr->B->get_hp() <= 0)
						{
							delete(plr->B); //dynamic allocation release
							plr->B->~Bulbasaur();
							field[i][j] = 0;
						}
						else
							field[i][j] = 1;
						a++;

					}
					else if (plr->P->get_x() == j && plr->P->get_y() == i) { //enemy P
						plr->P->set_hp(plr->P->get_hp() - 2);
						if (plr->P->get_hp() <= 0)
						{
							delete(plr->P); //dynamic allocation release
							plr->P->~Pikachu();
							field[i][j] = 0;
						}
						else
							field[i][j] = 1;
						a++;

					}
					else { // friendly, no enemy
						check_attack = false;
						field[i][j] = 1;
					}
				}
			}
		}

		if (check_attack == true || a > 0)
		{
			cout << name << "ÀÇ ²¿ºÎ±âÀÇ ¹°´ëÆ÷!" << endl; //attack success
			plr->~player();
		}

		else
			cout << name << "ÀÇ ²¿ºÎ±âÀÇ °ø°ÝÀÌ ºø³ª°¬´Ù..." << endl;


	}
	else if (select == 3) // Bulbasaur
	{
		check_attack = B->Attack(field, direction);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (field[i][j] == 2)
				{
					if (plr->C->get_x() == j && plr->C->get_y() == i) { // enemy C
						plr->C->set_hp(plr->C->get_hp() - 1);
						if (plr->C->get_hp() <= 0)
						{
							delete(plr->C); //dynamic allocation release
							plr->C->~Charmander();
							field[i][j] = 0;
						}
						else
							field[i][j] = 1;
						a++;

					}
					else if (plr->S->get_x() == j && plr->S->get_y() == i) { //enemy S
						plr->S->set_hp(plr->S->get_hp() - 3);
						if (plr->S->get_hp() <= 0)
						{
							delete(plr->S); //dynamic allocation release
							plr->S->~Squirtle();
							field[i][j] = 0;
						}
						else
							field[i][j] = 1;
						a++;

					}
					else if (plr->B->get_x() == j && plr->B->get_y() == i) { //enemy B
						plr->B->set_hp(plr->B->get_hp() - 2);
						if (plr->B->get_hp() <= 0)
						{
							delete(plr->B); //dynamic allocation release
							plr->B->~Bulbasaur();
							field[i][j] = 0;
						}
						else
							field[i][j] = 1;
						a++;
					}
					else if (plr->P->get_x() == j && plr->P->get_y() == i) { //enemy P
						plr->P->set_hp(plr->P->get_hp() - 2);
						if (plr->P->get_hp() <= 0)
						{
							delete(plr->P); //dynamic allocation release
							plr->P->~Pikachu();
							field[i][j] = 0;
						}
						else
							field[i][j] = 1;
						a++;

					}
					else { // friendly, no enemy
						check_attack = false;
						field[i][j] = 1;
					}
				}
			}
		}

		if (check_attack == true || a > 0) //attack success
		{
			cout << name << "ÀÇ ÀÌ»óÇØ¾¾ÀÇ µ¢±¼Ã¤Âï!" << endl;
			plr->~player(); 
		}

		else
			cout << name << "ÀÇ ÀÌ»óÇØ¾¾ÀÇ °ø°ÝÀÌ ºø³ª°¬´Ù..." << endl;


	}
	else if (select == 4) // Pikachu
	{
		check_attack = P->Attack(field, direction);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (field[i][j] == 2)
				{
					if (plr->C->get_x() == j && plr->C->get_y() == i) { // enemy C
						plr->C->set_hp(plr->C->get_hp() - 2);
						if (plr->C->get_hp() <= 0)
						{
							delete(plr->C); //dynamic allocation release
							plr->C->~Charmander();
							field[i][j] = 0; 
						}
						else
							field[i][j] = 1;
						a++;

					}
					else if (plr->S->get_x() == j && plr->S->get_y() == i) { //enemy S
						plr->S->set_hp(plr->S->get_hp() - 2);
						if (plr->S->get_hp() <= 0)
						{
							delete(plr->S); //dynamic allocation release
							plr->S->~Squirtle();
							field[i][j] = 0;
						}
						else
							field[i][j] = 1;
						a++;

					}
					else if (plr->B->get_x() == j && plr->B->get_y() == i) { //enemy B
						plr->B->set_hp(plr->B->get_hp() - 2);
						if (plr->B->get_hp() <= 0)
						{
							delete(plr->B); //dynamic allocation release
							plr->B->~Bulbasaur();
							field[i][j] = 0;
						}
						else
							field[i][j] = 1;
						a++;

					}
					else if (plr->P->get_x() == j && plr->P->get_y() == i) { //enemy P
						plr->P->set_hp(plr->P->get_hp() - 2);
						if (plr->P->get_hp() <= 0)
						{
							delete(plr->P); //dynamic allocation release
							plr->P->~Pikachu();
							field[i][j] = 0;
						}
						else
							field[i][j] = 1;
						a++;

					}
					else { // friendly, no enemy
						check_attack = false;
						field[i][j] = 1;
					}
				}
			}
		}

		if (check_attack == true || a > 0)//attack success
		{
			cout << name << "ÀÇ ÇÇÄ«ÃòÀÇ 100¸¸º¼Æ®!" << endl;
			plr->~player();
		}

		else
			cout << name << "ÀÇ ÇÇÄ«ÃòÀÇ °ø°ÝÀÌ ºø³ª°¬´Ù..." << endl;

	}

}

void player::print(int j, int i)
{
	if (playerNumber == 1)
	{
		if ((C->get_x() == j) && (C->get_y() == i)) { cout << "C1"; }
		else if ((S->get_x() == j) && (S->get_y() == i)) { cout << "S1"; }
		else if ((P->get_x() == j) && (P->get_y() == i)) { cout << "P1"; }
		else if ((B->get_x() == j) && (B->get_y() == i)) { cout << "B1"; }
	}//print  position
	else
	{
		if ((C->get_x() == j) && (C->get_y() == i)) { cout << "C2"; }
		else if ((S->get_x() == j) && (S->get_y() == i)) { cout << "S2"; }
		else if ((P->get_x() == j) && (P->get_y() == i)) { cout << "P2"; }
		else if ((B->get_x() == j) && (B->get_y() == i)) { cout << "B2"; }
	} //print  position

}

