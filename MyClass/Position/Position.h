#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
class Position
{
private:
	int x;
	int y;
	int startX;
	int startY;
public:
	Position() : x(1), y(1), startX(1), startY(1) {}
	Position(const Position& o) : Position(o.x, o.y) {}
	Position(int x, int y) : x(x), y(y), startX(x), startY(y) {}
	
	/// ��������� ����� � ��� ��������
	Position& setX(int x);
	/// ��������� ����� � ��� ��������
	Position& setY(int y);
	/// ��������� ����� ��� ��������
	Position& setPos(const Position& o);
	/// ��������� ����� ��� ��������
	inline Position& setPos(int x, int y) { return setPos(Position(x, y)); }
	/// ������� �� ����������� �����������
	Position& go();
	/// ������� � ���������� ����� ���������
	Position& goTo(const Position& o);
	/// ������� � ���������� ����� ���������
	Position& goTo(int x, int y);
	/// ������� � ���������� ����� ���������
	inline Position& goTo() { return goTo(*this); }
	/// �������� �� ������ ������� ����������
	inline void show() { std::cout << "[x:" << x << ",y:" << y << "]\n"; }
	/// �������� �� ������ ������� ���������� � ��������� �����
	Position& show(int x, int y);
	/// ��������� � + 1, ��� ��������
	Position& nextLine(int line = 1);
	/// ��������� � + 1, ��� ��������
	inline void operator++() { nextLine(); }
	inline bool operator==(Position a) { return ((a.x == x && a.y == y) ? true : false); }
	/// ��������� �� ����������� ����������� � �������� �����
	Position& print(const std::string& s);
	/// ��������� �� ����������� ����������� � �������� �����, � ����� ������� �� ��������� �������
	Position& printLn(const std::string& s);
	/// ��������� �� ����������� ����������� � �������� �����, � ����� ������� �� ��������� �������
	Position& printLn(const char s);
	///  ������������� ���������� � ����� ������� �������
	Position& setConsoleSize();
	/// ���������� ���������� �� �
	inline int getX() { return x; }
	/// ���������� ���������� �� �
	inline int getY() { return y; }
	// ���������� ���������� ������������� ���������� �
	inline int getMinX() { return startX; }
	// ���������� ���������� ������������� ���������� �
	inline int getMinY() { return startY; }
	Position& setStartX(int x);
	Position& setStartY(int y);
	/// ����������� � �������������� �����������
	Position& restart();
	//���������� ������ � ��������� �������
	inline static void moveTo(int x, int y) { std::cout << "\033[" << y << ";" << x << "H"; }
	//��������� � � ������������ ���������� �����
	Position& plusX(int x);
	//��������� � � ������������ ���������� �����
	Position& plusY(int y);
};

