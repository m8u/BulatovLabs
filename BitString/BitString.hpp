#include <iostream>
#include <fstream>
using namespace std;

class BitString {
    protected:
        long int head;
        unsigned long int tail;
        // -7FFFFFFFFFFFFFFF to 7FFFFFFFFFFFFFFF

    public:
        BitString();
        BitString(char* hexCharseq);
        BitString(long int _head, unsigned long int _tail);

        long int getHead();
        unsigned long int getTail();

        operator char*();

        friend istream& operator >> (istream& in, BitString &p);
        friend ostream& operator << (ostream& out, BitString &p);
        friend ifstream& operator >> (ifstream& in, BitString &p);
        friend ofstream& operator << (ofstream& out, BitString &p);

        BitString operator = (BitString other); 
        friend BitString operator + (BitString _this, BitString other);
        BitString operator - (BitString other);
        BitString operator | (BitString other);
        BitString operator & (BitString other);
        BitString operator ^ (BitString other);
        BitString operator ~ ();
};

#pragma once
