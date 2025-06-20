#pragma once

#ifndef CLS_QUEUE_H
#define CLS_QUEUE_H

#include <iostream>
#include <optional>
#include "clsSingleLinkedList.h"

using namespace std;

template <typename T>
class clsQueue
{
private:
    clsSingleLinkedList<T> _list;

    void _displayEmptyQueue() const
    {
        cout << "Queue is empty." << endl;
    }

public:
    bool isEmpty() const
    {
        return _list.isEmpty();
    }

    int size() const
    {
        return _list.size();
    }

    void print() const
    {
        if (_list.isEmpty())
            return _displayEmptyQueue();

        _list.print();
    }

    void enqueue(const T &value)
    {
        _list.pushBack(value);
    }

    optional<T> dequeue()
    {
        if (_list.isEmpty())
        {
            _displayEmptyQueue();
            return nullopt;
        }

        return _list.popFront();
    }

    optional<T> front() const
    {
        if (_list.isEmpty())
        {
            _displayEmptyQueue();
            return nullopt;
        }

        return _list.front();
    }

    optional<T> back() const
    {
        if (_list.isEmpty())
        {
            _displayEmptyQueue();
            return nullopt;
        }

        return _list.back();
    }

    optional<T> getItem(int idx) const
    {
        clsSingleLinkedList::Node *node = _list.getItem(idx);

        if (node == nullptr)
        {
            cout << "Not found!" << endl;
            return nullopt;
        }

        return node->value;
    }

    void reverse()
    {
        _list.reverse();
    }

    void updateItem(int idx, T &newValue)
    {
        clsSingleLinkedList::Node *item = _list.getNode(idx);

        if (item != nullptr)
            item->value = newValue;
    }

    void insertAfter(int idx, T &value)
    {
        _list.insertAt(idx + 1, value);
    }

    void insertAtFront(T &value)
    {
        _list.pushFront(value);
    }

    void insertAtEnd(T &value)
    {
        _list.pushBack(value);
    }

    void clear()
    {
        _list.clear();
    }
};

#endif // CLS_QUEUE_H
