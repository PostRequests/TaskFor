#include "NumSet.h"
NumSet& NumSet::clear() {
	if (numSet) {
		delete[] numSet;
		numSet = nullptr;
		size = 0;
	}
	return *this;
}
NumSet& NumSet::copy(int n) {
	clear();
	numSet = new int[1] {n};
	size = 1;
	return *this;
}
bool NumSet::include(int n) {
	for (int i = 0; i < size; i++)
		if (numSet[i] == n) return true;
	return false;
}

bool NumSet::include(const NumSet& o) {
	if (o.size != size) return false;
	if (!o.numSet || !numSet) return o.numSet == numSet;
	for (int i = 0; i < size; i++)
		if (!include(o.numSet[i]))
			return false;
	return true;
}
NumSet& NumSet::copy(const NumSet& o) {
	if (this == &o) return *this;
	clear();
	if (o.numSet) {
		numSet = new int[o.size];
		for (int i = 0; i < o.size; i++)
			numSet[i] = o.numSet[i];
		size = o.size;
	}
	return *this;
}
NumSet& NumSet::add(int n) {
	if (!include(n)) {
		int* t = new int[size + 1];
		for (int i = 0; i < size; i++)
			t[i] = numSet[i];
		t[size] = n;
		int s = size + 1;
		clear();
		size = s;
		numSet = t;
	}
	return *this;
}

NumSet& NumSet::add(const NumSet& o) {
	for (int i = 0; i < o.size; i++)
		add(o.numSet[i]);
	return *this;
}
NumSet& NumSet::show() {
	std::cout << (str)*this;
	return * this;
}
NumSet NumSet::operator+(const NumSet& o) {
	NumSet result{ *this };
	result.add(o);
	return result;
}
