#pragma once
#include "ANSI.h"
#include <iostream>
/// <summary>
/// Печатает линию
/// </summary>
/// <param name="s">Длинна линии</param>
/// <param name="symbol">Элемент заполнения</param>
/// <param name="color1">Цвет консоли ANSI</param>
/// <param name="color2">Цвет консоли ANSI</param>
void printRowChars(int s, char symbol, int color1 = 0, int color2 = 0);
/// <summary>
/// Печатает линию
/// </summary>
/// <param name="s">Длинна линии</param>
/// <param name="l">Первый символ в линии</param>
/// <param name="c">Символ который будет заполнять центр линии</param>
/// <param name="r">Последний символ линии</param>
/// <param name="color1">Цвет консоли ANSI (не обязательный параметр)</param>
/// <param name="color2">Цвет консоли ANSI (не обязательный параметр)</param>
void printRowChars(int s, char l, char c, char r, int color1 = 0, int color2 = 0);
/// <summary>
/// Закрашивает/Удаляет область прямоугольную 
/// </summary>
/// <param name="posX">Позиция строки</param>
/// <param name="posY">Позиция колонки</param>
/// <param name="rows">Количество закрашиваемых строк</param>
/// <param name="cols">Количество закрашиваемых колонок</param>
/// <param name="color">Параметр цвета (указываем только задний фон)</param>
void drawFillRectangle(int posX, int posY, int rows, int cols, int color = 0);
/// <summary>
/// Рисует квадрат с двойными рамками
/// </summary>
/// <param name="sX">Х - левая верхняя координата</param>
/// <param name="sY">У - левая верхняя координата</param>
/// <param name="eX">Х - правая нижняя координата</param>
/// <param name="eY">У - правая нижняя координата</param>
/// <param name="color">Цвет рамки</param>
void drawEmptyRectangle2(int sX, int sY, int eX, int eY, int color = 0);
/// <summary>
/// Печатает текст по середине
/// </summary>
/// <param name="text">Текст</param>
/// <param name="totalLen">Длинна строки</param>
void centerWord(const char* text, int totalLen);
