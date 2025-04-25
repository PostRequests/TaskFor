#pragma once
#include <iostream>

/// <summary>
/// Проверяет, содержит ли text только элементы из content
/// </summary>
/// <param name="text">Проверяемый текст</param>
/// <param name="content">Разрешённые символы</param>
/// <returns>True, если все символы из text присутствуют в content, иначе false</returns>
bool includeContainsOnly(char* text, const char* content);
/// <summary>
/// Преобразует текст в число (нужна предварительная проверка bool isNumber(char* text))
/// </summary>
/// <param name="num">Текст</param>
/// <returns>Возвращает преобразованное число из текста</returns>
int strToInt(char* num);
/// <summary>
///  Проверяет, может ли текст превратиться в целочисленное число
/// </summary>
/// <param name="text">Проверяемый текст</param>
/// <returns>Возвращает true если text содержит символы "1234567890-"</returns>
bool isNumber(char* text);