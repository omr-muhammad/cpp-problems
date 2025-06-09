#pragma once

#ifndef CLS_STACK_H
#define CLS_STACK_H

#include <iostream>
#include <optional>

#include "clsSingleLinkedList.h"

template <typename T>
class clsStack
{
private:
    clsSingleLinkedList<T> _list;

public:
    int size()
    {
        _list.size();
    }

    void push(T &value)
    {
        _list.pushBack(value);
    }

    optional<T> top()
    {
        _list.back();
    }

    optional<T> bottom()
    {
        _list.front();
    }

    optional<T> pop()
    {
        return _list.popBack();
    }

    optional<T> getItem(int idx)
    {
        typename clsSingleLinkedList::Node *node = _list.getNode(idx);

        if (node != nullptr)
            return node->value;

        return nullopt;
    }

    void reverse()
    {
        _list.reverse();
    }

    void updateItem(int idx, T &newValue)
    {
        typename clsSingleLinkedList::Node *node = _list.getNode(idx);

        if (node != nullptr)
            node->value = newValue;
    }

    void insertAfter(int idx, T &value)
    {
        _list.insertAt(idx + 1, value);
    }

    void insertAtFront(T &value)
    {
        _list.pushFront(value);
    }

    void insertAtBack(T &value)
    {
        _list.pushBack(value);
    }

    void clear()
    {
        _list.clear();
    }
};

#endif // CLS_STACK_H
