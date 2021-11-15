#include "Interface.h"
void hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

int interfaceMenu
(
	/*
	* 0 - tittle screen
	* 1 - main_menu
		* 11 - new game
			* 111 player vs cpu
				* 1111 easy
					* 11111 manual placement
					* 11112 auto placement
					* 11113 back
				* 1112 hard
					* 11121 manual placement
					* 11122 auto placement 
					* 11123 back
				* 1113 back
			* 112 cpu vs cpu
				* 1121 easy
				* 1122 hard
				* 1123 back
			* 113 back
		* 12 - continue
		* 13 - about
		* 14 - exit
	*/
	int current_menu
)
{
	int counter = 0, current_position = 0, current_menu_size = 0;
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 30;                   // Width of each character in the font
	cfi.dwFontSize.Y = 30;                  // Height
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	
	switch (current_menu)
	{
	case 0:
		while (_kbhit() == 0)
		{
			Sleep(500);
			system("cls");
			std::cout << "\n\n\n\t\t\t SEA BATTLE";
			Sleep(500);
			std::cout << "\n\t\t\tpress any key";
		}

		return 1;
		break;
	case 1:
		return
			drawMenu(current_menu,
				"New Game", "Continue", "About", "Exit");
		break;
	case 11:
		return
			drawMenu(current_menu,
				"Player vs CPU", "CPU vs CPU", "New String", "Back");
		break;
	case 111:
		return
			drawMenu(current_menu,
				"Easy", "Hard", "Back");
		break;
	case 1111:
		return
			drawMenu(current_menu,
				"Manual placement", "Auto placement", "Back");
		break;
	case 1112:
		return
			drawMenu(current_menu,
				"Manual placement", "Auto placement", "Back");
	case 112:
		return
			drawMenu(current_menu,
				"Easy", "Hard", "Back");
	}
}

template <typename T>
void printMenu(int counter, int current_position, T t)
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
		std::cout << " " << t << std::endl;
	}
	counter++;
	printMenu(counter, current_position, args...);
}

template <typename T>
void countMenuSize(int& counter, T t)
{
	counter++;
}

template <typename T, typename... Args>
void countMenuSize(int& counter, T t, Args... args)
{
	counter++;
	countMenuSize(counter, args...);
}

template <typename... Args>
int drawMenu(int current_menu, Args... args)
{
	int current_position = 0;
	int current_menu_size = 0;
	int counter = 0;
	countMenuSize(current_menu_size, args...);
	system("cls");
	printMenu(counter, current_position,
		args...);
	do
	{
		switch (_getch())
		{
		case 72:
			if (current_position > 0)
				current_position--;
			else
				current_position = current_menu_size - 1;
			break;
		case 80:
			if (current_position < current_menu_size - 1)
				current_position++;
			else
				current_position = 0;
			break;
		case 13:
			//Костыль оставил в комменте.Сделал более лаконично
			if (
				/*(
					current_menu == 11 ||
					current_menu == 111 || current_menu == 112 ||
					current_menu == 1111 || current_menu == 1112
					)*/
				current_menu > 1
				&& current_position == current_menu_size - 1
				)
				return current_menu / 10;
			else
				return current_menu * 10 + (current_position + 1);
			break;
		}
		system("cls");
		printMenu(counter, current_position,
			args...);
	} while (true);
}

