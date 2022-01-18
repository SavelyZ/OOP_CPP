#include "array2.h"
#include <iostream>

using namespace std;

int main()
 {
	setlocale(LC_ALL, "RUSSIAN");
	myArr m(2, 4), m1(4, 4), m2(2, 4), m3(4, 4), m4(4,4);
	m.ReadMas();
	m1.ReadMas();
	cout << endl;
	
	cout << "* \n";
	m2 = m * m1;//перемножаем массивы по правилу перемножения матриц
	m2.WriteMas();
	cout << endl;

	cout << "sum elem 2 array \n";
	int c = int(m1); //получаем сумму элементов массива
	cout << c << endl;
	cout << endl;

	cout << "== \n";
	bool v = (m == m1);
	cout << v << endl;
	cout << endl;

	cout << "2 array  * 3 \n";
	m3 = m1 * 3;
	m3.WriteMas();
	cout << endl;

	cout << "transponation array 2 \n";
    ++m1;
	m1.WriteMas();
	
	//getch();
}