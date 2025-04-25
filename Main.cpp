
#include <iostream>
#include "NumSet.h"

int main()
{
    NumSet m{25};
    NumSet m2{112};
    std::cout << (str)m;
    (m2 += m).add(2);
    m.add(6).add(8);
    
    NumSet m3;
    m3 += m2;
    m3 += m;
    m3 += (NumSet)12;
    m3 += (int)32;
    m3 += 23;

    m3.show();
    m2.show();
    //std::cout << (m == m2);
    //std::cout << m.include(6);
}

