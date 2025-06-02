#pragma once

#ifndef CLS_DOUBLE_LINKED_LIST_H
#define CLS_DOUBLE_LINKED_LIST_H

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

template <typename T>
class clsDoubleLinkedList
{
public:
    class Node
    {
    public:
        T value;
        Node *next;
        Node *prev;
    };
    Node *head = NULL;
    Node *tail = NULL;

    void print() const
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *cur = head;

        while (cur != tail)
        {
            cout << cur->value << " ";
            cur = cur->next;
        }
    }
};
#endif // CLS_DOUBLE_LINKED_LIST_H