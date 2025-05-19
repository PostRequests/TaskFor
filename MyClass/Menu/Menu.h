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
	int cur;//������� ��������� ����� ��������
	int count;//���������� ���� ���������
	int width;//������ ����
	bool visible = false;//���������� ��������� ���� �� ������
	Color cH;//���� ���������
	Color cT;//�������� ���� ����
	std::string head;//��������� ����
	std::vector<std::string> elMenu;//�������� ��������� ����
	std::vector<std::function<void()>> func;//������� ���������� ��� ������� 

	
	//��������� � ������� ������� ����
	void strToVector(std::string s) { if(!s.empty()) elMenu.push_back(s); }
	//��������� � ������� �������
	void functionToVector(std::function<void()> f) { if (f) func.push_back(f); }
	//������������� ������������ ������ ����
	inline void calcWidth(std::string s) { width = ( (width>(int)s.length() + 3))? width: (int)s.length() + 2; }
	//�������� �������� ����
	void printElMenu();
	//������� �� ����� ����
	void show();
	//������������� ������� ����
	void redrawItem(Color color);
	//������� ���� � ������
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
	//������������� �������� ���� ����
	Menu& setColorText(int BG, int FG);
	Menu(int x, int y, std::string h) :Menu(x, y, 0, 0, 0, h, "", nullptr) {}
	//��������� ������� ���� � ����
	inline Menu& addItem(std::string el) { return addItem(el, [](){}); }
	Menu& addItem(std::string el, std::function<void()> f);
	//������������� ����� ����
	Menu& setHead(std::string h);
	//������ ����, ���������� ��������� ������� ����
	int run();
	inline int getWidth() { return width; }

	
};
