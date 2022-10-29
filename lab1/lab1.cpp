// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

void printBytes() {
	cout << "Сколько памяти занимают различные типы данных:\n";
	cout << "int: " << sizeof(int) << endl << "short int: " << sizeof(short int) << endl << "long int: " << sizeof(long int) << endl
		<< "float: " << sizeof(float) << endl << "double: " << sizeof(double) << endl << "long double: " << sizeof(long double) << endl
		<< "char: " << sizeof(char) << endl << "bool: " << sizeof(bool) << endl;
}

void printInt(int value) {
	unsigned int order = sizeof(value) * 8;
	unsigned int mask = 1 << (order - 1);
	for (int i = 1; i <= order; i++)
	{
		putchar(value & mask ? '1' : '0');
		mask >>= 1;
		if (i % 8 == 0)
		{
			putchar(' ');
		}
		if (i % order - 1 == 0)
		{
			putchar(' ');
		}
	}
	cout << " " << "(" << value << ")";
	cout << endl;
}

void printFloat(int value) {
	unsigned int order = sizeof(value) * 8;
	unsigned int mask = 1 << (order - 1);
	for (int i = 1; i <= order; i++) {
		putchar(value & mask ? '1' : '0');
		mask >>= 1;
		if (i <= 9)
		{
			if (i == 1 || i == 9) putchar(' ');
		}
		else if (i % 4 == 1)
		{
			putchar(' ');
		}
	}
	cout << " " << "(" << value << ")";
	cout << endl;
}

void invertBits(int number, bool isInt) {
	cout << endl << "Инвертировать биты? (введите y/n): ";
	char answer;
	cin >> answer;
	int num;
	if (answer == 'y') {
		cout << "Введите количество битов, которые не нужно инвертировать: ";
		cin >> num;
		int* bits = new int[num];
		cout << endl << "Введите номера битов, которые не нужно инвертировать: ";
		for (int i = 0; i < num; i++) {
			cin >> bits[i];
		}
		sort(bits, bits + num);
		unsigned int order = sizeof(number) * 8;
		unsigned int mask = ~0, temp;
		for (int i = 0; i < num; i++)
		{
			temp = 1 << bits[i];
			mask = mask ^ temp;
		}
		number = number ^ mask;
		if (isInt) printInt(number);
		else printFloat(number);
	}
}

void repeat() {
	cout << "Введите int: ";
	int value;
	cin >> value;
	printInt(value);
	invertBits(value, true);
	cout << endl;
	union {
		float value_float;
		int tool;
	};
	cout << "Введите float: ";
	cin >> value_float;
	printFloat(tool);
	invertBits(tool, false);
	char t;
	cout << endl << "Повторить выполнение программы (введите y/n): ";
	cin >> t;
	if (t == 'y') repeat();
}

int main()
{
	setlocale(0, "");
	printBytes();
	repeat();

	return 0;
}
