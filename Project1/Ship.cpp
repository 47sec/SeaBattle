#include "Ship.h"

Ship::Ship(int ship_length)
{
	length = ship_length;
	x_start = 5 - length / 2;
	x_end = x_start + length;
	y_start = y_end = 5;
}

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