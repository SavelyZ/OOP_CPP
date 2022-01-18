#include "array2.h"
#include <iostream>
using namespace std;

myArr::myArr(int a, int b) 
{
	n = a; m = b; //динамически выделяем память под двумерный массив
	mas = new int* [n];

	for (int i = 0; i < n; i++)
		mas[i] = new int[m];
}

myArr::myArr(myArr& srcArr)
{
	n = srcArr.n; m = srcArr.m;
	mas = new int* [n];

	for (int i = 0; i < n; i++)
		mas[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mas[i][j] = srcArr.mas[i][j];

}

void myArr::ReadMas() 
{

	cout << "Введите массив ("<<n<<' '<<m<<") \n";

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mas[i][j];
}

void myArr::WriteMas() {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << mas[i][j] << '\t';

		cout << '\n';
	}
}

myArr::~myArr()
{
	for (int i = 0; i < n; i++)
		delete[] mas[i];

	delete[]mas;
}

myArr operator*(myArr& m1, myArr& m2) //внешняя функция
//перегрузки операции умножения
{
	if (m1.m == m2.n)
	{
		myArr tmp(m1.n, m2.m);
		int s;

		for (int i = 0; i < m1.n; i++)
		{
			for (int j = 0; j < m2.m; j++)
			{
				s = 0;

				for (int k = 0; k < m1.m; k++)
					s += m1.mas[i][k] * m2.mas[k][j];

				tmp.mas[i][j] = s;
			}
		}

		return tmp;
	}
	else std::cout<<"Не совпадают размеры массивов \n";
}

myArr operator*(const myArr& m, const int& mn)
{
	myArr res(m.n, m.m);

	for (int i = 0; i < m.n; i++)
		for (int j = 0; j < m.m; j++)
			res.mas[i][j] = m.mas[i][j] * mn;

	return res;
}

myArr operator+(myArr&, int&)
{
	//?
	myArr res(0, 0);
	return res;
}

bool operator==(const myArr& m1, const myArr& m2)
{
	if (m1.n == m2.n && m1.m == m2.m) {
		for (int i = 0; i < m1.n; i++)
			for (int j = 0; j < m1.m; j++)
			{
				if (m1.mas[i][j] != m2.mas[i][j])
					return false;
			}
	}
	else return false;

	return true;
}

myArr& operator++(myArr& m)
{
	myArr res(m.m, m.n);

	for (int i = 0; i < m.n; i++)
		for (int j = 0; j < m.m; j++)
			res.mas[j][i] = m.mas[i][j];
	m = res;
	return res;
}

myArr::operator int()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sum += mas[i][j];

	return sum;
}

void myArr::operator=(const myArr& m2)
{
	if (this->n == m2.n && this->m == m2.m)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				mas[i][j] = m2.mas[i][j];

	else std::cout << "Не совпадают размеры массивов \n";
}

