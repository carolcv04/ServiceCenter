#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "ListQueue.h"
#include <sstream>
#include <string>
class Customer{

    public: 
        Customer();
        ~Customer();
        Customer(std::string customerInfo); //sets customer information and number
        std::string accessOfficeInfo(); //accesses customers current & next offices
        std::string getOffice(); 
        int getOfficeTime();
        void reduceTime();
        void occoupied();
        void setIsBeingAttended(bool x); //customer is being attended
        bool getIsBeingAttended();
        int getCustomerNum();
        void addWaitTime();
        int getWaitTime();

    private:
        std::string* customerInfo;
        ListQueue<std::string> officeVisitOrder;
        int timeAtRegistrar;
        int customerNum;
        int timeAtCashier;
        int timeAtFinacialAid;
        int nextInfoIndex;
        int infoSize;
        int officeTime;
        int waitTime = -2;
        bool isBeingAttended;
        std::string nextOffice;
};

#endif