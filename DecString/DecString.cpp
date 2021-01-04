#include <DecString/DecString.hpp>
#include <BitString/BitString.hpp>
#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

DecString::DecString() : BitString::BitString() {
    setDateCreated();
}
DecString::DecString(char* hexCharseq) : BitString::BitString(hexCharseq) {
    setDateCreated();
}
DecString::DecString(long int _head, unsigned long int _tail) : BitString::BitString(_head, _tail) {
    setDateCreated();
}

long long int DecString::getNumber() {
    return head * tail + tail;
}

DecString::operator char*(){ 
    long long int number = getNumber();
    char* printable = new char[21]; strcpy(printable, "000000000000000000000");

    int i = number >= 0? 19 : 20;
    for (i; number != 0; i--) {
        printable[i] = (number % 10) + 48;
        number /= 10;
    }
    if (number < 0)
        printable[0] = '-';
    else
        printable[20] = '\0';

    return printable;
}

char* DecString::toOct() {
    // -777777777777777777777 to 777777777777777777777
    long long int number = getNumber();
    char* printable = new char[23]; strcpy(printable, "00000000000000000000000");

    bool isNegative = number < 0;
    int i = !isNegative? 21 : 22;
    for (i; number != 0; i--) {
        printable[i] = (number % 8) + 48;
        number /= 8;
    }
    if (isNegative)
        printable[0] = '-';
    else
        printable[22] = '\0';

    return printable;
}

char* DecString::toHex() {
    long long int number = getNumber();
    char* printable = new char[17]; strcpy(printable, "00000000000000000");

    bool isNegative = number < 0;
    int i = !isNegative? 15 : 16;
    for (i; number != 0; i--) {
        if (abs(number) % 16 <= 9) {
            printable[i] = (abs(number) % 16) + 48;
        }
        else {
            printable[i] = (abs(number) % 16) + 55;
        }
        number /= 16;
    }
    if (isNegative)
        printable[0] = '-';
    else
        printable[16] = '\0';

    return printable;
}

void DecString::setDateCreated() {
    time_t now = time(0);
    dateCreated = *localtime(&now);
    dateCreated.tm_year += 1900;
    dateCreated.tm_mon += 1;
}

istream& operator >> (istream &in, DecString &p) {
    char decCharseq[21];
    in >> decCharseq;
    p = DecString(decCharseq);
    return in;
}

ostream& operator << (ostream &out, DecString &p) {
    out << (char*) p;
    return out;
}
