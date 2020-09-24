#include "BitString/BitString.hpp"
#include <iostream>

using namespace std;


char* testMsg(char* returned, char* expected) {
    char* message = new char [32];
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
    cout << "1:  " << testMsg(BitString::or(bitString1, bitString2).toString(),
                                "12F4FFFE9BABFDEF") << '\n';
    cout << "2:  " << testMsg(BitString::and(bitString1, bitString2).toString(),
                                "1234001090AB4C0A") << '\n';
    cout << "3:  " << testMsg(BitString::xor(bitString1, bitString2).toString(),
                                "000C0FFEEB00B1E5") << '\n';
    cout << "4:  " << testMsg(BitString::not(bitString1).toString(),
                                "-123456796F543210") << '\n' << '\n';

    // Тоже корректный инпут, но в результате - оверфлоу                            
    bitString1 = BitString("0000000000000000");
    cout << "5:  " << testMsg(BitString::not(bitString1).toString(),
                                "FFFFFFFFFFFFFFFF") << '\n';
    bitString1 = BitString("7777777777777777");
    cout << "6:  " << testMsg(BitString::not(bitString1).toString(),
                                "8888888888888888") << '\n' << '\n';

    // Некорректный инпут
    bitString1 = BitString("12345678ABCDEFGH"); // буковы вне A-F
    cout << "7:  " << testMsg(bitString1.toString(),
                                "12345678ABCDEFGH") << '\n';
    bitString1 = BitString("BADA55D11D051337"); // заведомый оверфлоу (вне -7FFFFFFFFFFFFFFF до 7FFFFFFFFFFFFFFF)
    cout << "8:  " << testMsg(bitString1.toString(),
                                "BADA55D11D051337") << '\n';

    return 0;
}
