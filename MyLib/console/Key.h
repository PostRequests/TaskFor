#pragma once
#include <iostream>
//#include <Windows.h>
#include <conio.h>

/// <summary>Конвертирует нажатые клавиши на русском и английском вединый вид </summary>
/// <param name="key">Символ который в итоге конвертируется</param>
/// <returns>Обработанный символ например ц==Ц==W==(w) возвращает w</returns>
char convertKey(char key);
/// <returns>Возвращает нажатый символ</returns>
char catchKey();

