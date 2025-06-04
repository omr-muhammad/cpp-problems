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
    Node *_head = nullptr;
    Node *_tail = nullptr;

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

    void pushFront(const T &value)
    {
        // Setting up newNode
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = head;

        // Update List Nodes
        head = newNode;

        // If the list was empty, set tail to newNode
        if (tail == nullptr)
        {
            tail = newNode;
        }

        _size++;
    }

    void pushBack(const T &value)
    {
        // Setting up newNode
        Node *newNode = new Node;
        newNode->value = value;

        tail->next = newNode;
        tail = newNode;

        if (isEmpty())
        {
            head newNode;
        }

        _size++;
    }
};

#endif // CLS_SINGLE_LINKED_LIST_H