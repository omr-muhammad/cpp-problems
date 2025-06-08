#pragma once

#ifndef CLS_DYNAMIC_ARRAY_H
#define CLS_DYNAMIC_ARRAY_H

#include <iostream>

template <typename T>
class clsDynamicArray
{
private:
    size_t _size = 0;
    T *_dArr;

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
};

#endif // CLS_DYNAMIC_ARRAY_H
