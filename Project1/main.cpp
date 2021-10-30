#include <iostream>

class Ship
{
	short length, x_start, x_end, y_start, y_end;

public:
	Ship(int ship_length);
};
Ship::Ship(int ship_length)
{
	length = ship_length;
	x_start = 5 - length / 2;
	x_end = x_start + length;
	y_start = y_end = 5;
}

class Field
{
	char field_image[10][10];

public:
	void printField();
};

void Field::printField()
{
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			std::cout << field_image[i][j];
		}
		std::cout << std::endl;
	}
}

int main()
{

}