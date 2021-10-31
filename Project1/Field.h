#pragma once
#include "Ship.h"
#include <vector>
class Field
{
	static int size_of_fields;
	char field_image[size_of_fields][10];
	std::vector <Ship> ships;	//может использовать что-то другое?
	


public:
	Field();
	void printField();
	void printString(int num_of_str);
	void setShip(Ship ship);
	int getSizeOfField();
};