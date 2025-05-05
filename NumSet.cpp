#include "NumSet.h"

NumSet& NumSet::copy(int n) {
	numSet.clear();
	numSet.push_back(n);
	return *this;
}
NumSet& NumSet::copy(const NumSet& o) {
	if (this == &o) return *this;
	numSet = o.numSet;
	return *this;
}
NumSet& NumSet::copy(const int* n, int s) {
	for (int i = 0; i < s; i++)
		add(n[i]);
	return *this;
}
NumSet& NumSet::copy(const std::string& s) {
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '-' || isdigit(s[i])) {
			std::string num;
			if (s[i] == '-') {
				num += '-';
				i++;
			}
			while (i < s.size() && isdigit(s[i])) 
				num += s[i++];
			
			add(std::stoi(num));
		}
	return *this;
}
NumSet& NumSet::add(const NumSet& o) {
	for (int i = 0; i < o.numSet.size(); i++)
		if (!include(o.numSet[i])) 
			numSet.push_back(o.numSet[i]);
	return *this;
}
bool NumSet::include(int n) {
	for (int i = 0; i < numSet.size(); i++)
		if (numSet[i] == n) return true;
	return false;
}

bool NumSet::include(const NumSet& o) {
	if (o.numSet.size() != numSet.size()) return false;
	for (int i = 0; i < numSet.size(); i++)
		if (!include(o.numSet[i]))
			return false;
	return true;
}
NumSet& NumSet::show() {
	std::cout << *this << std::endl;
	return * this;
}
NumSet NumSet::operator+(const NumSet& o) {
	NumSet result{ *this };
	result.add(o);
	return result;
}
NumSet& NumSet::operator-=(const NumSet& o) {
	if (numSet.empty() || o.numSet.empty()) return *this;
	for (int i = 0; i < numSet.size(); i++) {
		for (int j = 0; j < o.numSet.size(); j++)
			if (numSet[i] == o.numSet[j]) {
				numSet.erase(numSet.begin() + i);
				break;
			}
	}
	return *this;
}
NumSet NumSet::operator-(const NumSet& o) {
	NumSet r{ *this };
	r -= o;
	return r;
}
NumSet NumSet::operator*(const NumSet& o) {
	NumSet r;
	for (int i = 0; i < o.numSet.size(); i++)
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
	for (int i = 0; i < o.numSet.size(); i++)
		if (!include(o.numSet[i]))
			r.add(o.numSet[i]);
	return r;
}
NumSet& NumSet::operator/=(const NumSet& o) {
	NumSet r{ *this };
	*this = r * o;
	return  *this;
}
 std::string NumSet::conclusion() {
	std::string r{ ((numSet.empty()) ? "[ ]" : "[") };
	for (int i = 0; i < numSet.size(); i++)
		r += std::to_string(numSet[i]) + ((i < numSet.size() - 1) ? ", " : "]");
	return r;
}
std::ostream& operator << (std::ostream& o, NumSet s) {
	o << std::string(s);
	return o;
}
std::istream& operator >> (std::istream& o, NumSet& s) {
	std::string n;
	std::getline(o, n);
	s.copy(n);
	return o;
}
