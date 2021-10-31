#include "Field.h"
#include <iostream>

Field::Field()
{
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			field_image[i][j] = '+';
		}
	}
}

void Field::printField()
{
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			std::cout << field_image[j][i] << " ";
		}
		std::cout << std::endl;
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
}