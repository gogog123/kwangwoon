#include <iostream>
#include <windows.h>
#include <ctime>
#include <fstream>
#include "player.h"
using namespace std;

int main()
{
	int turn = 1, select = 0;;
	int field[9][9] = { 0, };
	char name1[10] = { 0, };
	char name2[10] = { 0, };
	player * player1, * player2, * p, * n;
	cout << "player1 name : "; cin >> name1;
	cout << "player2 name : "; cin >> name2;
	//////////////////////// 플레이어 동적할당 ///////////////////////////////
	if (strcmp(name1, "default") == 0)
		player1 = new player(1);
	else 
		player1 = new player(name1, 1);

	if (strcmp(name2, "default") == 0)
		player2 = new player(2);
	else 
		player2 = new player(name2, 2);
	
	//////////////////////////////////////////////////////////////////////////
	field[1][0] = 1; field[3][0] = 1; field[5][0] = 1; field[7][0] = 1;
	field[1][8] = 1; field[3][8] = 1; field[5][8] = 1; field[7][8] = 1;
	system("cls");

	while (1) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (field[i][j] == 0) cout << "□";
				else {
					player1->print(j, i);
					player2->print(j, i);
				}
			}
			cout << endl;
		} //gameboard print

		if (turn == 1) {
			p = player1; n = player2;
			turn = 2;
		}
		else {
			n = player1; p = player2;
			turn = 1;
		}

		cout << p->getName() << " Turn" << endl;
		p->HPprint();
		cout << "1. Move	2.Battle : ";
		cin >> select;

		if (select == 1) {
			while (1) {
				cout << "Pokemon Select(1.C  2.S  3.B  4.P) : "; cin >> select;
				if ((p->getC() == NULL && select == 1) || (p->getS() == NULL && select == 2) || (p->getB() == NULL && select == 3) || (p->getP() == NULL && select == 4)) {
					cout << "Pokemon fell down!" << endl;
					continue;
				}
				if (select < 5 && select>0) break;
				cout << "wrong select pokemon!" << endl;
				if (!cin) {
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
			}
			while (1) {
				char c;
				cout << "Direction(U, D, R, L) : "; cin >> c;
				if (select == 1) {
					if (p->getC()->move(c, field) == true) {
						break;
					}
				}
				else if (select == 2) {
					if (p->getS()->move(c, field) == true) {
						break;
					}
				}
				else if (select == 3) {
					if (p->getB()->move(c, field) == true) {
						break;
					}
				}
				else if (select == 4) {
					if (p->getP()->move(c, field) == true) {
						break;
					}
				}
				cout << "wrong direction!" << endl;
			}
		}
		else {
			cout << "Pokemon Select(1.C  2.S  3.B  4.P) : "; cin >> select;
			cout << "Attack Direction(R, L) : ";
			char attack_direction;
			cin >> attack_direction;
			p->battle(field, n, select, attack_direction);
			Sleep(700);
		}
		if ((player1->getC() == NULL && player1->getS() == NULL && player1->getB() == NULL && player1->getP() == NULL) || (player2->getC() == NULL && player2->getS() == NULL && player2->getB() == NULL && player2->getP() == NULL))
			break;
		system("cls");
	}
	system("cls");
	cout << "*** GAME END ***" << endl;
	delete player1;
	delete player2;
	return 0;
}
