#ifndef WINDOW_H
#define WINDOW_H
#include "Customer.h"

class Window{

    public: 
        Window();
        ~Window();
        bool isIdle();
        void attendCustomer(Customer* c); //attends a customer
        void setOccupied(bool occ);
        Customer* getCustomerAtWindow();
        bool getIsOccupied();
        void removeCustomer();
        void incrementIdleTime();
        int getIdleTime();
        int getLongestIdleTime();
        int getCustomersAttended();
        bool getIdleForMoreThanFive();

    private:
        bool isOccupied;
        int idleTime = -2;
        bool idleForMoreThanFive;
        int totalIdleTime, customersAttended;
        ListQueue<Customer*> customerAtWindow;
};

#endif