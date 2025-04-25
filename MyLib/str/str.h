#pragma once
#include "../console/Helper.h"
#include <iostream>
class str
{
private:
	char* s;
	size_t len;

public:
	//Конструкторы
	str() : s(nullptr), len(0) {};
	str(const char* s) : str() {copy(s);}
	//Конструктор копирования
	str(const str& o) :str() { copy(o);	}
	//Оператор присвоения
	str& operator=(const str& o) {return copy(o);}
	//Метод копирования
	str& copy(const str& o) {	return *this;	}
	str& copy(const char* o);
	//Метод очищения указателей и сброса
	str& clear();
	//Метод возвращает указатель на текст
	char * get_s() {return s;}
	//Метод возвращает размер строки
	size_t length() {return len;}
	//Сеттер устанавливающий строку
	str& set_s(const char* s) {	copy(s);}
	//Возвращает int если может преобразовать текст в число или 0
	int toInt() {return strToInt(s);}
	//Метод добавляющий в конец строки текст
	str& cat(const char* s);	
	str& cat(const str o) {	return cat(o.s);}
	//Оператор складывания строк
	str& operator+(const char* s) {	return cat(s);}
	//Оператор складывание строки и целочисленного числа
	str& operator+(int p);
	str& input();
	//Оператор выведения строки
	operator char*() const {return s;}
	//Метод возвращает сравнение 2х текстов
	int cmp(const char* s) {return strcmp(this->s, s);}
	bool operator==(const char* s) {return (cmp(s) == 0);}
	bool operator<(const str& s) {	return (cmp(s) == -1);	}
	bool operator>(const str& s) {	return (cmp(s) == 1);}
	//Деструктор
	~str() {clear();}
};

