#pragma once
#include <string>
class Equal
{
public:
	template <typename T>
	bool operator ()(const T& t1, const T& t2) {
		return t1 == t2;
	}
};

