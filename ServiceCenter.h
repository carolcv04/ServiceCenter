#ifndef SERVICECENTER_H
#define SERVICECENTER_H

#include <iostream>
#include <fstream>
#include "Office.h"
#include "ListQueue.h"

class ServiceCenter{

    public:
        ServiceCenter();
        ServiceCenter(std::string inputFile); //takes in a file with office and customer information
        ~ServiceCenter();
        int stringToInt(std::string string);
        void clockTick();
        void addCustomerToLine(Customer* c); 
        void updateCustomersInOffice();
        void updateOffice(Office* pOffice);
        void officeResults();

    private:
        int newCustomerAmount;
        
        int arrivalTime;
        int clockTime = 1;
        bool serviceIsOpen = true;
        ListQueue<Customer*> newCustomers;
        ListQueue<Customer*> currCustomers;
        ListQueue<Customer*> finishedCustomers;
        ListQueue<std::string> fileValues;
        Office* cashierOffice;
        Office* registrarOffice;
        Office* finacialOffice;
        int totalCustomers;

};

#endif