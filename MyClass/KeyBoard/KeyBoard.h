#pragma once
#include <iostream>
#include <conio.h>      
#include <windows.h>    
enum class KEY {
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ENTER,
    ESCAPE,
    ANY,
    CHARACTER
};

class KeyBoard
{
public:
    // �������� ������� �� ������������
    static KEY getKey();
    // ���������, ������ �� �����-�� �������
    static inline bool isKeyPressed() { return _kbhit() != 0;   }
    // ���������� ��� ��������� ������� ������� (���� �����)
    static inline int getLastChar() { return static_cast<int>(_getch());  }
};

