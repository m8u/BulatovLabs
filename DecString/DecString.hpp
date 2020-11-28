#include <BitString/BitString.hpp>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class DecString: public BitString {
    // -9223372036854775807 to 9223372036854775807 but not really
    
    void setDateCreated();

    public:
        DecString();
        DecString(char* hexCharseq);
        DecString(long int _head, unsigned long int _tail);

        long long int getNumber();
        operator char*();

        char* toOct();
        char* toHex();

        tm dateCreated;

        friend istream& operator >> (istream& in, DecString &p);
        friend ostream& operator << (ostream& out, DecString &p);
};