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

    // добавление числа в ряд
    IntVector& addNumber(int num);
    // Ищет числа в ряду
    int findNumber(int num);
    // Выводит все чисел ряда
    std::string toStrig();
};

