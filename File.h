#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <map>
class File
{
public:
	static std::string loadFile(const std::string& fn) {
		std::string lines;
		std::ifstream file(fn);
		if (!file.is_open()) 
			throw std::exception("Не удалось открыть файл: ");
		std::string line;
		while (std::getline(file, line))
			lines += line;
		return lines;
	}
	static void saveFile(const std::string& fn, const std::string& s) {
		std::ofstream file(fn); //открываем файл
		if (!file) //Если не можем открыть выдаем ошибку
			throw std::exception("Не удалось открыть файл для чтения");
		file << s;
		file.close();
	}

	static std::map<char, int> loadFileToMap(const std::string& fn) {
		std::map<char, int> r;
		std::ifstream file(fn);
		if (!file.is_open())
			throw std::exception("Не удалось открыть файл: ");
		char ch;
		while (file.get(ch)) {
			r[ch]++;
		}
		return r;
	}
};

