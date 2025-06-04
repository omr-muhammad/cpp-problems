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

    void popFront()
    {
        if (isEmpty())
            return _displayEmptyList();

        Node *temp = head;
        head = head->next;

        if (head == nullptr)
            tail = nullptr;

        delete temp;
        _size--;
    }

    void popBack()
    {
        if (isEmpty())
            return _displayEmptyList();

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node *cur = head;
        while (cur->next != tail)
            cur = cur->next;

        delete tail;
        tail = cur;
        tail->next = nullptr;

        _size--;
    }

    void insertAt(int idx, const T &value)
    {
        if (idx < 0 || idx > _size)
        {
            cout << "Index out of bounds." << endl;
            return;
        }

        if (idx == 0)
        {
            pushFront(value);
            return;
        }

        if (idx == _size)
        {
            pushBack(value);
            return;
        }

        int count = 0;
        Node *cur = head;
        Node *newNode = new Node;
        newNode->value = value;
        while (cout < idx - 1)
        {
            cur = cur->next;
            count++;
        }

        node->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    void deleteAt(int idx)
    {
        if (idx < 0 || idx >= _size)
        {
            cout << "Index out of bounds." << endl;
            return;
        }

        if (idx == 0)
        {
            popFront();
            return;
        }

        if (idx == _size - 1)
        {
            popBack();
            return;
        }

        int count = 0;
        Node *cur = head;
        while (count < idx - 1)
        {
            cur = cur->next;
            count++;
        }

        Node *toDelete = cur->next;
        cur->next = toDelete->next;
        delete toDelete;
        _size--;
    }

    Node *find(const T &value) const
    {
        Node *cur = head;
        while (cur != nullptr)
        {
            if (cur->value == value)
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }
};
#endif // CLS_SINGLE_LINKED_LIST_H