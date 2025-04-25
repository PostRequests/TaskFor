#pragma once
#include "../console/Console.h"

#include <string>
#include <vector>
#include <functional>
#include <iostream>
class Menu
{
private:
	int posX;//Верхний левый угол позиция Х
	int posY;//Верхний левый угол позиция У
	int cur;//Текущий выбранный номер элемента
	int count;//Количество всех элементов
	int width;//Ширина меню
	bool visible = false;//Отображает видимость юеню на экране
	int cb = RedBG;//Цвет выделения
	std::string head;//Заголовок меню
	std::vector<std::string> elMenu;//Названия элементов меню
	std::vector<std::function<void()>> func;//Функции вызываемые при нажатии 

	//Добавляем к вектору елемент менб
	void strToVector(std::string s) { if(!s.empty()) elMenu.push_back(s); }
	//Добавляем к вектору функцию
	void functionToVector(std::function<void()> f) { if (f) func.push_back(f); }
	//Устанавливаем максимальную ширину меню
	void calcWidth(std::string s) { width = std::max( width,(int)s.length() + 3); }
	//Печатаем элементы меню
	void printElMenu();
	//Выводим на экран меню
	void show();
	//Перекрашиваем элемент меню
	void redrawItem(int color);
	//Очищаем меню с экрана
	void hide() { drawFillRectangle(posX, posY, count *2 + 3, width + 1); }
public:
	Menu() : posX(1), posY(1), cur(0), count(0), width(0), head(), elMenu(), func() {}
	Menu(int x, int y, int cur, int count, int width, std::string h, std::string el, std::function<void()> f)
		: posX(x), posY(y), cur(0), count(0), width(0)	{
		setHead(h);
		strToVector(el);
		functionToVector(f);
	}
	Menu(int x, int y, std::string h) :Menu(x, y, 0, 0, 0, h, "", nullptr) {}
	//Добавляемт элемент меню к меню
	Menu& addItem(std::string el) { return addItem(el, [](){}); }
	Menu& addItem(std::string el, std::function<void()> f);
	//Устанавливаем шапку меню
	Menu& setHead(std::string h);
	//Запуск меню, возвращает выбранный элемент меню
	int run();
	

	
};
