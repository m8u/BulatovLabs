#include "BitString.hpp"
#include <iostream>

BitString::BitString(char* hexCharseq) {
    head = 0;
    tail = 0;

    int len;
    for (len = 0; hexCharseq[len] != '\0'; len++); 

    int i = len - 1;
    long int powerOfSixteen = 1;
    int sign = hexCharseq[0] == '-'? -1 : 1; 
    for (i; i >= 0 && powerOfSixteen != 4294967296; i--) {
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

        if (hexCharseq[i] <= 57) {
            head += (hexCharseq[i] - 48) * powerOfSixteen * sign;
        } else {
            head += (hexCharseq[i] - 55) * powerOfSixteen * sign;
        }
        powerOfSixteen *= 16;
    }
}

char* BitString::toString() {
    long int _head = head;
    unsigned long int _tail = tail;
    char printable[18] = "00000000000000000";

    int i = head > 0? 15 : 16;
    for (i; _tail > 0; i--) {
        if (_tail % 16 <= 9)
            printable[i] = (_tail % 16) + 48;
        else
            printable[i] = (_tail % 16) + 55;
        _tail /= 16;
    }

    return (char*)printable;
}
