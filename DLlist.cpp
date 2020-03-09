//
// Created by rarce on 03/09/20.
//

#include "DLlist.h"

void DLlist::insertAfter(DNode *curNode, int value) {
    DNode *n = new DNode(value);
    if (curNode == NULL) {
        if (head != NULL) head->prev = n;
        n->next = head;
        head = n;
        if (tail == NULL) tail = n;
    }
    else {
        DNode *p = curNode->next;
        n->prev = curNode;
        n->next = p;
        curNode->next = n;
        if (p != NULL) p->prev = n;
        else tail = n;
    }
    length++;
}

void DLlist::append(int value)  { insertAfter(tail,value); }

void DLlist::prepend(int value) { insertAfter(NULL,value); }

int DLlist::at(int idx) const {
    int i = 0;

    // validate the index
    if (idx < 0 || idx >= length) {
        cout << "error" << endl;
        exit(1);
    }

    // traverse the list until index
    DNode *p = head;
    for (int i = 0; i < idx; i++) p = p->next;
    return p->data;
}

void DLlist::removeFirst() {
    DNode *p;
    p = head;
    head = head ->next;
    if (head != NULL) head-> prev = NULL;
    else tail = NULL;
    delete p;
    length--;
}

int DLlist::getSize() const { return length; }

DLlist::~DLlist() {
    while (head!=NULL) {
        removeFirst();
    }
}

DNode* DLlist::search(int key) const {
    DNode *p = head;
    while (p != NULL) {
        if (p->data == key) return p;
        p = p->next;
    }
    return p;
}

