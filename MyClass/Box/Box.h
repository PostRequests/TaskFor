#pragma once
#include "../Position/Position.h"
#include "../Color/Color.h"
#include <vector>
#include <string>

/// Набор символов для рисования таблиц
//LT1: "┌" H1 : "─" RT1 : "┐" V1 : "│" LD1 : "└" RD1 : "┘" LV1 : "├" RV1 : "┤" DH1 : "┴" UH1 : "┬"C1 : "┼" 
#define Board_LT2 (char)201 //╔ левый верхний двойной
#define Board_H2 (char)205 //═ горизонтальный двойной
#define Board_RT2 (char)187 //╗ правый верхний двойной
#define Board_V2 (char)186 //║ вертикальный двойной
#define Board_LD2 (char)200 //╚ левый нижний двойной
#define Board_RD2 (char)188 //╝ правый нижний двойной
#define Board_LV2 (char)204 //╠ левый вертикальный двойной
#define Board_RV2 (char)185 //╣ правый вертикальный двойной
#define Board_DH2 (char)202 //╩ нижний горизонтальный двойной
#define Board_UH2 (char)203 //╦ верхний горизонтальный двойной
#define Board_C2 (char)206 //╬ центральный двойной

class Box
{
private:
	
	Position start;//Крайняя левая верхняя точка
	Position end;//Крайняя нижняя правая точка
	Position cur;//Текущее положение текста
	Color colBor; //Цвет окантовки
	Color colT;// Цвет текста и фона

	std::vector<std::string> splitWord(const std::string& s);
public:
	Box() : start(1, 1), cur(2, 2) { end.setConsoleSize(); }
	Box(int x, int y, int x2, int y2) : start(x, y), end(x2, y2), cur(x + 1, y + 1) {}
	Box(Position s, Position e) :start(s), end(e), cur(s.getX() + 1, s.getY() + 1) {}
	Box(Position s, int x, int y) :start(s), end(x,y), cur(s.getX() + 1, s.getY() + 1) {}
	Box(int x, int y, Position e) :start(x,y), end(e), cur(x + 1, y + 1) {}
	~Box() { clear(); }
	//Возвращает строку длинною s и заполненную символами r
	inline static std::string getCharRow(int s, char r) { return std::string(s, r);}
	//Возвращает строку длинною s первый символ l, середина с и в конце r
	inline static std::string getCharRow(int s, char l, char c, char r) {
		return l + std::string(s, c) + r;	}
	//Установить координаты начала и конца
	Box& setCoordinate(int x, int y, int x2, int y2);
	//Установить цвет бордюра
	Box& setColorBoard(int c);
	//Установить цвет бордюра
	Box& setColorBoard(const Color& c);
	//Установить цвет бордюра
	Box& setColorBoard(int BG, int FG);
	//Установить цвет текста
	Box& setColorText(int c);
	//Установить цвет текста
	Box& setColorText(int BG, int FG);
	//Установить цвет текста
	Box& setColorText(const Color& c);
	//Заполняет квадрат пробелами
	static void drawFillBox(int xs, int ys, int xe, int ye);
	//Заполняет квадрат пробелами
	inline static void drawFillBox(Position& s, Position& e) { drawFillBox(s.getX(), s.getY(), e.getX(), e.getY()); }
	//Рисует окантовку по заданным позициям
	Box& drawBox();
	//Рисует квадрат с координатами начала и конца
	static void drawBox(int xs, int ys, int xe, int ye);
	//Рисует квадрат с координатами начала и конца
	inline static void drawBox(Position& s, Position& e) { drawBox(s.getX(), s.getY(), e.getX(), e.getY()); };
	//Выводит текст на экран в определенных рамках
	Box& print(const std::string& s);
	//Очищает текст внутри экрана
	Box& cls();
	//Очищает все содержимое вместе с рамкой
	Box& clear();
};

