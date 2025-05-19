#pragma once
#include <iostream>
class Factorial
{
public:
	long long operator()(int n) {
		if (n < 0)
			throw std::exception("�� �������� ���������� ��������� �������������� �����");
		long long r = 1;
		for (int i = 2; i <= n; ++i) 
			r *= i;
		return r;
	}
};

