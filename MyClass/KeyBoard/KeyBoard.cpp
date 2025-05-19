#include "KeyBoard.h"

KEY KeyBoard::getKey() {
    int key = _getch(); 
    if (key == 0 || key == 0xE0) {
        key = _getch(); 
        switch (key) {
        case 72: return KEY::UP;     
        case 80: return KEY::DOWN;   
        case 75: return KEY::LEFT;   
        case 77: return KEY::RIGHT;  
        case 13: return KEY::ENTER;
        case 27: return KEY::ESCAPE;
        default: return KEY::CHARACTER;
        }
    }
    else {
        return KEY::ANY; //Прочая клавиша
    }
    return KEY::NONE;
}