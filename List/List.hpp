#include <BitString/BitString.hpp>
#include <iostream>

class List {
    public:
        List *__prev, *__next;
        BitString *__ptr;

        List();

        void append(BitString *bitString);
        void insert(BitString *bitString, int index);
        BitString *pop(int index=-1);
        BitString *find(char* hexCharseq);
        
        friend ostream& operator << (ostream &out, List &p);
};
