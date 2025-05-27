#include "RusEncryption.h"

RusEncryption& RusEncryption::setMap(int shift) {
    if (shift > 0) {
        for (size_t i = 0; i < 32; i++) //Генерируем заглавные буквы
            ch.insert({ 'А' + i, ('А' + i + shift) % 32 + 'А' });
        for (size_t i = 0; i < 32; i++) //Генерируем прописные
            ch.insert({ 'а' + i, ('а' + i + shift) % 32 + 'а' });
    }
    else {
        shift *= -1;
        for (size_t i = 0; i < 32; i++) //Генерируем заглавные буквы
            ch.insert({ ('А' + i + shift) % 32 + 'А', 'А' + i });
        for (size_t i = 0; i < 32; i++) //Генерируем прописные
            ch.insert({ ('а' + i + shift) % 32 + 'а', 'а' + i });
    }
    return *this;
}
std::string RusEncryption::encryption(const std::string& s) {
    std::string r = s;
    std::transform(r.begin(), r.end(), r.begin(), //Меняет буквы на соответствия в мапе
        [this](char letter) {
            return  (ch.count(letter) ? ch[letter] : letter); //Если буква найдена, возвращаем значение, если нет, возвращаем ее стандартную форму
        });
    return r;
}
std::string RusEncryption::decryption(const std::string& s) {
    std::string r = s;
    std::transform(r.begin(), r.end(), r.begin(), //Меняет буквы на соответствия в мапе
        [this](char letter) {
            for (auto p : ch)  //Ищем по знаяению
                if (p.second == letter) 
                    return p.first;
            return   letter; 
        });
    return r;
}