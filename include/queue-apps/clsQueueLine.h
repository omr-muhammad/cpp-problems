#pragma once

#ifndef CLS_QUEUE_LINE_H
#define CLS_QUEUE_LINE_H

#include <iostream>
#include <string>

#include "clsQueue.h"
#include "clsDate.h"

using namespace std;

class clsQueueLine
{
private:
    struct stTicket;

    string _prefix;
    double _estTime;
    int _totalTkts = 0, _servedClients = 0, _waitingClients = 0;
    clsQueue<stTicket> _queueLine;

    void _initTicket(stTicket &tkt)
    {
        clsDate date;

        tkt.id = _prefix + to_string(_totalTkts + 1);
        tkt.issuedDate = date.getDate();
        tkt.issuedTime = date.getTime();
        tkt.waitingClients = _waitingClients;
        tkt.waitingTime = _waitingClients * _estTime;
    }

    void _printEmptyLine()
    {
        cout << "Line is Empty!\n";
    }

    void _getTktAndPrint(int idx)
    {
        stTicket emptyTkt;
        stTicket curTkt = _queueLine.getItem(idx).value_or(emptyTkt);

        if (!curTkt.id.empty())
            cout << curTkt.id;
    }

    void _printTkt(const stTicket &tkt)
    {
        cout << "\n\t\t\t  _______________________\n";
        cout << "\n\t\t\t\t    " << tkt.id;
        cout << "\n\n\t\t\t    " << tkt.issuedDate << '  -  ' << tkt.issuedTime;
        cout << "\n\t\t\t    Wating Clients:  " << tkt.waitingClients;
        cout << "\n\t\t\t      Estimated Time: " << tkt.waitingTime << " Minutes.";
        cout << "\n\t\t\t  _______________________\n";
    }

public:
    struct stTicket
    {
        string id;
        string issuedDate;
        string issuedTime;
        int waitingClients;
        double waitingTime;
    };
    clsQueueLine(string prefix, double estTime) : _prefix(prefix), _estTime(estTime) {}

    void issueTkt()
    {
        // Prepare the ticket
        stTicket tkt;
        _initTicket(tkt);

        // Updating Queue
        _queueLine.enqueue(tkt);
        _totalTkts++;
        _waitingClients++;
    }

    void printInfo()
    {
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t\tQueue Info";
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t    Prefix   = " << _prefix;
        cout << "\n\t\t\t    Total Tickets   = " << _totalTkts;
        cout << "\n\t\t\t    Served Clients  = " << _servedClients;
        cout << "\n\t\t\t    Wating Clients  = " << _waitingClients;
        cout << "\n\t\t\t _________________________\n";
        cout << "\n";
    }

    void printTktLineRTL()
    {
        if (_queueLine.size() == 0)
            return _printEmptyLine();

        cout << "Tickets: ";
        for (int i = 0; i < _queueLine.size(); ++i)
        {
            _getTktAndPrint(i);
            if (i < _queueLine.size() - 1)
                cout << "     <--     ";
        }

        cout << endl;
    }

    void printTktLineLTR(int idx = 0)
    {
        if (_queueLine.size() == 0)
            return _printEmptyLine();

        if (idx < _queueLine.size() - 1)
            printTktLineLTR(++idx);

        if (idx == _queueLine.size() - 1)
            cout << "Tickets:    ";

        _getTktAndPrint(idx);

        if (idx != 0)
            cout << "     -->     ";
        else
            cout << "\n";
    }

    void printAllTkts()
    {
        for (int i = 0; i < _queueLine.size(); ++i)
        {
            stTicket emptyTkt;
            stTicket curTkt = _queueLine.getItem(i).value_or(emptyTkt);

            if (!curTkt.id.empty())
                _printTkt(curTkt);
        }
    }
};

#endif
