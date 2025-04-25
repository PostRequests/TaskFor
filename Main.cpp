
#include <iostream>
#include "MyLib/str/str.h"
#include "NumSet.h"


int main()
{
    system("chcp 1251>nul");
    NumSet m1{"3, 8, 46, 5, 11"};
    NumSet m2;
    std::cout << "Сложение/добавление элементов \n";
    std::cout << m1 << " + 4 = " << m1.add(3) << '\n';
    std::cout << m1 << " + 3 = " << m1.add(3) << '\n';
    std::cout << "Введите множество для сложения пример: 2 3 41 23\n";
    std::cin >> m2;
    std::cout << &m1 << " + " << &m2 << " = " << (m1 + m2) << '\n';

    //NumSet any2;
    //std::cin >> any2;
    //any2.show();
    //std::cin >> any2;
    //any2.show();
    //NumSet any{ "-1234 -123-4.12" };
    //std::cout << any;
    //NumSet m{125 };
    //NumSet m2{112};
    ////std::cin >> (str)m;
    //std::cout << m << "sfdes";
    /*m.add(6).add(8);
    m2.add(6).add(8).show();
    m.show();
    (m / m2).show();*/
    //m.show();

    //std::cout << (m == m2);
    //std::cout << m.include(6);
}


