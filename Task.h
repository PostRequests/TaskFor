#pragma once
#include "MyClass/Menu/Menu.h"
class Task
{
private:
public:
	void run(); 

	//вспомогательные методы

	/// <summary>
	/// Переводит вектор в строку 
	/// </summary>
	/// <param name="v">Одномерный вектор</param>
	 template <typename T>
	 static std::string toStr(std::vector<T>& v);
};

