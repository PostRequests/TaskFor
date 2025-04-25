#pragma once
#include <iostream>
#include "MyLib/str/str.h"

class NumSet
{
private:
	int* numSet;
	int size;
	str const output();
	
public:
	

	NumSet() : numSet(nullptr), size(0) {}
	NumSet(int n) : numSet(), size(1) { copy(n); }
	NumSet(const char* s) { strToNumSet(s); }
	NumSet(int* n, int s) { copy(n,s); }
	NumSet(const NumSet& o) { add(o); }

	~NumSet() { clear(); }

	bool operator==(const NumSet& o) { return include(o); }
	NumSet& operator=(const NumSet& o) { return copy(o); }
	NumSet& operator+=(const NumSet& o) { return add(o); }
	NumSet operator+(const NumSet& o);
	NumSet operator-(const NumSet& o);
	NumSet& operator-=(const NumSet& o);
	NumSet operator*(const NumSet& o);
	NumSet& operator*=(const NumSet& o);
	NumSet operator/(const NumSet& o);
	NumSet& operator/=(const NumSet& o);
	operator str const() {return output();}
	

	NumSet& copy(const NumSet& o);
	NumSet& copy(int n);
	NumSet& copy(const int* n, int s);
	bool include(const NumSet& o);
	bool include(int n);
	NumSet& add(int n);
	NumSet& add(const NumSet& o);
	void strToNumSet(const char* s);

	NumSet& clear();
	NumSet& show();
};

std::ostream& operator << (std::ostream& o, NumSet& s);
std::istream& operator >> (std::istream& o, NumSet& s);
//std::ostream& operator << (std::ostream& o, const NumSet& s);