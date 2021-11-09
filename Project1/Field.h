#pragma once
#include "Ship.h"
#include <vector>
class Field
{
	std::vector <std::vector<char>> field_image;
	
public:
	static int size_of_fields;

public:
	Field();
	void printField();
	void printString(int num_of_str);
	void setShipInCoordArr(Ship ship);
	int getSizeOfField();
	void reInitFieldCorrdArr(std::vector <Ship>& ships);
};