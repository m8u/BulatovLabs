#include "BitString/BitString.hpp"
#include <iostream>
#include "string.h"

using namespace std;

char* testMsg(char* returned, char* expected) {
    char* what = new char[0]; // без этой штуки message почему-то создается с адресом returned
    char* message = new char [64];
    if (strcmp(returned, expected) == 0) {
        strcpy(message, strcat(returned, " - OK"));
    } else {
        strcpy(message, strcat(strcat(returned, " - WRONG, expected: "), expected));
    }
    return message;
}


int main() {
    // Побитовые операции на корректном инпуте
    BitString bitString1 = BitString("1234567890ABCDEF");
    BitString bitString2 = BitString("12F4A9969BAB7C0A");
    cout << "1:  " << testMsg(BitString::_or(bitString1, bitString2).toString(),
                                "12F4FFFE9BABFDEF") << '\n';
    cout << "2:  " << testMsg(BitString::_and(bitString1, bitString2).toString(),
                                "1234001090AB4C0A") << '\n';
    cout << "3:  " << testMsg(BitString::_xor(bitString1, bitString2).toString(),
                                "000C0FFEEB00B1E5") << '\n';
    // Результат операции not с любым числом из данного диапазона находится вне диапазона,
    // т.к. not для [0, 7] это [8, F], а макс. значение старшего разряда -- 7
    cout << "4:  " << testMsg(BitString::_not(bitString1).toString(),
                                "EDCBA9876F543210") << '\n' << '\n';

    // Некорректный инпут
    bitString1 = BitString("12345678ABCDEFGH"); // буковы вне A-F
    cout << "7:  " << testMsg(bitString1.toString(),
                                "12345678ABCDEFGH") << '\n';
    bitString1 = BitString("BADA55D11D051337"); // заведомый оверфлоу (вне -7FFFFFFFFFFFFFFF до 7FFFFFFFFFFFFFFF)
    cout << "8:  " << testMsg(bitString1.toString(),
                                "BADA55D11D051337") << '\n';

    return 0;
}
