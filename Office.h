#ifndef OFFICE_H
#define OFFICE_H

#include "Customer.h"
#include "Dblist.h"
#include "Window.h"
#include <iostream>

class Office{

    public:
        Office();
        ~Office();
        Office(std::string name, int windowsOpen); //name of the office and windows available
        void setOfficeWindows();
        bool isEmpty();
        bool allWindowsIdle();
        void setTime(int x);
        void addCustomerToLine(Customer* c);
        ListQueue<Customer*> updateCustomersInOffice(); //updates the customers status and returns a queue with customers that are done at the office
        void getOfficeStats();
        int getWaitTimeOverTen();
        int getIdleWindowsOverFive();
        int getLongestIdleTime();
        void incrementWaitTime();
        int getCustomersWaitingOverTen();
        
    private:
        std::string name;
        int longestTime = 0;
        int numOfCustomers = 0;
        int customerNum, customerWaitingOverTen, idleWindowsOverFive, idleTime, longestIdleTime, time, waitTimeOverTen;
        DoublyLinked<Window*> windowsAvailable;
        ListQueue<Customer*> customerQueue;
};

#endif