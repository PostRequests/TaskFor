#pragma once
#include "../Color/Color.h"
#include "../Position/Position.h"
#include "../Box/Box.h"
#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <conio.h>
class Menu
{
private:
	Position start;
	int cur;//Текущий выбранный номер элемента
	int count;//Количество всех элементов
	int width;//Ширина меню
	bool visible = false;//Отображает видимость меню на экране
	Color cH;//Цвет выделения
	Color cT;//Основной цвет меню
	std::string head;//Заголовок меню
	std::vector<std::string> elMenu;//Названия элементов меню
	std::vector<std::function<void()>> func;//Функции вызываемые при нажатии 

	
	//Добавляем к вектору элемент меню
	void strToVector(std::string s) { if(!s.empty()) elMenu.push_back(s); }
	//Добавляем к вектору функцию
	void functionToVector(std::function<void()> f) { if (f) func.push_back(f); }
	//Устанавливаем максимальную ширину меню
	inline void calcWidth(std::string s) { width = ( (width>(int)s.length() + 3))? width: (int)s.length() + 2; }
	//Печатаем элементы меню
	void printElMenu();
	//Выводим на экран меню
	void show();
	//Перекрашиваем элемент меню
	void redrawItem(Color color);
	//Очищаем меню с экрана
	void hide() {  }
public:
	Menu() :start(2,2), cur(0), count(0), width(0), head(), elMenu(), func() { cH.setBG(RedBG); }
	Menu(int x, int y, int cur, int count, int width, std::string h, std::string el, std::function<void()> f)
		: start(x + 1 , y + 1), cur(0), count(0), width(0)	{
		setHead(h);
		strToVector(el);
		functionToVector(f);
		cH.setBG(RedBG);
	}
	//Устанавливаем основной цвет меню
	Menu& setColorText(int BG, int FG);
	Menu(int x, int y, std::string h) :Menu(x, y, 0, 0, 0, h, "", nullptr) {}
	//Добавляем элемент меню к меню
	inline Menu& addItem(std::string el) { return addItem(el, [](){}); }
	Menu& addItem(std::string el, std::function<void()> f);
	//Устанавливаем шапку меню
	Menu& setHead(std::string h);
	//Запуск меню, возвращает выбранный элемент меню
	int run();
	inline int getWidth() { return width; }

	
};
