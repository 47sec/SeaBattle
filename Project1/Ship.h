#pragma once
#include <vector>
class Ship
{
	short length, x_start, x_end, y_start, y_end;
	std::vector <bool> damage;
public:
	Ship(int ship_length, int size_of_field);
	short getXStart();
	short getXEnd();
	short getYStart();
	short getYEnd();

};