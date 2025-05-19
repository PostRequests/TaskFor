#pragma once
#include <string>
#include <iostream>
class To866
{
public:
	std::string operator()(const std::string & s) {
		std::string r;
		for (char ch : s) {
			int nch = static_cast<unsigned char>(ch);
			if (nch >= 240 && nch <= 255)
				r += nch - 16;
			else if (nch >= 192 && nch <= 239)
				r += nch - 64;
			else
				r += nch;
		}
		return r;
	}
	
};

