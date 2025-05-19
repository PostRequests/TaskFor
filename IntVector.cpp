#include "IntVector.h"
int IntVector::findNumber(int num) {
    for (int i = 0; i < numbers.size(); ++i) 
        if (numbers[i] == num)
            return i;
    // генерируем исключение
    throw MyError("Число " + std::to_string(num) + " не найдено в ряду!");
}
std::string IntVector::toStrig()  {
    std::string r;
    r += "[";
    for (int i = 0; i < numbers.size(); i++)
        r += std::to_string(numbers[i]) + ((i < numbers.size() - 1) ? ", " : "");
    r += "]";
    return r;
}
IntVector& IntVector::addNumber(int num) { 
    numbers.push_back(num); 
    return *this;
}