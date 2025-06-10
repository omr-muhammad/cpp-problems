#pragma once

#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include <string>

#include "clsStack.h"

class clsMyString
{
private:
    string _value = "";
    clsStack<string> _undoStack;
    clsStack<string> _reUndoStack;

public:
    void setValue(string newValue = "")
    {
        _value = newValue;
        _undoStack.push(newValue);
    }

    string getValue() const
    {
        return _value;
    }

    void undo()
    {
        if (_undoStack.size() <= 1)
            return; // Prevent Udoing init state

        _reUndoStack.push(_value);

        _undoStack.pop();
        string newValue = _undoStack.top().value_or("");
        setValue(newValue);
    }

    void redo()
    {
        if (_reUndoStack.size() <= 0)
            return;

        string reUndoValue = _reUndoStack.pop().value_or("");

        // It handles pushing to _undoStack :D
        setValue(reUndoValue);
    }
};

#endif
