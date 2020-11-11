#include "BitString.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

BitString::BitString() {}

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
            if (head > 2147483647) throw overflow_error(""); // В какой-то момент оно просто перестало кидаться при перегрузе
        } catch (exception& e) {
            cerr << "\x1B[33mWARNING: There's some overflow happening\033[0m\t\t" << '\n';
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
    } catch (exception& e) {
        head = NULL;
        tail = NULL;
    }
}

long int BitString::getHead() { return this->head; }

unsigned long int BitString::getTail() { return this->tail; }


BitString::operator char*(){
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
    if (printable[8] == '0') {
        int j = head > 0? 8 : 9;
        i = head > 0? 8 : 9;
        for (i, j; printable[j] == '0'; i--, j++);
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


istream& operator >> (istream &in, BitString &p) {
    char hexCharseq[17];
    in >> hexCharseq;
    p = BitString(hexCharseq);
    return in;
}

ostream& operator << (ostream &out, BitString &p) {
    out << (char*) p;
    return out;
}

ifstream& operator >> (ifstream &in, BitString &p) {
    in >> p.head >> p.tail;
    return in;
}

ofstream& operator << (ofstream &out, BitString &p) {
    out << p.head << " " << p.tail << '\n';
    return out;
}


BitString BitString::operator = (BitString other) {
    head = other.head;
    tail = other.tail;
    return *this;
}

BitString operator + (BitString _this, BitString other) {
    if (_this.tail + other.tail > 0xFFFFFFFF)
        return BitString(_this.head + other.head + (_this.tail + other.tail) / 0x100000000, 
                            (_this.tail + other.tail) % 0x100000000);
    else
        return BitString(_this.head + other.head, _this.tail + other.tail);
}

BitString BitString::operator - (BitString other) {
    return BitString(head - other.head, abs((long long int)tail - (long long int)other.tail));
}

BitString BitString::operator | (BitString other) {
    return BitString(head | other.head, tail | other.tail);
}

BitString BitString::operator & (BitString other) {
    return BitString(head & other.head, tail & other.tail);
}

BitString BitString::operator ^ (BitString other) {
    return BitString(head ^ other.head, tail ^ other.tail);
}

BitString BitString::operator ~ () {
    return BitString(~head, ~tail);
}
