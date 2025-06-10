#pragma once

#ifndef CLS_QUEUE_LINE_H
#define CLS_QUEUE_LINE_H

#include <iostream>
#include <string>

#include "clsQueue.h"
#include "clsDate.h"

class clsQueueLine
{
private:
    class clsTicket;

    string _prefix;
    double _estTime;
    int _totalTkts = 0, _servedClients = 0, _waitingClients = 0;
    clsQueue<clsTicket> _queueLine;

    void _initTicket(clsTicket &tkt)
    {
        clsDate date;

        tkt.id = _prefix + to_string(_totalTkts + 1);
        tkt.issuedDate = date.getDate();
        tkt.issuedTime = date.getTime();
        tkt.waitingClients = _waitingClients;
        tkt.waitingTime = _waitingClients * _estTime;
    }

public:
    class clsTicket
    {
    public:
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
        clsTicket tkt;
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
};

#endif
