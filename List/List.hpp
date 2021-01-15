#include <BitString/BitString.hpp>
#include <iostream>

template <class T> class List {
    public:
        List<T> *__prev, *__next;
        T *__ptr;

        List();

        void append(T *t);
        void insert(T *t, int index);
        T *pop(int index=-1);
        T *find(char* hexCharseq);
        
        template <class U> friend ostream& operator << (ostream &out, List<U> &p);
};

#pragma once;

#include <List/List.tpp>
