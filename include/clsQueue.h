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

    void dequeue()
    {
        if (_list.isEmpty())
            return _displayEmptyQueue();
        {
            return _list.isEmpty();
        }

        _list.popFront();
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
};

#endif // CLS_QUEUE_H