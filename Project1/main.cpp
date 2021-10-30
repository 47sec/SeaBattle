#include <iostream>

class Ship
{
	short length, x_start, x_end, y_start, y_end;

public:
	Ship(int ship_length);
	short getXStart();
	short getXEnd();
	short getYStart();
	short getYEnd();

};
Ship::Ship(int ship_length)
{
	length = ship_length;
	x_start = 5 - length / 2;
	x_end = x_start + length;
	y_start = y_end = 5;
}

short Ship::getXStart()
{
	return x_start-1;
}

short Ship::getXEnd()
{
	return x_end-1;
}

short Ship::getYStart()
{
	return y_start-1;
}

short Ship::getYEnd()
{
	return y_end-1;
}

class Field
{
	char field_image[10][10];

public:
	Field();
	void printField();
	void setShip(Ship ship);
};

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


int main()
{
	Field left_field;
	left_field.printField();
	Ship ship_x4 (4);
	left_field.setShip(ship_x4);
	std::cout << std::endl;
	left_field.printField();
}