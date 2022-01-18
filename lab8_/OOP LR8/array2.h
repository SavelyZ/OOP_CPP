#pragma once
#include <iostream>
#include <conio.h>

class myArr

{
	int** mas; //��������� �� ������

	int n, m; //���������� ����� � ��������

public:

	myArr();

	myArr(int, int); //�����������

	myArr(myArr&); //����������� �����������

	void ReadMas(); //���� ������� � ����������

	void WriteMas(); //����� ��������� ������� �� �����

	~myArr(); //����������

	operator int(); //���������� �������� ���������� ����

	friend myArr operator*(myArr&, myArr&); //������������� ������� ���������� �������� ���������

	void operator=(const myArr&); //���������� �������� ����������

	friend myArr operator*(const myArr&, const int&);

	friend myArr operator+(const myArr&, const int&);

	friend bool operator==(const myArr&, const myArr&);

	friend myArr& operator++(myArr&);
};