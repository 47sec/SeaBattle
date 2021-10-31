#include <iostream>
#include "Ship.h"
#include "Field.h"

int main()
{
	Field left_field;
	left_field.printField();
	Ship ship_x4 (4);
	left_field.setShip(ship_x4);
	std::cout << std::endl;
	left_field.printField();
}