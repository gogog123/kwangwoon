#include "pokemon.h"

pokemon::pokemon(int pNum)
{
	playerNum = pNum;
	hp = 3;
}

bool pokemon::move(char c, int(*field)[9])
{
	field[y][x] = 0;
	if (c == 'U')
	{
		if (y == 0)
			return false;
		y = y - 1;
	}
	else if (c == 'D')
	{
		if (y == 8)
			return false;
		y = y + 1;
	}
	else if (c == 'R')
	{
		if (x == 8)
			return false;
		x = x + 1;
	}
	else if (c == 'L')
	{
		if (x == 0)
			return false;
		x = x - 1; 
	}
	field[y][x] = 1;

	return true;
} //move function
