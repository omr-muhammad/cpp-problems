#pragma once

#ifndef CLS_DOUBLE_LINKED_LIST_H
#define CLS_DOUBLE_LINKED_LIST_H

#include <iostream>
#include <list>

using namespace std;

template <typename T>
class clsDoubleLinkedList
{
private:
    list<T> _dbList;
    size_t _size = 0;

public:
    // Default constructor initializes an empty double-lined list.
    clsDoubleLinkedList() = default;

    void printList() const
    {
        if (_dbList.empty())
        {
            cout << "The list is empty." << endl;
            return;
        }

        for (const auto &item : _dbList)
            cout << item << " - ";

        cout << endl;
    }
};

#endif // CLS_DOUBLE_LINKED_LIST_H