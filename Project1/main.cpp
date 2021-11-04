#include <iostream>
#include <string>
#include <Windows.h>
#include <cwchar>
#include <conio.h>
#include "Ship.h"
#include "Field.h"



void fieldsPaint(Field lfield, Field rfield);
int interfaceMenu(int current_position);
void hideCursor();


template <typename T>
void printMenu(int counter, int current_position,T t)
{
	if (current_position == counter)
	{
		std::cout << "=" << t << "=\n";
	}
	else
	{
		std::cout << " " << t << std::endl;
	}
	counter++;
}

template <typename T, typename... Args>
void printMenu(int counter, int current_position, T t, Args... args)
{
	if (current_position == counter)
	{
		std::cout << "=" << t << "=\n";
	}
	else
	{
		std::cout<< " " << t << std::endl;
	}
	counter++;
	printMenu(counter,current_position,args...);
}

int main()
{
	hideCursor();
	Field left_field, right_field;
	int current_menu = 0;
	while (current_menu != 14)
	{
		current_menu = interfaceMenu(current_menu);
		//_getch();
	}


}

void hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void fieldsPaint(Field lfield, Field rfield)
{
	for (size_t i = 0; i < Field::size_of_fields; i++)
	{
		lfield.printString(i);
		std::cout << "\t\t";
		rfield.printString(i);
		std::cout << std::endl;
	}
}

int interfaceMenu(int current_menu)
{
	int counter = 0, current_position = 0;
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 30;                   // Width of each character in the font
	cfi.dwFontSize.Y = 30;                  // Height
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	/*
	* 0 - tittle screen
	* 1 - main_menu
	* 11 - new game
	* 12 - continue
	* 13 - about
	* 14 - exit
	*/
	switch (current_menu)
	{
	case 0:
		while (_kbhit()==0)
		{
			Sleep(500);
			system("cls");
			Sleep(500);
			std::cout << "\n\n\n\t\t\t SEA BATTLE";
			std::cout << "\n\t\t\tpress any key";
		}
		return 1;
		break;

	case 1:
		system("cls");
		printMenu(counter, current_position,
			"New Game", "Continue", "About", "Exit");
		while (_kbhit() != 28)
		{
			system("cls");
			switch (_getch())
			{
			case 72:
				if (current_position > 0)
					current_position--;
				else
					current_position = 3;
				break;
			case 80:
				if (current_position < 3)
					current_position++;
				else
					current_position = 0;
				break;
			case 28:

				break;
			}
			printMenu(counter, current_position,
				"New Game", "Continue", "About", "Exit");
		}
		break;
	}
	return 0;
}
