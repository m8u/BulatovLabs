#include "BitString/BitString.hpp"
#include <iostream>

using namespace std;


int main() {
    BitString bitString1 = BitString("13243546576879AB");
    BitString bitString2 = BitString("31425364758697EF");

    cout << (bitString1 | bitString2).toString() << '\n';
    cout << (bitString1 & bitString2).toString() << '\n';
    cout << (bitString1 ^ bitString2).toString() << '\n';
    cout << (~bitString1).toString() << '\n';

    return 0;
}
