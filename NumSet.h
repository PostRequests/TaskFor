#pragma once
#include <iostream>
#include <string>
#include <vector>
//#include "MyLib/str/str.h"

class NumSet
{
private:
	std::vector <int> numSet;
public:
	//Конструкторы
	NumSet() : numSet() {}
	NumSet(const std::initializer_list<int> il) : numSet(il) {}
	NumSet(const std::string& s) : NumSet() { copy(s); }
	NumSet(const NumSet& o) : NumSet() { add(o); }
	NumSet(int* n, int s) : NumSet() { copy(n, s); }
	NumSet(int n) : NumSet() { copy(n); }
	//Деструктор
	~NumSet() {  }
	//Операторы
	inline bool operator==(const NumSet& o) { return include(o); }
	inline NumSet& operator=(const NumSet& o) { return copy(o); }
	inline NumSet& operator+=(const NumSet& o) { return add(o); }
	inline operator std::string const() { return conclusion(); }
	NumSet& operator-=(const NumSet& o);
	NumSet& operator*=(const NumSet& o);
	NumSet& operator/=(const NumSet& o);
	NumSet operator+(const NumSet& o);
	NumSet operator-(const NumSet& o);
	NumSet operator*(const NumSet& o);
	NumSet operator/(const NumSet& o);
	//Методы
	//Клонирует содержимое объекта из другого объекта
	NumSet& copy(const NumSet& o);
	//Клонирует из числа в объект
	NumSet& copy(int n);
	//Клонирует из массива в объект
	NumSet& copy(const int* n, int s);
	//Клонирует из строки в объект
	NumSet& copy(const std::string& s);
	//Преобразует объект в строку
	std::string conclusion();
	//Проверяет соответствие объектов
	bool include(const NumSet& o);
	//Проверяет наличие числа в объекте
	bool include(int n);
	//Добавляем элементы
	NumSet& add(const NumSet& o);
	//Выводим на экран объект множества
	NumSet& show();
};

std::ostream& operator << (std::ostream& o, NumSet s);

std::istream& operator >> (std::istream& o, NumSet& s);