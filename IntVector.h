#pragma once
#include <vector>
#include <string>
class IntVector
{
private:
	std::vector<int> num;
public:
	IntVector() {}
	IntVector(int n)  {}
	//Добавляем число в конец вектора
	IntVector& push_back(int n);
	//Находим среднее арифметическое
	int middle();
	//Переводим значения вектора в стрроку
	std::string toStr();
};

