#include "IntVector.h"
IntVector& IntVector::push_back(int n) {
	num.push_back(n);
	return *this;
}
int IntVector::middle() {
	int r = 0;
	[*this, &r]() {
		int summ = 0;
		for (int n : num) 
			summ += n;
		r = summ / num.size();
		}();
	return r;
}
std::string IntVector::toStr() {
	std::string r;
	r += "[";
	for (int i = 0; i < num.size(); i++)
		r += std::to_string(num[i]) + ((i < num.size() - 1) ? ", " : "");
	r += "]";
	return r;
}