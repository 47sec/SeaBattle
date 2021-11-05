#include "Ship.h"

Ship::Ship(int ship_length, int size_of_field)
{
	length = ship_length;
	x_start = size_of_field/2 - length / 2;
	x_end = x_start + length;
	y_start = y_end = size_of_field/2;
	damage.resize(length, false);
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