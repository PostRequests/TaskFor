#pragma once
#include <vector>
class MinElement
{
public:
	int operator()(std::vector<int>& vec) {
		if (vec.empty())
			throw std::exception("Векстор пустой!");
		int min = vec[0];
		for (int i = 1; i < vec.size(); i++)
			if (min > vec[i])
				min = vec[i];
		return min;
	}
};

