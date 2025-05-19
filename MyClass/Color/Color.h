#pragma once
#include <iostream>
#define BlackBG  40   // Фоновый черный
#define BlackFG  30   // Текстовый черный
#define RedBG  41     // Фоновый красный
#define RedFG  31     // Текстовый красный
#define GreenBG  42   // Фоновый зеленый
#define GreenFG  32   // Текстовый зеленый
#define YellowBG  43  // Фоновый желтый
#define YellowFG  33  // Текстовый желтый
#define BlueBG  44    // Фоновый синий
#define BlueFG  34    // Текстовый синий
#define MagentaBG  45 // Фоновый пурпурный
#define MagentaFG  35 // Текстовый пурпурный
#define CyanBG  46    // Фоновый циановый
#define CyanFG  36    // Текстовый циановый
#define WhiteBG  47   // Фоновый белый
#define WhiteFG  37   // Текстовый белый

class Color
{
private:
	int BG; //цвет фона
	int FG; //цвет текста
public:
	Color(): BG(BlackBG), FG(WhiteFG){}
	~Color() { reset(); }
	//Устанавливаем цвет текста
	Color& setFG(int FG);
	//Устанавливаем цвет фона
	Color& setBG(int BG);
	//Устанавливаем цветовую палитру, первый элемент цвет фона, второй цвет текста
	Color& setColor(int BG, int FG);
	//Устанавливаем цвет
	inline Color& setColor(int c) { return setColor(c, c); }
	//Устанавливаем и присваеваем цвет другого элемента
	Color& setColor(const Color& c);
	//Геттер фонового цвета
	inline int getBG() { return BG; }
	//Геттер текстового цвета
	inline int getFG() { return FG; }
	//Оператор присвоения цвета
	inline void operator= (Color c) { setColor(c); }
	//Раскрашиваем установленные цвета
	Color& colorize();
	//Устанавливаем заданный цвет текста и фона
	inline static void colorize(int c, int c1) { std::cout << "\x1b[" << c << ';' << c1 << 'm'; }
	//Устанавливаем заданный цвет текста или фона
	inline static void colorize(int c) { std::cout << "\x1b[" << c << 'm'; }
	//Устанавливаем заданный цвет текста в RGB формате
	inline static void colorizeRGB_FG(int r, int g, int b) { std::cout << "\x1b[38;2;" << r << ";" << g << ";" << b << "m"; }
	//Устанавливаем заданный цвет фона в RGB формате
	inline static void colorizeRGB_BG(int r, int g, int b) { std::cout << "\x1b[48;2;" << r << ";" << g << ";" << b << "m"; }
	//Сбрасывает цвет на 0, при этом не меняя данные о цвете
	Color& reset();
};

