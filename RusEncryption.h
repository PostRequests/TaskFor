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
	 * @brief ���������� ����
	 * @param shift �����
	 */
	RusEncryption& setMap(int shift);
	/**
	 * @brief ������� ������
	 * @param s ������
	 * @return ���������� ������������� ������
	 */
	std::string encryption(const std::string& s);
	/**
	 * @brief ��������������  ������
	 * @param s ������
	 * @return ���������� �������������� ������ ������
	 */
	std::string decryption(const std::string& s);
};

