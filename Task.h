#pragma once
#include "MyClass/Menu/Menu.h"
class Task
{
private:
public:
	void run(); 

	//��������������� ������

	/// <summary>
	/// ��������� ������ � ������ 
	/// </summary>
	/// <param name="v">���������� ������</param>
	 template <typename T>
	 static std::string toStr(std::vector<T>& v);
};

