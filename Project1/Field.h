#pragma once
#include "Ship.h"
#include <vector>
class Field
{
	char field_image[10][10];
	std::vector <Ship> vect;
public:
	Field();
	void printField();
	void setShip(Ship ship);
};