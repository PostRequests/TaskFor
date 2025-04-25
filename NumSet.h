#pragma once
#include <iostream>
#include "MyLib/str/str.h"
class NumSet
{
private:
	int* numSet;
	int size;
public:
	NumSet() : numSet(nullptr), size(0) {}
	NumSet(int n) : numSet(), size(1) { copy(n); }
	//NumSet(int* n, int s) : numSet(), size(s){}
	NumSet(const NumSet& o) { add(o); }

	~NumSet() { clear(); }

	bool operator==(const NumSet& o) { return include(o); }
	NumSet& operator=(const NumSet& o) { return copy(o); }
	NumSet& operator+=(const NumSet& o) { return add(o); }
	NumSet operator+(const NumSet& o);
	operator str const() {
		str r{ ((numSet) ? "[" : "[ ]") };
		for (int i = 0; i < size; i++)
			r + numSet[i] + ((i < size - 1) ? ", " : "]");
		return r;
	}


	NumSet& copy(const NumSet& o);
	NumSet& copy(int n);
	bool include(const NumSet& o);
	bool include(int n);
	NumSet& add(int n);
	NumSet& add(const NumSet& o);
	NumSet& clear();
	NumSet& show();
};

