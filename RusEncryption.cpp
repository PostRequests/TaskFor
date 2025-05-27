#include "RusEncryption.h"

RusEncryption& RusEncryption::setMap(int shift) {
    if (shift > 0) {
        for (size_t i = 0; i < 32; i++) //���������� ��������� �����
            ch.insert({ '�' + i, ('�' + i + shift) % 32 + '�' });
        for (size_t i = 0; i < 32; i++) //���������� ���������
            ch.insert({ '�' + i, ('�' + i + shift) % 32 + '�' });
    }
    else {
        shift *= -1;
        for (size_t i = 0; i < 32; i++) //���������� ��������� �����
            ch.insert({ ('�' + i + shift) % 32 + '�', '�' + i });
        for (size_t i = 0; i < 32; i++) //���������� ���������
            ch.insert({ ('�' + i + shift) % 32 + '�', '�' + i });
    }
    return *this;
}
std::string RusEncryption::encryption(const std::string& s) {
    std::string r = s;
    std::transform(r.begin(), r.end(), r.begin(), //������ ����� �� ������������ � ����
        [this](char letter) {
            return  (ch.count(letter) ? ch[letter] : letter); //���� ����� �������, ���������� ��������, ���� ���, ���������� �� ����������� �����
        });
    return r;
}
std::string RusEncryption::decryption(const std::string& s) {
    std::string r = s;
    std::transform(r.begin(), r.end(), r.begin(), //������ ����� �� ������������ � ����
        [this](char letter) {
            for (auto p : ch)  //���� �� ��������
                if (p.second == letter) 
                    return p.first;
            return   letter; 
        });
    return r;
}