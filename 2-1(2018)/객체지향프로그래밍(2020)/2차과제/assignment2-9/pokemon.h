#pragma once
#include <iostream>
using namespace std;
class pokemon
{
private:
	int hp;
	int playerNum;
	int x;
	int y;
	char type;
	int death = 0;

public:
	pokemon(int pNum);
	~pokemon() {}

	bool move(char c, int(*field)[9]);
	virtual bool Attack(int(*field)[9], char direction) = 0;

	int get_x() { return x; }
	void set_x(int _x) { x = _x; }
	int get_y() { return y; }
	void set_y(int _y) { y = _y; }
	int get_hp() { return hp; }
	void set_hp(int _hp) { hp = _hp; }
	char get_type() { return type; }
	void set_type(char _type) { type = _type; }
	int get_death() { return death; }
	void set_death(int _death) { death = _death; }
	//get,set function
};

class Charmander : public pokemon
{
private:

public:
	virtual bool Attack(int(*field)[9], char direction) {

		int x = get_x();
		int y = get_y();
		int a = 0;
		if (direction == 'R')
		{
			if (field[y][x + 1] == 1 && 0 <= y && y < 9 && 0 <= x + 1 && x + 1 < 9) {
				field[y][x + 1] = 2; a = 1;
			}
			if (field[y + 1][x + 1] == 1 && 0 <= y + 1 && y + 1 < 9 && 0 <= x + 1 && x + 1 < 9) {
				field[y + 1][x + 1] = 2; a = 1;
			}
			if (field[y - 1][x + 1] == 1 && 0 <= y - 1 && y - 1 < 9 && 0 <= x + 1 && x + 1 < 9) {
				field[y - 1][x + 1] = 2; a = 1;
			}
			if (field[y - 1][x + 2] == 1 && 0 <= y - 1 && y - 1 < 9 && 0 <= x + 2 && x + 2 < 9) {
				field[y - 1][x + 2] = 2; a = 1;
			}
			if (field[y + 1][x + 2] == 1 && 0 <= y + 1 && y + 1 < 9 && 0 <= x + 2 && x + 2 < 9) {
				field[y + 1][x + 2] = 2; a = 1;
			}
		} //Set attack range
		// field range 9*9
		else
		{
			if (field[y][x - 1] == 1 && 0 <= y && y < 9 && 0 <= x - 1 && x - 1 < 9) {
				field[y][x - 1] = 2; a = 1;
			}
			if (field[y + 1][x - 1] == 1 && 0 <= y + 1 && y + 1 < 9 && 0 <= x - 1 && x - 1 < 9) {
				field[y + 1][x - 1] = 2; a = 1;
			}
			if (field[y - 1][x - 1] == 1 && 0 <= y - 1 && y - 1 < 9 && 0 <= x - 1 && x - 1 < 9) {
				field[y - 1][x - 1] = 2; a = 1;
			}
			if (field[y - 1][x - 2] == 1 && 0 <= y - 1 && y - 1 < 9 && 0 <= x - 2 && x - 2 < 9) {
				field[y - 1][x - 2] = 2; a = 1;
			}
			if (field[y + 1][x - 2] == 1 && 0 <= y + 1 && y + 1 < 9 && 0 <= x - 2 && x - 2 < 9) {
				field[y + 1][x - 2] = 2; a = 1;
			}
		}//Set attack range

		if (a == 1)
			return true;

		return false; 
	}

	Charmander(int pNum) : pokemon(pNum)
	{
		if (pNum == 1)
		{
			set_x(0);
			set_y(1);
		}
		else
		{
			set_x(8);
			set_y(1);
		}
		set_type('F');
	}//initial setting

	~Charmander()
	{
		set_x(NULL);
		set_y(NULL);
		set_hp(0);
		set_death(1);
	}

};

class Squirtle : public pokemon
{
private:

public:
	virtual bool Attack(int(*field)[9], char direction) {
		int x = get_x();
		int y = get_y();
		int a = 0;
		if (direction == 'R')
		{
			if (field[y - 1][x] == 1 && 0 <= y - 1 && y - 1 < 9 && 0 <= x && x < 9) {
				field[y - 1][x] = 2; a = 1;
			}
			if (field[y + 1][x] == 1 && 0 <= y + 1 && y + 1 < 9 && 0 <= x && x < 9) {
				field[y + 1][x] = 2; a = 1;
			}
			if (field[y][x + 1] == 1 && 0 <= y && y < 9 && 0 <= x + 1 && x + 1 < 9) {
				field[y][x + 1] = 2; a = 1;
			}
			if (field[y][x + 2] == 1 && 0 <= y && y < 9 && 0 <= x + 2 && x + 2 < 9) {
				field[y][x + 2] = 2; a = 1;
			}//Set attack range
		}
		else
		{
			if (field[y - 1][x] == 1 && 0 <= y - 1 && y - 1 < 9 && 0 <= x && x < 9) {
				field[y - 1][x] = 2; a = 1;
			}
			if (field[y + 1][x] == 1 && 0 <= y + 1 && y + 1 < 9 && 0 <= x && x < 9) {
				field[y + 1][x] = 2; a = 1;
			}
			if (field[y][x - 1] == 1 && 0 <= y && y < 9 && 0 <= x - 1 && x - 1 < 9) {
				field[y][x - 1] = 2; a = 1;
			}
			if (field[y][x - 2] == 1 && 0 <= y && y < 9 && 0 <= x - 2 && x - 2 < 9) {
				field[y][x - 2] = 2; a = 1;
			}//Set attack range
		}
		if (a == 1)
			return true;
		return false; 
	}
	Squirtle(int pNum) : pokemon(pNum) {
		if (pNum == 1)
		{
			set_x(0);
			set_y(3);
		}
		else
		{
			set_x(8);
			set_y(3);
		}
		set_type('W');
	}//initial setting

