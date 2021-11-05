#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>
void hideCursor();

int interfaceMenu(int current_position);

template <typename T>
void printMenu(int counter, int current_position, T t);

template <typename T, typename... Args>
void printMenu(int counter, int current_position, T t, Args... args);

template <typename T>
void countMenuSize(int& counter, T t);

template <typename T, typename... Args>
void countMenuSize(int& counter, T t, Args... args);

template <typename... Args>
int drawMenu(int current_menu, Args... args);