#pragma once

#ifndef CLS_DYNAMIC_ARRAY_H
#define CLS_DYNAMIC_ARRAY_H

#include <iostream>
#include <optional>

using namespace std;

template <typename T>
class clsDynamicArray
{
private:
    size_t _size = 0;
    T *_dArr = nullptr;

public:
    clsDynamicArray(size_t size = 0)
    {
        if (size != 0)
            _size = size;

        _dArr = new T[_size];
    }

    ~clsDynamicArray()
    {
        delete[] _dArr;
    }

    size_t size()
    {
        return _size;
    }

    void print()
    {
        for (size_t i = 0; i < _size; i++)
            cout << _dArr[i] << "  ";

        cout << '\n';
    }

    bool setItem(size_t idx, T newItem)
    {
        if (idx >= _size)
            return false;

        _dArr[idx] = newItem;
        return true;
    }

    bool isEmpty()
    {
        return _size <= 0;
    }

    void resize(size_t newSize)
    {
        if (newSize == _size)
            return;

        size_t minSize = newSize < _size ? newSize : _size;
        T *newArr = new T[minSize];
        for (size_t i = 0; i < minSize; ++i)
            newArr[i] = _dArr[i];

        delete[] _dArr;
        _dArr = newArr;
        _size = minSize;
    }

    optional<T> getItem(size_t idx)
    {
        return idx >= _size ? nullopt : _dArr[idx];
    }

    void reverse()
    {
        for (size_t i = 0; i < _size; ++i)
            swap(_dArr[i], _dArr[_size - i - 1]);
    }

    bool removeAt(size_t idx)
    {
        if (idx >= _size)
            return false;

        T *newArr = new T[_size - 1];
        for (size_t i = 0, j = 0; i < _size; ++i)
            if (i != idx)
                newArr[j++] = _dArr[i];

        delete[] _dArr;
        _dArr = newArr;
        --_size;
        return true;
    }
};

#endif // CLS_DYNAMIC_ARRAY_H
