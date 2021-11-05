#include "Field.h"
#include <iostream>

int Field::size_of_fields = 10;

Field::Field()
{
	field_image.resize(size_of_fields);
	for (size_t i = 0; i < size_of_fields; i++)
	{
		field_image.at(i).resize(size_of_fields);
	}
	for (size_t i = 0; i < size_of_fields; i++)
	{
		for (size_t j = 0; j < size_of_fields; j++)
		{
			field_image[i][j] = '+';
		}
	}
}

void Field::printField()
{
	for (size_t i = 0; i < size_of_fields; i++)
	{
		for (size_t j = 0; j < size_of_fields; j++)
		{
			std::cout << field_image[j][i] << " ";
		}
		std::cout << std::endl;
	}
}

void Field::printString(int num_of_str)
{
	for (size_t i = 0; i < size_of_fields; i++)
	{
		std::cout << field_image[i][num_of_str] << " ";
	}
}

void Field::setShip(Ship ship)
{
	for (short i = ship.getXStart(); i <= ship.getXEnd(); i++)
	{
		for (short j = ship.getYStart(); j <= ship.getYEnd(); j++)
		{
			field_image[i][j] = 'S';
		}
	}
	ships.push_back(ship);
}

int Field::getSizeOfField()
{
	return size_of_fields;
}