	~Squirtle()
	{
		set_x(NULL);
		set_y(NULL);
		set_hp(0);
		set_death(1);
	}
};

class Bulbasaur : public pokemon
{
private:

public:
	virtual bool Attack(int(*field)[9], char direction) {
		int x = get_x();
		int y = get_y();
		int a = 0;
		if (direction == 'R')
		{
			if (field[y - 1][x] == 1 && 0 <= y - 1 && y - 1 < 9 && 0 <= x && x < 9) {
				field[y - 1][x] = 2; a = 1;
			}
			if (field[y + 1][x] == 1 && 0 <= y + 1 && y + 1 < 9 && 0 <= x && x < 9) {
				field[y + 1][x] = 2; a = 1;
			}
			if (field[y - 1][x + 1] == 1 && 0 <= y - 1 && y - 1 < 9 && 0 <= x + 1 && x + 1 < 9) {
				field[y - 1][x + 1] = 2; a = 1;
			}
			if (field[y][x + 1] == 1 && 0 <= y && y < 9 && 0 <= x+1 && x+1 < 9) {
				field[y][x + 1] = 2; a = 1;
			}
			if (field[y + 1][x + 1] == 1 && 0 <= y + 1 && y + 1 < 9 && 0 <= x + 1 && x + 1 < 9) {
				field[y + 1][x + 1] = 2; a = 1;
			}//Set attack range

		}
		else
		{
			if (field[y - 1][x] == 1 && 0 <= y - 1 && y - 1 < 9 && 0 <= x && x < 9) {
				field[y - 1][x] = 2; a = 1;
			}
			if (field[y + 1][x] == 1 && 0 <= y + 1 && y + 1 < 9 && 0 <= x && x < 9) {
				field[y + 1][x] = 2; a = 1;
			}
			if (field[y - 1][x - 1] == 1 && 0 <= y - 1 && y - 1 < 9 && 0 <= x - 1 && x - 1 < 9) {
				field[y - 1][x - 1] = 2; a = 1;
			}
			if (field[y][x - 1] == 1 && 0 <= y && y < 9 && 0 <= x - 1 && x - 1 < 9) {
				field[y][x - 1] = 2; a = 1;
			}
			if (field[y + 1][x - 1] == 1 && 0 <= y + 1 && y + 1 < 9 && 0 <= x - 1 && x - 1 < 9) {
				field[y + 1][x - 1] = 2; a = 1;
			}//Set attack range
		}

		if (a == 1)
			return true;

		return false; 
	}
	Bulbasaur(int pNum) : pokemon(pNum) {
		if (pNum == 1)
		{
			set_x(0);
			set_y(5);
		}
		else
		{
			set_x(8);
			set_y(5);
		}
		set_type('G');
	}//initial setting

	~Bulbasaur()
	{
		set_x(NULL);
		set_y(NULL);
		set_hp(0);
		set_death(1);
	}
};

class Pikachu : public pokemon
{
private:

public:
	virtual bool Attack(int(*field)[9], char direction) {
		int x = get_x();
		int y = get_y();
		int a = 0;
		if (direction == 'R')
		{
			if (field[y][x + 1] == 1 && 0 <= y && y < 9 && 0 <= (x + 1) && (x + 1) < 9) {
				field[y][x + 1] = 2; a = 1;
			}
			if (field[y + 1][x + 2] == 1 && 0 <= y + 1 && y + 1 < 9 && 0 <= x + 2 && x + 2 < 9) {
				field[y + 1][x + 2] = 2; a = 1;
			}
			if (field[y][x + 2] == 1 && 0 <= y && y < 9 && 0 <= x + 2 && x + 2 < 9) {
				field[y][x + 2] = 2; a = 1;
			}
			if (field[y - 1][x + 2] == 1 && 0 <= y - 1 && y - 1 < 9 && 0 <= x + 2 && x + 2 < 9) {
				field[y - 1][x + 2] = 2; a = 1;
			}//Set attack range
		}
		else
		{
			if (field[y][x - 1] == 1 && 0 <= y && y < 9 && 0 <= x - 1 && x - 1 < 9) {
				field[y][x - 1] = 2; a = 1;
			}
			if (field[y + 1][x - 2] == 1 && 0 <= y + 1 && y + 1 < 9 && 0 <= x - 2 && x - 2 < 9) {
				field[y + 1][x - 2] = 2; a = 1;
			}
			if (field[y][x - 2] == 1 && 0 <= y && y < 9 && 0 <= x - 2 && x - 2 < 9) {
				field[y][x - 2] = 2; a = 1;
			}
			if (field[y - 1][x - 2] == 1 && 0 <= y - 1 && y - 1 < 9 && 0 <= x - 2 && x - 2 < 9) {
				field[y - 1][x - 2] = 2; a = 1;
			}//Set attack range
		}
		if (a == 1)
			return true;
		return false; 
	}
	Pikachu(int pNum) : pokemon(pNum) {
		if (pNum == 1)
		{
			set_x(0);
			set_y(7);
		}
		else
		{
			set_x(8);
			set_y(7);
		}
		set_type('E');
	}//initial setting

	~Pikachu()
	{
		set_x(NULL);
		set_y(NULL);
		set_hp(0);
		set_death(1);
	}
};