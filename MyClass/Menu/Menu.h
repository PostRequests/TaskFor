#pragma once
#include "../Color/Color.h"
#include "../Position/Position.h"
#include "../Box/Box.h"
#include "ItemM.h"
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
	std::vector<MenuItem> elem;
	Box xBox;

	

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
	Menu() :start(2, 2), cur(0), count(0), width(0), head() {  cH.setColor(RedBG); }
	Menu(int x, int y, int cur, int count, int width, std::string h)
		: start(x + 1 , y + 1), cur(0), count(0), width(0)	{
		setHead(h);
		cH.setBG(RedBG);
	}
	Menu(int x, int y, std::string h) :Menu(x, y, 0, 0, 0, h) {}

	//Устанавливаем основной цвет меню
	Menu& setColorText(int BG, int FG);
	//Добавляем элемент меню к меню
	//inline Menu& addItem(const std::string& head) { return addItem(head, nullptr); }
	Menu& addItem(const std::string& head, const std::function<void()>& fEnter);
	Menu& addItem(const std::string& head, const std::function<void()>& fEnter, const std::function<void()>& fmove);
	Menu& setBox(int x, int y, int x2, int y2);
	Menu& setBox(Position& s, Position& e);
	Menu& printBox(const std::string& text);
	Menu& clsBox();
	//Устанавливаем шапку меню
	Menu& setHead(std::string h);
	//Запуск меню, возвращает выбранный элемент меню
	int run();
	inline int getWidth() { return width; }

	
};
