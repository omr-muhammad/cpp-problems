#pragma once

#ifndef CLS_SINGLE_LINKED_LIST_H
#define CLS_SINGLE_LINKED_LIST_H

#include <iostream>
#include <optional>

using namespace std;

template <typename T>
class clsSingleLinkedList
{
private:
    int _size = 0;

    void _displayEmptyList() const
    {
        cout << "List is empty." << endl;
    }

public:
    class Node
    {
    public:
        T value;
        Node *next = nullptr;
    };

    void print() const
    {
        if (isEmpty())
            return _displayEmptyList();

        Node *cur = head;

        while (cur != nullptr)
        {
            cout << cur->value << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

#endif // CLS_SINGLE_LINKED_LIST_H