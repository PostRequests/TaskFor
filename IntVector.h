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
	//��������� ����� � ����� �������
	IntVector& push_back(int n);
	//������� ������� ��������������
	int middle();
	//��������� �������� ������� � �������
	std::string toStr();
};

