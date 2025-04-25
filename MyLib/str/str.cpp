#include "str.h"
str& str::copy(const char* o) {
	if (o != this->s) {
		clear();
		len = strlen(o);
		s = new char[len + 1];
		strcpy_s(s, len + 1, o);
		return *this;
	}

}
str& str::clear() {
	if (s) {
		delete[] s;
		s = nullptr;
		len = 0;
	}
	return *this;
}
str& str::cat(const char* s) {
	if (!this->s) {
		copy(s);
	}
	if (s) {
		size_t n_len = len + strlen(s);
		char* n = new char[n_len + 1];
		strcpy_s(n, n_len + 1, this->s);
		strcat_s(n, n_len + 1, s);
		clear();
		this->s = n;
		this->len = n_len;
	}
	return *this;
}
str& str::operator+(int p) {
	static char m[1024]{};
	sprintf_s(m, "%i", p);
	return cat(m);
}

str& str::input(){
	char m[1024]{};
	std::cin >> m;
	return copy(m);
}