#pragma once

#ifndef CLS_BILLS_QUEUE_H
#define CLS_BILLS_QUEUE_H

#include <iostream>
#include <string>

#include "clsQueue.h"

class clsBillsQueue
{
private:
    string _prefix;
    double _estTime;

public:
    clsBillsQueue(string prefix, double estTime) : _prefix(prefix), _estTime(estTime) {}
};

#endif
