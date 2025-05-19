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
    // ѕолучить клавишу от пользовател€
    static KEY getKey();
    // ѕровер€ет, нажата ли кака€-то клавиша
    static inline bool isKeyPressed() { return _kbhit() != 0;   }
    // ¬озвращает код последней нажатой клавиши (если нужно)
    static inline int getLastChar() { return static_cast<int>(_getch());  }
};

