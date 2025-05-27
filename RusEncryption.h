#pragma once
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
class RusEncryption
{
private:
	std::map<char, char> ch;
public:
	RusEncryption(){ setMap(3); }
	RusEncryption(int shift) { setMap(shift); }
	/*
	 * @brief Генерирует шифр
	 * @param shift Сдвиг
	 */
	RusEncryption& setMap(int shift);
	/**
	 * @brief Шифрует строку
	 * @param s строка
	 * @return Возвращает зашифрованную строку
	 */
	std::string encryption(const std::string& s);
	/**
	 * @brief Расшифровывает  строку
	 * @param s строка
	 * @return Возвращает расшифрованную строку строку
	 */
	std::string decryption(const std::string& s);
};

