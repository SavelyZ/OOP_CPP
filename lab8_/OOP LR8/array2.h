#pragma once
#include <iostream>
#include <conio.h>

class myArr

{
	int** mas; //указатель на массив

	int n, m; //количество строк и столбцов

public:

	myArr();

	myArr(int, int); //конструктор

	myArr(myArr&); //конструктор копирования

	void ReadMas(); //ввод массива с клавиатуры

	void WriteMas(); //вывод элементов массива на экран

	~myArr(); //деструктор

	operator int(); //перегрузка операции приведения типа

	friend myArr operator*(myArr&, myArr&); //дружественная функция перегрузки операции умножения

	void operator=(const myArr&); //перегрузка операции присвоения

	friend myArr operator*(const myArr&, const int&);

	friend myArr operator+(const myArr&, const int&);

	friend bool operator==(const myArr&, const myArr&);

	friend myArr& operator++(myArr&);
};