#include "BitString/BitString.hpp"
#include <iostream>

using namespace std;


int main() {

    BitString bitString = BitString("-7FFFFFFFFFFFFFFF");

    char* a = bitString.toString();

    cout << a << '\n';

    return 0;
}