#include <iostream>
#include <string>
#include <cwchar>
#include <array>
#include "Ship.h"
#include "Field.h"
#include "Interface.h"


void fieldsPaint(Field lfield, Field rfield);
void configGame(int current_menu, std::array <bool, 3> &config_array);
void setShips(std::array <bool, 3>& config_array)
{
	
}

int main()
{
	/*
	* 0 - mode (player)
	* 1 - difficulty (easy)
	* 2 - placement (manual)
	*/
	std::array <bool, 3> game_config_array = { 1,1,0 };
	hideCursor();
	Field left_field, right_field;
	int current_menu = 0;
	//Навигация по меню-----------------------------------
	while (current_menu != 14)
	{
		configGame(current_menu, game_config_array);
		//ещё один костыль (более глубокое меню - будет ошибка)
		if (current_menu > 10000 || current_menu == 1121 || current_menu == 1122)
			break;
		current_menu = interfaceMenu(current_menu);
	}
	if (current_menu == 14) return 0;
	//Конец навигации по меню------------------------------
	//fieldsPaint(left_field, right_field);
	Ship ship_x3(9, left_field.getSizeOfField());
	std::vector <Ship> ships_left_filed;
	ships_left_filed.push_back(ship_x3);
	int ch = 0;
		do
		{
			left_field.reInitFieldCorrdArr(ships_left_filed);
			//system("cls");
			fieldsPaint(left_field, right_field);
			std::cout << ships_left_filed.at(0).getXStart() << ":" <<
				ships_left_filed.at(0).getXEnd() << std::endl;
			std::cout << ships_left_filed.at(0).getYStart() << ":" <<
				ships_left_filed.at(0).getYEnd() << std::endl;

			switch (ch=_getch())
			{
			case 72:	//вверх
				ships_left_filed.at(0).moveShip(0, -1);
				break;
			case 80:	//вниз
				ships_left_filed.at(0).moveShip(0, 1);
				break;
			case 75:	//влево
				ships_left_filed.at(0).moveShip(-1, 0);
				break;
			case 77:	//вправо
				ships_left_filed.at(0).moveShip(1, 0);
				break;
			case 32:
				ships_left_filed.at(0).rotateShip();
				break;
			}
		} while (true);
}


void fieldsPaint(Field lfield, Field rfield)
{
	system("cls");
	for (size_t i = 0; i < Field::size_of_fields; i++)
	{
		lfield.printString(i);
		std::cout << "\t\t";
		rfield.printString(i);
		std::cout << std::endl;
	}
}

void configGame(int current_menu, std::array <bool, 3> &config_array)
{
	if (current_menu == 111) config_array[0] = true;
	if (current_menu == 112) config_array[0] = false;
	if (current_menu == 1111 || current_menu == 1121) config_array[1] = true;
	if (current_menu == 1112 || current_menu == 1122) config_array[1] = false;
	if (current_menu == 11111 || current_menu == 11121) config_array[2] = true;
	if (current_menu == 11112 || current_menu == 11122)config_array[2] = false;

}