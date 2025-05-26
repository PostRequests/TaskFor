#pragma once
#include "MyClass/Menu/Menu.h"
#include <algorithm>
#include <set>
class Task
{
private:
	
public:
	void run(); 
	Task() {}
	//вспомогательные методы

	/// <summary>
	/// Переводит вектор в строку 
	/// </summary>
	/// <param name="v">Одномерный вектор</param>
	 template <typename T>
	 static std::string toStr(const std::vector<T>& v);
	 /// <summary>
	/// Переводит set в строку 
	/// </summary>
	/// <param name="v">Одномерный вектор</param>
	template <typename T>
	 static std::string toStr(const std::set<T>& v);
	 /**
	 * @brief Заполняет вектор случайными числами от min до max размером size
	 */
	 static std::vector<int> randVec( int min, int max, int size);
};

