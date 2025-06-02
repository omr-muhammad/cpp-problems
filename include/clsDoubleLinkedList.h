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
private:
    int _size = 0;

public:
    class Node
    {
    public:
        T value;
        Node *next = NULL;
        Node *prev = NULL;
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

    void insertAtBeginning(const T &value)
    {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = head;

        if (head == NULL)
        {
            head = tail = newNode;
            // [next, prev] are initially NULL
        }
        else
        {
            // This line handle One list node since head = tail = newNode at the first insertion
            head->prev = newNode;
            head = newNode;
        }

        _size++;
    }
};
#endif // CLS_DOUBLE_LINKED_LIST_H