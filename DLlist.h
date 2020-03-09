//
// Created by rarce on 03/09/20.
//
#include <cstdlib>
#include <iostream>

using namespace std;

#ifndef UNTITLED3_DLLIST_H
#define UNTITLED3_DLLIST_H

class DNode {
public:
    int data;
    DNode *next;
    DNode *prev;
    DNode(int d, DNode *n = NULL, DNode *p = NULL): data(d), next(n), prev(p) {}

};

class DLlist {
private:
    DNode *head;
    DNode *tail;
    int length;
public:
    DLlist(): head(NULL), tail(NULL), length(0) {}
    void insertAfter(DNode *curNode, int value);
    int at(int idx) const;
    void removeFirst();
    void append(int value);
    void prepend(int value);
    int getSize() const;
    ~DLlist();
    DNode *search(int key) const;

};


#endif //UNTITLED3_DLLIST_H
