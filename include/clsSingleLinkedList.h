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

        Node *cur = _head;

        while (cur != nullptr)
        {
            cout << cur->value << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    optional<T> front() const
    {
        if (isEmpty())
        {
            _displayEmptyList();
            return nullopt;
        }
        return _head->value;
    }

    optional<T> back() const
    {
        if (isEmpty())
        {
            _displayEmptyList();
            return nullopt;
        }
        return _tail->value;
    }

    void pushFront(const T &value)
    {
        // Setting up newNode
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = _head;

        // Update List Nodes
        _head = newNode;

        // If the list was empty, set _tail to newNode
        if (_tail == nullptr)
        {
            _tail = newNode;
        }

        _size++;
    }

    void pushBack(const T &value)
    {
        // Setting up newNode
        Node *newNode = new Node;
        newNode->value = value;

        _tail->next = newNode;
        _tail = newNode;

        if (isEmpty())
        {
            _head newNode;
        }

        _size++;
    }

    optional<T> popFront()
    {
        if (isEmpty())
        {
            _displayEmptyList();
            return nullopt;
        }

        T deletedValue = _head->value;
        Node *temp = _head;
        _head = _head->next;

        if (_head == nullptr)
            _tail = nullptr;

        delete temp;
        _size--;
        return deletedValue;
    }

    optional<T> popBack()
    {
        if (isEmpty())
        {
            _displayEmptyList();
            return nullopt;
        }

        T deletedValue = nullopt;

        if (_head == _tail)
        {
            deletedValue = _head->value;
            delete _head;
            _head = _tail = nullptr;
            return deletedValue;
        }

        Node *cur = _head;
        while (cur->next != _tail)
            cur = cur->next;

        deletedValue = _tail->value;
        delete _tail;
        _tail = cur;
        _tail->next = nullptr;

        _size--;
        return deletedValue;
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
        Node *cur = _head;
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
        Node *cur = _head;
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
        Node *cur = _head;
        while (cur != nullptr)
        {
            if (cur->value == value)
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    Node *getNode(int idx) const
    {
        if (idx < 0 || idx >= _size)
        {
            cout << "Index out of bounds." << endl;
            return nullptr;
        }

        if (isEmpty())
        {
            _displayEmptyList();
            return nullptr;
        }

        Node *cur = _head;
        for (int i = 0; i < idx; ++i)
        {
            cur = cur->next;
        }

        return cur;
    }

    bool isEmpty() const
    {
        return _size == 0;
    }

    int size() const
    {
        return _size;
    }

    void clear()
    {
        while (!isEmpty())
            popFront();
    }

    void reverse()
    {
        Node *cur = _head;
        Node *prev = nullptr;

        _tail = _head;

        while (cur != nullptr)
        {
            Node *nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        _head = prev;
    }
};
#endif // CLS_SINGLE_LINKED_LIST_H
