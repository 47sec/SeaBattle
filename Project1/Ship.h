#pragma once
#include <vector>
class Ship
{
	short length, x_start, x_end, y_start, y_end, x_border, y_border;
	std::vector <bool> damage;
public:
	Ship(int ship_length, int size_of_field);
	short getXStart();
	short getXEnd();
	short getYStart();
	short getYEnd();
	void setXStart(short x);
	void setXEnd(short x);
	void setYStart(short y);
	void setYEnd(short y);
	void moveShip(short x_coord_shift, short y_coord_shift);
	void rotateShip();
};