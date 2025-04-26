#pragma once
#include <iostream>
#include "MyLib/str/str.h"

class NumSet
{
private:
	int* numSet;
	int size;
		
public:
	
	//������������
	NumSet() : numSet(nullptr), size(0) {}
	NumSet(const NumSet& o) : NumSet() { add(o); }
	NumSet(int* n, int s) : NumSet() { copy(n, s); }
	NumSet(const char* s) : NumSet() { copy(s); }
	NumSet(int n) : NumSet() { copy(n); }
	//����������
	~NumSet() { clear(); }
	//���������
	inline bool operator==(const NumSet& o) { return include(o); }
	inline NumSet& operator=(const NumSet& o) { return copy(o); }
	inline NumSet& operator+=(const NumSet& o) { return add(o); }
	inline operator str const() { return conclusion(); }
	NumSet& operator-=(const NumSet& o);
	NumSet& operator*=(const NumSet& o);
	NumSet& operator/=(const NumSet& o);
	NumSet operator+(const NumSet& o);
	NumSet operator-(const NumSet& o);
	NumSet operator*(const NumSet& o);
	NumSet operator/(const NumSet& o);
	//������
	//��������� ��������� ������� �� ������� �������
	NumSet& copy(const NumSet& o);
	//��������� �� ����� � ������
	NumSet& copy(int n);
	//��������� �� ������� � ������
	NumSet& copy(const int* n, int s);
	//��������� �� ������ � ������
	NumSet& copy(const char* s);
	//����������� ������ � ������
	str const conclusion();
	//��������� ������������ ��������
	bool include(const NumSet& o);
	//��������� ������� ����� � �������
	bool include(int n);
	//��������� ��������
	NumSet& add(const NumSet& o);
	//������� ��������� � �������
	NumSet& clear();
	//������� �� ����� ������ ���������
	NumSet& show();
};
//���������� ��������� std::cout <<
std::ostream& operator << (std::ostream& o, NumSet& s);
//���������� ��������� std::cin >>
std::istream& operator >> (std::istream& o, NumSet& s);