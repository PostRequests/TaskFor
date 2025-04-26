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
NumSet& NumSet::add(const NumSet& o) {
	for (int i = 0; i < o.size; i++)
		if (!include(o.numSet[i])) {
			int* t = new int[size + 1];
			for (int i = 0; i < size; i++)
				t[i] = numSet[i];
			t[size] = o.numSet[i];
			int s = size + 1;
			clear();
			size = s;
			numSet = t;
		}
	return *this;
}
NumSet& NumSet::show() {
	std::cout << (str)*this << std::endl;
	return * this;
}
NumSet NumSet::operator+(const NumSet& o) {
	NumSet result{ *this };
	result.add(o);
	return result;
}
NumSet& NumSet::operator-=(const NumSet& o) {
	//Ћишн€€ пам€ть остаетс€ в конце 
	if (!numSet || !o.numSet) return *this;
	int newSize = 0;
	int* temp = new int[size];
	for (int i = 0; i < size; i++) {
		bool found = false;
		for (int j = 0; j < o.size; j++) 
			if (numSet[i] == o.numSet[j]) {
				found = true;
				break;
			}
		if (!found) 
			temp[newSize++] = numSet[i];
	}
	delete[] numSet;
	numSet = temp;
	size = newSize;
	return *this;
}

NumSet NumSet::operator-(const NumSet& o) {
	NumSet r{ *this };
	r -= o;
	return r;
}

NumSet NumSet::operator*(const NumSet& o) {
	NumSet r;
	for (int i = 0; i < o.size; i++)
		if (include(o.numSet[i]))
			r.add(o.numSet[i]);
	return r;
}
NumSet& NumSet::operator*=(const NumSet& o) {
	NumSet r{*this};
	*this = r * o;
	return  *this;
}
NumSet NumSet::operator/(const NumSet& o) {
	NumSet r;
	for (int i = 0; i < o.size; i++)
		if (!include(o.numSet[i]))
			r.add(o.numSet[i]);
	return r;
}
NumSet& NumSet::operator/=(const NumSet& o) {
	NumSet r{ *this };
	*this = r * o;
	return  *this;
}
NumSet& NumSet::copy(const int* n, int s) {
	for (int i = 0; i < s; i++)
		add(n[i]);
	return *this;
}

 str const NumSet::conclusion() {
	str r{ ((numSet) ? "[" : "[ ]") };
	for (int i = 0; i < size; i++)
		r + numSet[i] + ((i < size - 1) ? ", " : "]");
	return r;
}

NumSet& NumSet::copy(const char* s) {
	clear();
	for (int i = 0; s[i] != '\0'; i++) 
		if (strchr("-1234567890", s[i])) {
			str num{s[i]};
			while (s[i++] && strchr("1234567890", s[i]))
				num.cat(s[i]) ;
			add(strToInt(num));
		}
	return *this;
}

std::ostream& operator << (std::ostream& o, NumSet& s) {
	o << (str)s;
	return o;
}

std::istream& operator >> (std::istream& o, NumSet& s) {
	o.clear();
	const int limitSymbol = 1024;
	char* r = new char[limitSymbol];
	o.getline(r, limitSymbol);
	s.copy(r);
	return o;
}