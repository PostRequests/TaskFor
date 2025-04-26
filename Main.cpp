
#include <iostream>
#include "MyLib/str/str.h"
#include "NumSet.h"
#include <string>


int main()
{
    system("chcp 1251>nul");
    NumSet m1{ "3, 8, 46, 5, 11" };
    NumSet m2;
    std::cout << "Сложение/добавление элементов \n";
    std::cout << m1 << " + 4 = " << (m1 + 4) << '\n';
    std::cout << m1 << " + 3 = " << (m1 + 3) << '\n';
    std::cout << "Введите множество для сложения, например: 2 3 41 23\n : ";
    std::cin >> m2;
    std::cout << m1 << " + " << m2 << " = " << (m1 + m2) << '\n';
    std::cout << "Удаление элементов множеств\n";
    NumSet m3{ "3 4 5" };
    std::cout << m1 << " - 3 = " << (m1 - 3) << '\n';
    std::cout << m1 << " - " << m3 << " = " << (m1 - m3) << '\n';
    std::cout << "Пересечение множеств\n";
    std::cout << m1 << " * " << m3 << " = " << (m1 * m3) << '\n';
    std::cout << "Разность множеств\n";
    std::cout << m1 << " / " << m3 << " = " << (m1 / m3) << '\n';
    std::cout << m3 << " / " << m1 << " = " << (m3 / m1) << '\n';
    std::cout << "Сравнение множеств\n";
    NumSet m4{ m1 };
    std::cout << m1 << " == " << m3 << ((m1 == m3) ? " одинаковые" : " разные") << '\n';
    std::cout << m1 << " == " << m4 << ((m1 == m4) ? " одинаковые" : " разные") << '\n';
    std::cout << m3 << " == " << m3 << ((m3 == m3) ? " одинаковые" : " разные") << '\n';
}


