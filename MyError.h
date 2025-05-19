#pragma once
#include <string>
#include <vector>
#include <iostream>
class MyError : public std::exception
{
private:
	std::string er;//Сообщение с ошибкой
public:
	MyError(const std::string& er) : er(er) {}
	std::string what() {
		return er;
	}
};

