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

void Field::setShipInCoordArr(Ship ship)
{
	int xstart = 0, xend = 0, ystart = 0, yend = 0;
	if (ship.getXStart() > ship.getXEnd())
	{
		xstart = ship.getXEnd();
		xend = ship.getXStart();
	}
	else
	{
		xstart = ship.getXStart();
		xend = ship.getXEnd();
	}
	if (ship.getYStart() > ship.getYEnd())
	{
		ystart = ship.getYEnd();
		yend = ship.getYStart();
	}
	else
	{
		ystart = ship.getYStart();
		yend = ship.getYEnd();
	}
	for (short i = xstart; i <= xend; i++)
	{
		for (short j = ystart; j <= yend; j++)
		{
			field_image[i][j] = 'S';
		}
	}
}

int Field::getSizeOfField()
{
	return size_of_fields;
}

void Field::reInitFieldCorrdArr(std::vector <Ship>& ships)
{
	for (size_t i = 0; i < size_of_fields; i++)
	{
		for (size_t j = 0; j < size_of_fields; j++)
		{
			field_image[i][j] = '+';
		}
	}
	for (size_t i = 0; i < ships.size(); i++)
	{
		setShipInCoordArr(ships.at(i));
	}
}

