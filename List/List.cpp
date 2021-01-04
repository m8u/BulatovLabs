#include <List/List.hpp>
#include <BitString/BitString.hpp>
#include <iostream>
#include <cstring>

using namespace std;

List::List() {
    __ptr = NULL;
    __prev = NULL;
    __next = NULL;
}

void List::append(BitString *bitString) {
    List *head = this;
    if (head->__ptr == NULL) {
        head->__ptr = bitString;
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
    node->__ptr = bitString;
}

void List::insert(BitString *bitString, int index) {
    List *head = this;
    List *node = head;
    for (int i = 0; i < index; i++)
        node = node->__next;
    
    BitString *temp1 = node->__ptr;
    node->__ptr = bitString;
    BitString *temp2;
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

BitString* List::pop(int index) {
    BitString *toReturn;
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

BitString* List::find(char* hexCharseq) {
    BitString *toReturn = NULL;
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
        return new BitString("0");
}


ostream& operator << (ostream &out, List &p) {
    List *node = &p;
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
