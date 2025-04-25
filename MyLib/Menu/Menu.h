#pragma once
#include "../console/Console.h"

#include <string>
#include <vector>
#include <functional>
#include <iostream>
class Menu
{
private:
	int posX;//������� ����� ���� ������� �
	int posY;//������� ����� ���� ������� �
	int cur;//������� ��������� ����� ��������
	int count;//���������� ���� ���������
	int width;//������ ����
	bool visible = false;//���������� ��������� ���� �� ������
	int cb = RedBG;//���� ���������
	std::string head;//��������� ����
	std::vector<std::string> elMenu;//�������� ��������� ����
	std::vector<std::function<void()>> func;//������� ���������� ��� ������� 

	//��������� � ������� ������� ����
	void strToVector(std::string s) { if(!s.empty()) elMenu.push_back(s); }
	//��������� � ������� �������
	void functionToVector(std::function<void()> f) { if (f) func.push_back(f); }
	//������������� ������������ ������ ����
	void calcWidth(std::string s) { width = std::max( width,(int)s.length() + 3); }
	//�������� �������� ����
	void printElMenu();
	//������� �� ����� ����
	void show();
	//������������� ������� ����
	void redrawItem(int color);
	//������� ���� � ������
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
	//���������� ������� ���� � ����
	Menu& addItem(std::string el) { return addItem(el, [](){}); }
	Menu& addItem(std::string el, std::function<void()> f);
	//������������� ����� ����
	Menu& setHead(std::string h);
	//������ ����, ���������� ��������� ������� ����
	int run();
	

	
};
