#include <List/List.hpp>
#include <iostream>
#include <cstring>

using namespace std;

template <class T>
List<T>::List() {
    __ptr = NULL;
    __prev = NULL;
    __next = NULL;
}

template <class T>
void List<T>::append(T *t) {
    List *head = this;
    if (head->__ptr == NULL) {
        head->__ptr = t;
        return;
    }

    if (head->__next == NULL)
        head->__next = new List();
    List *node = head->__next;
    while (node->__ptr != NULL) {
        if (node->__next == NULL) {
            node->__next = new List();
            node->__next->__prev = node;
        }
        node = node->__next;
    }
    node->__ptr = t;
}

template <class T>
void List<T>::insert(T *t, int index) {
    List *head = this;
    List *node = head;
    for (int i = 0; i < index; i++)
        node = node->__next;
    
    T *temp1 = node->__ptr;
    node->__ptr = t;
    T *temp2;
    while (node->__next->__ptr != NULL) {
        temp2 = node->__next->__ptr;
        node->__next->__ptr = temp1;
        temp1 = temp2;
        node = node->__next;
        if (node->__next == NULL) {
            node->__next = new List();
            node->__next->__prev = node;
        }
    }
    node->__next->__ptr = temp1;
}

template <class T>
T* List<T>::pop(int index) {
    T *toReturn;
    List *head = this;
    List *node = head;
    if (index == -1) {
        while (node->__next != NULL)
            node = node->__next;
        toReturn = node->__ptr;
        node->__prev->__next = NULL;
    } else {
        for (int i = 0; i < index; i++)
            node = node->__next;
        toReturn = node->__ptr;
        while (node->__next != NULL) {
            node->__ptr = node->__next->__ptr;
            node = node->__next;
        }
        node->__prev->__next = NULL;
    }
    return toReturn;
}

template <class T>
T* List<T>::find(char* hexCharseq) {
    T *toReturn = NULL;
    List *head = this;
    List *node = head;
    while (node != NULL) {
        if (strcmp((char*)*(node->__ptr), hexCharseq) == 0) {
            toReturn = node->__ptr;
            break;
        }
        node = node->__next;
    }
    if (toReturn != NULL)
        return toReturn;
    else
        return new T("0");
}


template <class T>
ostream& operator << (ostream &out, List<T> &p) {
    List<T> *node = &p;
    out << '[';
    while (node != NULL) {
        out << *(node->__ptr);
        if (node->__next != NULL)
            out << ", ";
        node = node->__next;
    }
    out << ']';

    return out;
}

#pragma once;
