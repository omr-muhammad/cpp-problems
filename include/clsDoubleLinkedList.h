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
        Node *prev = nullptr;
    };

    Node *head = nullptr;
    Node *tail = nullptr;

    int size() const
    {
        return _size;
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    void print() const
    {
        if (isEmpty())
            return _displayEmptyList();

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

        if (head == nullptr)
        {
            head = tail = newNode;
            // [next, prev] are initially nullptr
        }
        else
        {
            // This line handle One list node since head = tail = newNode at the first insertion
            head->prev = newNode;
            head = newNode;
        }

        _size++;
    }

    void insertAtEnd(const T &value)
    {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->prev = tail;

        if (head == nullptr)
        {
            head = tail = newNode;
            // [next, prev] are initially nullptr
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        _size++;
    }

    void insertAfter(const int idx, const T &value)
    {
        Node *node = getNodeByIndex(idx);
        if (node == nullptr)
        {
            cout << "Node not found." << endl;
            return;
        }

        insertAfter(node, value);
    }

    void insertAfter(Node *node, const T &value)
    {
        if (node == nullptr || find(node->value) == nullptr)
        {
            cout << "Node not found." << endl;
            return;
        }

        // Setting up newNode
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = node->next;
        newNode->prev = node;

        // Update List Nodes
        if (node != tail)
            newNode->next->prev = newNode;
        else
            tail = newNode;

        node->next = newNode;
        _size++;
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

        return nullptr; // Not found 😢
    }

    void deleteNode(Node *node)
    {
        if (isEmpty())
            return _displayEmptyList();

        if (node == nullptr || find(node->value) == nullptr)
        {
            cout << "Node not found." << endl;
            return;
        }

        if (node == head)
            return deleteFirstNode();

        if (node == tail)
            return deleteLastNode();

        // Of course, node is neither head nor tail
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        _size--;
    }

    void deleteFirstNode()
    {
        if (isEmpty())
            return _displayEmptyList();

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        --_size;
    }

    void deleteLastNode()
    {
        if (isEmpty())
            return _displayEmptyList();

        if (head == tail)
        {
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        --_size;
    }

    void clear()
    {
        while (!isEmpty())
            deleteFirstNode();
    }

    void reverse()
    {
        if (isEmpty())
            return _displayEmptyList();

        Node *cur = head;
        while (cur != nullptr)
        {
            Node *temp = cur->next;
            cur->next = cur->prev;
            cur->prev = temp;
            cur = temp;
        }

        // Swap head and tail
        Node *temp = head;
        head = tail;
        tail = temp;
    }

    Node *getNodeByIndex(int idx) const
    {
        if (isEmpty())
        {
            _displayEmptyList();
            return nullptr;
        }

        if (idx < 0 || idx >= _size)
        {
            cout << "Index out of bounds." << endl;
            return nullptr;
        }

        // Determine if we should start from head or tail
        bool afterMid = idx > _size / 2;
        int count = afterMid ? _size - 1 : 0;
        Node *cur = afterMid ? tail : head;

        while (count != idx)
        {
            cur = afterMid ? cur->prev : cur->next;
            count += afterMid ? -1 : 1;
        }

        return cur;
    }

    // optional<T> for modern C++ versions
    // optional<T> getValueByIndex(int idx) const
    // {
    //     Node *node = getNodeByIndex(idx);
    //     return node ? node->value : nullopt;
    // }

    T getValueByIndex(int idx) const
    {
        Node *node = getNodeByIndex(idx);

        return node ? node->value : NULL;
    }

    bool updateItem(int idx, const T &value)
    {
        Node *node = getNodeByIndex(idx);

        if (node == nullptr)
            return false;

        node->value = value;
        return true;
    }
};
#endif // CLS_DOUBLE_LINKED_LIST_H