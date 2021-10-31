#include <iostream>
#include "Ship.h"
#include "Field.h"



void interfacePaint(Field lfield, Field rfield);

int main()
{
	Field left_field, right_field;
	Ship ship_x4 (4);
	left_field.setShip(ship_x4);
	interfacePaint(left_field,right_field);
}

void interfacePaint(Field lfield, Field rfield)
{
	for (size_t i = 0; i < Field::size_of_fields; i++)
	{
		lfield.printString(i);
		std::cout << "\t\t";
		rfield.printString(i);
		std::cout << std::endl;
	}
}