#pragma once
#include <iostream>
#define BlackBG  40   // ������� ������
#define BlackFG  30   // ��������� ������
#define RedBG  41     // ������� �������
#define RedFG  31     // ��������� �������
#define GreenBG  42   // ������� �������
#define GreenFG  32   // ��������� �������
#define YellowBG  43  // ������� ������
#define YellowFG  33  // ��������� ������
#define BlueBG  44    // ������� �����
#define BlueFG  34    // ��������� �����
#define MagentaBG  45 // ������� ���������
#define MagentaFG  35 // ��������� ���������
#define CyanBG  46    // ������� ��������
#define CyanFG  36    // ��������� ��������
#define WhiteBG  47   // ������� �����
#define WhiteFG  37   // ��������� �����

class Color
{
private:
	int BG; //���� ����
	int FG; //���� ������
public:
	Color(): BG(BlackBG), FG(WhiteFG){}
	~Color() { reset(); }
	//������������� ���� ������
	Color& setFG(int FG);
	//������������� ���� ����
	Color& setBG(int BG);
	//������������� �������� �������, ������ ������� ���� ����, ������ ���� ������
	Color& setColor(int BG, int FG);
	//������������� ����
	inline Color& setColor(int c) { return setColor(c, c); }
	//������������� � ����������� ���� ������� ��������
	Color& setColor(const Color& c);
	//������ �������� �����
	inline int getBG() { return BG; }
	//������ ���������� �����
	inline int getFG() { return FG; }
	//�������� ���������� �����
	inline void operator= (Color c) { setColor(c); }
	//������������ ������������� �����
	Color& colorize();
	//������������� �������� ���� ������ � ����
	inline static void colorize(int c, int c1) { std::cout << "\x1b[" << c << ';' << c1 << 'm'; }
	//������������� �������� ���� ������ ��� ����
	inline static void colorize(int c) { std::cout << "\x1b[" << c << 'm'; }
	//������������� �������� ���� ������ � RGB �������
	inline static void colorizeRGB_FG(int r, int g, int b) { std::cout << "\x1b[38;2;" << r << ";" << g << ";" << b << "m"; }
	//������������� �������� ���� ���� � RGB �������
	inline static void colorizeRGB_BG(int r, int g, int b) { std::cout << "\x1b[48;2;" << r << ";" << g << ";" << b << "m"; }
	//���������� ���� �� 0, ��� ���� �� ����� ������ � �����
	Color& reset();
};

