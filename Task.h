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
	//��������������� ������

	/// <summary>
	/// ��������� ������ � ������ 
	/// </summary>
	/// <param name="v">���������� ������</param>
	 template <typename T>
	 static std::string toStr(const std::vector<T>& v);
	 /// <summary>
	/// ��������� set � ������ 
	/// </summary>
	/// <param name="v">���������� ������</param>
	template <typename T>
	 static std::string toStr(const std::set<T>& v);
	 /**
	 * @brief ��������� ������ ���������� ������� �� min �� max �������� size
	 */
	 static std::vector<int> randVec( int min, int max, int size);
};

