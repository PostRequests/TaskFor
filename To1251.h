#pragma once
#include <string>
class To1251
{
public:
	std::string operator()(const std::string& s) {
		std::string r;
		for (char ch : s) {
			int nch = static_cast<unsigned char>(ch);
			if (nch >= 128 && nch <= 175)
				r += nch + 64;
			else if (nch >= 224 && nch <= 239)
				r += nch + 16;
			else
				r += nch;
		}
		return r;
	}
};

