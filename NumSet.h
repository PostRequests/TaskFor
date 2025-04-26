#pragma once
#include <iostream>
#include "MyLib/str/str.h"

class NumSet
{
private:
	int* numSet;
	int size;
		
public:
	
	//Конструкторы
	NumSet() : numSet(nullptr), size(0) {}
	NumSet(const NumSet& o) : NumSet() { add(o); }
	NumSet(int* n, int s) : NumSet() { copy(n, s); }
	NumSet(const char* s) : NumSet() { copy(s); }
	NumSet(int n) : NumSet() { copy(n); }
	//Деструктор
	~NumSet() { clear(); }
	//Операторы
	inline bool operator==(const NumSet& o) { return include(o); }
	inline NumSet& operator=(const NumSet& o) { return copy(o); }
	inline NumSet& operator+=(const NumSet& o) { return add(o); }
	inline operator str const() { return conclusion(); }
	NumSet& operator-=(const NumSet& o);
	NumSet& operator*=(const NumSet& o);
	NumSet& operator/=(const NumSet& o);
	NumSet operator+(const NumSet& o);
	NumSet operator-(const NumSet& o);
	NumSet operator*(const NumSet& o);
	NumSet operator/(const NumSet& o);
	//Методы
	//Клонирует содежимое объекта из другого объекта
	NumSet& copy(const NumSet& o);
	//Клонирует из числа в объект
	NumSet& copy(int n);
	//Клонирует из массива в объект
	NumSet& copy(const int* n, int s);
	//Клонирует из строки в объект
	NumSet& copy(const char* s);
	//Преобразует объект в строку
	str const conclusion();
	//Проверяет соответствие объектов
	bool include(const NumSet& o);
	//Проверяет наличие числа в объекте
	bool include(int n);
	//Добавляем элементы
	NumSet& add(const NumSet& o);
	//Очищаем указатели в объекте
	NumSet& clear();
	//Выводим на экран объект множества
	NumSet& show();
};
//Перегрузка оператора std::cout <<
std::ostream& operator << (std::ostream& o, NumSet& s);
//Перегрузка оператора std::cin >>
std::istream& operator >> (std::istream& o, NumSet& s);