#pragma once
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