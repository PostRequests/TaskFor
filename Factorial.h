#pragma once
#include <iostream>
class Factorial
{
public:
	long long operator()(int n) {
		if (n < 0)
			throw std::exception("Не возможно определить факториал отрицательного числа");
		long long r = 1;
		for (int i = 2; i <= n; ++i) 
			r *= i;
		return r;
	}
};

