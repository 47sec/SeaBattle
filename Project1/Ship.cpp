#include "Ship.h"

Ship::Ship(int ship_length, int size_of_field)
{
	length = ship_length;
	x_start = (size_of_field-1)/2 - length / 2;
	x_end = x_start + length-1;
	y_start = y_end = (size_of_field-1)/2;
	x_border = size_of_field - 1;
	y_border = size_of_field - 1;
	damage.resize(length, false);
}
//Геттеры--------------------------------------------
short Ship::getXStart()
{
	return x_start - 1;
}

short Ship::getXEnd()
{
	return x_end - 1;
}

short Ship::getYStart()
{
	return y_start - 1;
}

short Ship::getYEnd()
{
	return y_end - 1;
}
//Сеттеры-----------------------------------------------
void Ship::setXStart(short x)
{
	x_start = x;
}

void Ship::setXEnd(short x)
{
	x_end = x;
}

void Ship::setYStart(short y)
{
	y_start = y;
}

void Ship::setYEnd(short y)
{
	y_end = y;
}

void Ship::moveShip(short x_coord_shift, short y_coord_shift)
{
	//ось x
	if ((x_coord_shift > 0) && (x_end <= x_border) && (x_start <= x_border))
	{
		x_start++;
		x_end++;
	}
	if ((x_coord_shift < 0) && (x_start != 1) && (x_end != 1))
	{
		x_start--;
		x_end--;
	}
	//ось y
	if ((y_coord_shift > 0) && (y_end <= y_border) && (y_start <= y_border))
	{
		y_start++;
		y_end++;
	}
	if ((y_coord_shift < 0) && (y_start != 1) && (y_end != 1))
	{
		y_start--;
		y_end--;
	}
}

void Ship::rotateShip()
{
	if (y_start == y_end)
	{
		if (y_start <= (y_border + 1 - length + 1))
			y_end = y_start + (length - 1);
		else
			y_end = y_start - (length - 1);
		x_end = x_start;
	}
	else if (x_start == x_end)
	{
		if (x_start > (x_border + 1 - (length - 1)))
			x_end = x_start - (length - 1);
		else
			x_end = x_start+length-1;
		y_end = y_start;
	}
}