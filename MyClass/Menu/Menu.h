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
	Color �Selected;//���� ��������� ������ ����
	Color cDefault;//�������� ���� ����
	std::string head;//��������� ����
	std::vector<MenuItem> elem;//������� ������ ����
	Box xBox;//������� ��������� ���� �����
	bool boxVisible;
	

	/**
	 * @brief ������������ ������ ����, ����������� ��� ���������� ������ ������ ����
	 * @param s ����� ������ ����, ������������ �������� �������������� ������������ ������
	 */
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
	Menu() :start(2, 2), cur(0), count(0), width(0), head() {  �Selected.setColor(RedBG); }
	Menu(int x, int y, int cur, int count, int width, std::string h)
		: start(x + 1 , y + 1), cur(0), count(0), width(0)	{
		setHead(h);
		�Selected.setColor(RedBG);
	}
	Menu(int x, int y, std::string h) :Menu(x, y, 0, 0, 0, h) {}
	Menu(Position p) :Menu(p.getMinX(), p.getMinY(), 0, 0, 0, "") {}

	//������������� �������� ���� ����
	/**
	 * @brief ������������� 2 ����� ����, ���� � ����� ������
	 * @param BG ���� ������� ���� ������
	 * @param FG ���� ������
	 * @return ������ �� ������� ������ Menu ��� ������� �������
	 */
	Menu& setColorText(int BG, int FG);
	/**
	 * @brief ��������� ���� ����� ���� � ���������� �� ��� �������� ��� �������
	 * @param head ����� ��������� ����
	 * @return ������ �� ������� ������ Menu ��� ������� �������
	 */
	inline Menu& addItem(const std::string& head) { return addItem(head, nullptr); }
	/**
	 * @brief ��������� ����� ����� ���� � ���������� � ��������� ��� ������� Enter.
	 * @param head   - ��������� ������ ����
	 * @param fEnter - �������, ������� ����������� ��� ������ ����� ������
	 * @return ������ �� ������� ������ Menu ��� ������� �������
	 */
	Menu& addItem(const std::string& head, const std::function<void()>& fEnter);
	/**
	 * @brief ��������� ����� ����� ���� � ����������, ��������� ��� Enter � ��������� ��� �������� �������.
	 * @param head  - ��������� ������ ����
	 * @param fEnter - �������, ������� ����������� ��� ������� Enter
	 * @param fmove - �������, ������� ����������� ��� �������� � ������
	 * @return ������ �� ������� ������ Menu ��� ������� �������
	 */
	Menu& addItem(const std::string& head, const std::function<void()>& fEnter, const std::function<void()>& fmove);
	/**
	 * @brief ����� ���������� ������������� ������� (�����), � ������� ����� ������������ ����.
	 * @param x   - ���������� X ������ �������� ����
	 * @param y   - ���������� Y ������ �������� ����
	 * @param x2  - ���������� X ������� ������� ����
	 * @param y2  - ���������� Y ������� ������� ����
	 * @return ������ �� ������� ������ Menu ��� ������� �������
	 */
	Menu& setBox(int x, int y, int x2, int y2);
	/**
	 * @brief ������������� ���� �����
	 * @param c1 ���� 1
	 * @param c2 ���� 2
	 * @return ������ �� ������� ������ Menu ��� ������� �������
	 */
	Menu& setColorBox(int c1, int c2);
	/**
	 * @brief ������������� ���� �����
	 * @param c1 ���� 1
	 * @return ������ �� ������� ������ Menu ��� ������� �������
	 */
	Menu& setColorBox(int c1);
	/**
	 * @brief ����� ������� ��������� ���� ����� ��� �������: ��������� � ��������.
	 * @param s - ��������� ������� (����� ������� ����)
	 * @param e - �������� ������� (������ ������ ����)
	 * @return ������ �� ������� ������ Menu ��� ������� �������
	 */
	Menu& setBox(Position& s, Position& e);
	/**
	 * @brief ������� �������� ����� � ������� ������� ���� (������ �����).
	 * @param text - ����� ��� ������
	 * @return ������ �� ������� ������ Menu ��� ������� �������
	 */
	Menu& printBox(const std::string& text);
	/**
	 * @brief ������� ������� ��������������� ���������� �����
	 */
	Menu& clsBox();
	/**
	 * @brief ������������� ����� ����
	 * @param h - ����� ��� ��������� �����
	 * @return ������ �� ������� ������ Menu ��� ������� �������
	 */
	Menu& setHead(std::string h);
	/**
	 * @brief ��������� ����
	 * @param r - ����������� �� ���� ����� �����
	 * @return ���������� ��������� ������� ����
	 */
	int run(bool r = false);
	/**
	 * @brief ��������� �������� ������ ���� ����
	 * @return ���������� ������ ����
	*/
	inline int getWidth() { return width + 3; }
	/**
	 * @brief �������� �������
	 * @return ���������� ������� ������ Box
	 */
	inline Box& getBox() { return xBox; }
	
};
