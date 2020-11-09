#include "BitString/BitString.hpp"
#include <iostream>
#include <cstring>

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
    // Вычислительные операции на корректном инпуте
    BitString bitString1 = BitString("1234567890ABCDEF");
    BitString bitString2 = BitString("12F4A9969BAB7C0A");

    cout << "1:  " << testMsg((char*)(bitString1 + bitString2),
                                "2529000F2C5749F9") << '\n';
    cout << "2:  " << testMsg((char*)(bitString1 - bitString2),
                                "-00C0531E0AFFAE1B") << '\n';
    cout << "3:  " << testMsg((char*)(bitString1 | bitString2),
                                "12F4FFFE9BABFDEF") << '\n';
    cout << "4:  " << testMsg((char*)(bitString1 & bitString2),
                                "1234001090AB4C0A") << '\n';
    cout << "5:  " << testMsg((char*)(bitString1 ^ bitString2),
                                "00C0FFEE0B00B1E5") << '\n';
    // Результат операции not с любым числом из данного диапазона находится вне диапазона,
    // т.к. not для [0, 7] это [8, F], а макс. значение старшего разряда -- 7
    cout << "6:  " << testMsg((char*)~bitString1,
                                "EDCBA9876F543210") << '\n' << '\n';

    // Операция присваивания
    BitString assignedBitString = bitString1;
    cout << "7:  " << testMsg((char*)assignedBitString,
                                "1234567890ABCDEF") << '\n' << '\n';

    // Некорректный инпут
    bitString1 = BitString("12345678ABCDEFGH"); // буковы вне A-F
    cout << "8:  " << testMsg((char*)bitString1, "12345678ABCDEFGH") << '\n';
    bitString1 = BitString("BADA55D11D051337"); // заведомый оверфлоу (вне -7FFFFFFFFFFFFFFF до 7FFFFFFFFFFFFFFF)
    cout << "9:  " << testMsg((char*)bitString1, "BADA55D11D051337") << '\n';

    return 0;
}
