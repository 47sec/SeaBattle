#pragma once
#include "Ship.h"
#include <vector>
class Field
{
	std::vector <std::vector<char>> field_image;
	std::vector <Ship> ships;	//может использовать что-то другое?
	
public:
	static int size_of_fields;

public:
	Field();
	void printField();
	void printString(int num_of_str);
	void setShip(Ship ship);
	int getSizeOfField();
};