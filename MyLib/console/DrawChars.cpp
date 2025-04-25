#include "DrawChars.h"

void printRowChars(int s, char symbol, int color1, int color2) {
    if (color1)
        ((color2) ? setColor(color1, color2) : setColor(color1));
    for (int i = 0; i < s; i++)
        std::cout << symbol;
}

void printRowChars(int s, char l, char c, char r, int color1, int color2) {
    if (color1)
        ((color2) ? setColor(color1, color2) : setColor(color1));
    std::cout << l;
    for (int i = 1; i < s - 1; i++)
        std::cout << c;
    std::cout << r;
}

void drawFillRectangle(int posX, int posY, int rows, int cols, int color) {
    setCursorPosition(posX, posY);
    for (int r = 0; r < rows; r++) {
        printRowChars(cols, ' ', color);
        setCursorPosition(posX, posY + r + 1);
    }
    resetColor();
}

void drawEmptyRectangle2(int sX, int sY, int eX, int eY, int color) {
    int lengthX = eX - sX + 1; //Расстояние между точками Х
    int lengthY = eY - sY; //Расстояние между точками У
    if (color) setColor(color);
    system("chcp 866>nul");
    setCursorPosition(sX, sY); //устанавливаем курсор в левый верхний угол
    printRowChars(lengthX, Board_LT2, Board_H2, Board_RT2); //Рисуем верхнюю грань
    for (int i = 1; i < lengthY; i++) {//Рисуем правую и левую грань одновременно
        setCursorPosition(eX, sY + i);
        std::cout << Board_V2;
        setCursorPosition(sX, sY + i);
        std::cout << Board_V2;
    }
    setCursorPosition(sX, eY);
    printRowChars(lengthX, Board_LD2, Board_H2, Board_RD2);
    if(color)resetColor();
    system("chcp 1251>nul");
}

void centerWord(const char* text, int totalLen) {
    int spaces = (totalLen - strlen(text)) / 2;
    printRowChars(spaces, ' ');
    std::cout << text;
    printRowChars(totalLen - spaces - strlen(text), ' ');
}