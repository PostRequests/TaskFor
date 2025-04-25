#pragma once
#include "../console/Helper.h"
#include <iostream>
class str
{
private:
	char* s;
	size_t len;

public:
	//������������
	str() : s(nullptr), len(0) {};
	str(const char* s) : str() {copy(s);}
	//����������� �����������
	str(const str& o) :str() { copy(o);	}
	//�������� ����������
	str& operator=(const str& o) {return copy(o);}
	//����� �����������
	str& copy(const str& o) {	return *this;	}
	str& copy(const char* o);
	//����� �������� ���������� � ������
	str& clear();
	//����� ���������� ��������� �� �����
	char * get_s() {return s;}
	//����� ���������� ������ ������
	size_t length() {return len;}
	//������ ��������������� ������
	str& set_s(const char* s) {	copy(s);}
	//���������� int ���� ����� ������������� ����� � ����� ��� 0
	int toInt() {return strToInt(s);}
	//����� ����������� � ����� ������ �����
	str& cat(const char* s);	
	str& cat(const str o) {	return cat(o.s);}
	//�������� ����������� �����
	str& operator+(const char* s) {	return cat(s);}
	//�������� ����������� ������ � �������������� �����
	str& operator+(int p);
	str& input();
	//�������� ��������� ������
	operator char*() const {return s;}
	//����� ���������� ��������� 2� �������
	int cmp(const char* s) {return strcmp(this->s, s);}
	bool operator==(const char* s) {return (cmp(s) == 0);}
	bool operator<(const str& s) {	return (cmp(s) == -1);	}
	bool operator>(const str& s) {	return (cmp(s) == 1);}
	//����������
	~str() {clear();}
};

