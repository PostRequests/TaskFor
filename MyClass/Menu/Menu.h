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
	int cur;//������� ��������� ����� ��������
	int count;//���������� ���� ���������
	int width;//������ ����
	bool visible = false;//���������� ��������� ���� �� ������
	Color cH;//���� ���������
	Color cT;//�������� ���� ����
	std::string head;//��������� ����
	std::vector<MenuItem> elem;
	Box xBox;

	

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
	Menu() :start(2, 2), cur(0), count(0), width(0), head() {  cH.setColor(RedBG); }
	Menu(int x, int y, int cur, int count, int width, std::string h)
		: start(x + 1 , y + 1), cur(0), count(0), width(0)	{
		setHead(h);
		cH.setBG(RedBG);
	}
	Menu(int x, int y, std::string h) :Menu(x, y, 0, 0, 0, h) {}

	//������������� �������� ���� ����
	Menu& setColorText(int BG, int FG);
	//��������� ������� ���� � ����
	//inline Menu& addItem(const std::string& head) { return addItem(head, nullptr); }
	Menu& addItem(const std::string& head, const std::function<void()>& fEnter);
	Menu& addItem(const std::string& head, const std::function<void()>& fEnter, const std::function<void()>& fmove);
	Menu& setBox(int x, int y, int x2, int y2);
	Menu& setBox(Position& s, Position& e);
	Menu& printBox(const std::string& text);
	Menu& clsBox();
	//������������� ����� ����
	Menu& setHead(std::string h);
	//������ ����, ���������� ��������� ������� ����
	int run();
	inline int getWidth() { return width; }

	
};
