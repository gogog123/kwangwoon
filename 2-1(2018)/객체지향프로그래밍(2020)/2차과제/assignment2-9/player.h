#pragma once
#include "pokemon.h"
#include <cstring>
#include <windows.h> 

class player
{
private:
	Charmander* C;
	Squirtle* S;
	Bulbasaur* B;
	Pikachu* P;
	char* name;
	int playerNumber;

public:
	player(int pNum);
	player(char* N, int pNum);
	~player()
	{
		if (C->get_hp() == 0 && C->get_death() == 1) {
			cout << name << "�� ���̸��� ��������..." << endl;
			C->set_death(2); //To print only once
		}
		if (S->get_hp() == 0 && S->get_death() == 1) {
			cout << name << "�� ���αⰡ ��������..." << endl;
			S->set_death(2); //To print only once
		}
		if (B->get_hp() == 0 && B->get_death() == 1) {
			cout << name << "�� �̻��ؾ��� ��������..." << endl;
			B->set_death(2); //To print only once
		}
		if (P->get_hp() == 0 && P->get_death() == 1) {
			cout << name << "�� ��ī�� ��������..." << endl;
			P->set_death(2); //To print only once
		}//death

	}

	void battle(int(*field)[9], player* plr, int select, char direction);
	void print(int j, int i);
	char* getName() { return name; }

	void HPprint() {
		cout << "C : ";
		if (C->get_hp() == 0)
			cout << "X";
		else
			cout << C->get_hp();

		cout << "   S : ";
		if (S->get_hp() == 0)
			cout << "X";
		else
			cout << S->get_hp();

		cout << "   B : ";
		if (B->get_hp() == 0)
			cout << "X";
		else
			cout << B->get_hp();

		cout << "   P : ";
		if (P->get_hp() == 0)
			cout << "X";
		else
			cout << P->get_hp();

		cout << endl;
	} //current hp, hp = 0 -> "x" print

	Charmander* getC() { return C; }
	Squirtle* getS() { return S; }
	Bulbasaur* getB() { return B; }
	Pikachu* getP() { return P; }

};

