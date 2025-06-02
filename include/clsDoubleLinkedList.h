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
        Node *next = nullptr;
        Node *prev = nullptr;
    };

    Node *head = nullptr;
    Node *tail = nullptr;

    void print() const
    {
        if (head == nullptr)
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
};
#endif // CLS_DOUBLE_LINKED_LIST_H