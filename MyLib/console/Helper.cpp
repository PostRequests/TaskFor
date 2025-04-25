#include "Helper.h"

bool includeContainsOnly(char* text, const char* content) {
    if (!*text) return false;
    for (; (*text); text++) {
        bool include = false;
        for (const char* c = content; *c; c++) {
            if (*c == *text) {
                include = true;
                break;
            }
        }
        if (!include) return false;
    }
    return true;
}
bool isNumber(char* text) {
    return includeContainsOnly(text, "1234567890-");
}
int strToInt(char* num) {
    if (!isNumber(num)) return 0;
    int result = 0;//Результат функции
    int multiplier = 1; //Множитель
    bool isNegative = (*num == '-') ? true : false;
    if (isNegative) num++;
    char* end = num + strlen(num) - 1;
    for (; end != num - 1; end--, multiplier *= 10) {
        result += (*end - '0') * multiplier;
    }
    return ((isNegative) ? -result : result);
}