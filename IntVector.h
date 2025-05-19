#pragma once
#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include "MyError.h"
class IntVector
{
private:
    std::vector<int> numbers;

public:
    IntVector() {};
    IntVector(int n) { addNumber(n); };

    // ���������� ����� � ���
    IntVector& addNumber(int num);
    // ���� ����� � ����
    int findNumber(int num);
    // ������� ��� ����� ����
    std::string toStrig();
};

