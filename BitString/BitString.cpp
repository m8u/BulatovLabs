#include "BitString.hpp"
#include <iostream>
#include "string.h"

BitString::BitString(char* hexCharseq) {
    head = 0;
    tail = 0;

    int len;
    for (len = 0; hexCharseq[len] != '\0'; len++); 

    int i = len - 1;
    long int powerOfSixteen = 1;
    int sign = hexCharseq[0] == '-'? -1 : 1; 
    for (i; i >= 0 && powerOfSixteen != 4294967296 && powerOfSixteen != 0; i--) {
        if (hexCharseq[i] <= 57) {
            tail += (hexCharseq[i] - 48) * powerOfSixteen; // 0-9
        } else {
            tail += (hexCharseq[i] - 55) * powerOfSixteen; // A-F
        }
        powerOfSixteen *= 16;
    }
    powerOfSixteen = 1;
    for (i; i >= 0; i--) {
        if (hexCharseq[i] == '-') break;

        try {
            if (hexCharseq[i] <= 57) {
                head += (hexCharseq[i] - 48) * powerOfSixteen * sign;
            } else {
                head += (hexCharseq[i] - 55) * powerOfSixteen * sign;
            }
        } catch (std::exception& e) {
            head = NULL;
            tail = NULL;
            break;
        }
        powerOfSixteen *= 16;
    }
}

BitString::BitString(long int _head, unsigned long int _tail) {
    try {
        head = _head;
        tail = _tail;
    } catch (std::exception& e) {
        head = NULL;
        tail = NULL;
    }
}

char* BitString::toString() {
    long int _head = head;
    unsigned long int _tail = tail;
    char* printable = new char[17]; strcpy(printable, "00000000000000000");

    int i = head > 0? 15 : 16;
    for (i; _tail != 0; i--) {
        if (_tail % 16 <= 9)
            printable[i] = (_tail % 16) + 48;
        else
            printable[i] = (_tail % 16) + 55;
        _tail /= 16;
    }
    for (i; _head != 0; i--) {
        if (abs(_head) % 16 <= 9) {
            printable[i] = (abs(_head) % 16) + 48;
        }
        else {
            printable[i] = (abs(_head) % 16) + 55;
        }
        _head /= 16;
    }
    if (head < 0)
        printable[0] = '-';
    else
        printable[16] = '\0';

    return printable;
}

BitString BitString::_or(BitString bitString1, BitString bitString2) {
    return BitString(bitString1.head | bitString2.head, bitString1.tail | bitString2.tail);
}

BitString BitString::_and(BitString bitString1, BitString bitString2) {
    return BitString(bitString1.head & bitString2.head, bitString1.tail & bitString2.tail);
}

BitString BitString::_xor(BitString bitString1, BitString bitString2) {
    return BitString(bitString1.head ^ bitString2.head, bitString1.tail ^ bitString2.tail);
}

BitString BitString::_not(BitString bitString) {
    return BitString(~bitString.head, ~bitString.tail);
}
