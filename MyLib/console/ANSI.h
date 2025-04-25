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

#define Board_LT1 (char)218 // ┌ левый верхний одинарный
#define Board_H1 (char)196  // ─ горизонтальный одинарный
#define Board_RT1 (char)191 // ┐ правый верхний одинарный
#define Board_V1 (char)179  // │ вертикальный одинарный
#define Board_LD1 (char)192 // └ левый нижний одинарный
#define Board_RD1 (char)217 // ┘ правый нижний одинарный
#define Board_LV1 (char)195 // ├ левый вертикальный одинарный
#define Board_RV1 (char)180 // ┤ правый вертикальный одинарный
#define Board_DH1 (char)193 // ┴ нижний горизонтальный одинарный
#define Board_UH1 (char)194 // ┬ верхний горизонтальный одинарный
#define Board_C1 (char)197  // ┼ центральный одинарный

/// <summary>
/// Устанавливаем 1 цвет консоли
/// https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
/// </summary>
/// <param name="color">Цвет</param>
#define setColor(color) std::cout << "\x1b[" << color << 'm'
/// <summary>
/// Устанавливаем 2 цвета консоли, для фона и для символа
/// </summary>
/// <param name="color1">Цвет1</param>
/// <param name="color2">Цвет2</param>
#define setColor2(color1, color2) std::cout << "\x1b[" << color1 << ';' << color2 << 'm'
/// <summary>/// Сбрасываем все цвета консоли на стандартный/// </summary>
#define resetColor() setColor(0)
/// <summary>
/// Установка цвета текста в формате RGB
/// </summary>
/// <param name="r">Оттенок красного</param>
/// <param name="g">Оттенок зеленого</param>
/// <param name="b">Оттенок Синего</param>
#define set_RGB_FG(r, g, b) std::cout << "\x1b[38;2;" << r << ";" << g << ";" << b << "m"
/// <summary>
/// Устанавливает цвет фона в формате RGB
/// </summary>
/// <param name="r">Оттенок красного</param>
/// <param name="g">Оттенок зеленого</param>
/// <param name="b">Оттенок Синего</param>
#define set_RGB_BG(r, g, b) std::cout << "\x1b[48;2;" << r << ";" << g << ";" << b << "m"
/// <summary> Устанавливаем курсор в нужную позицию </summary>
/// <param name="x"></param>
/// <param name="y"></param>
#define setCursorPosition(x, y) std::cout << "\033[" << y << ";" << x << "H"
//Жирный текст
#define BOLD_TEXT "\x1b[1m"

