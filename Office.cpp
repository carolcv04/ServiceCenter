
//models an individual office in the service center
#include "Office.h"

Office::Office(){}

Office::~Office(){}

Office::Office(std::string name, int windowsOpen){
    this->name = name;

    for(int i = 0; i < windowsOpen; ++i){ //creates avavilable windows for the office
        Window* newWindow = new Window();
        windowsAvailable.insertBack(newWindow);
    }
}

ListQueue<Customer*> Office::updateCustomersInOffice(){

    ListQueue<Customer*> updatedCustomers;

    for(int i = 0; i < windowsAvailable.getSize(); i++){
        Window* w = windowsAvailable.getFront();

        if(w->isIdle()){ //if a windo is idle, idle time is incremeneted
            w->incrementIdleTime(); 

            if(w->getIdleTime() > longestIdleTime){ //keeps track of the longest idle window
                longestIdleTime = w->getIdleTime();
                break;
            }
        }
    
        if(!w->isIdle()){ //if the window is occupied . . .
            Customer* c = w->getCustomerAtWindow();

            if(c->getOfficeTime() == 0){ //customer is done at the window
                updatedCustomers.enqueue(c);
                w->removeCustomer(); //they are removed from the window
            }else{
                c->reduceTime(); //they are still at the window, so their time is rediced
            }
        }


        if(w->isIdle() && !customerQueue.isEmpty()){ //if the window is idle, and there is a customer in line 
            Customer* c = customerQueue.peek();
            w->attendCustomer(c);
            customerQueue.dequeue();
            break;
        }

        if(customerQueue.size() >= 1 && !w->isIdle()){ //tracks customer wait time
            incrementWaitTime();
            break;
        }

        if(w->getCustomersAttended() > numOfCustomers){ //tracks number of customers attended
            numOfCustomers = w->getCustomersAttended();
        }

        windowsAvailable.removeFront();
        windowsAvailable.insertBack(w); //allows access to all windows
    }

    return updatedCustomers;
}

void Office::addCustomerToLine(Customer* c){

    customerQueue.enqueue(c);
    for(int i = 0; i < windowsAvailable.getSize(); i++){
        Window* w = windowsAvailable.getFront();

        if(w->isIdle()){ //if the windle is available, the customer is attended
            w->attendCustomer(c);
            customerQueue.dequeue();
        }

        windowsAvailable.removeFront();
        windowsAvailable.insertBack(w);
    }
}

bool Office::isEmpty(){
    if(customerNum == 0){
        return true;
    }else{
        return false;
    }
}

void Office::getOfficeStats(){
    if (longestTime < 0){
        longestTime = 0;
    }
    //mean and longest data for the office
    float meanWaitTime = longestTime / static_cast<float>(numOfCustomers);

    std::cout << name << "'s" << " Office: " << std::endl;
    std::cout << "Mean student wait time: " << meanWaitTime << " tick(s)" << std::endl;
    std::cout << "Mean window idle time: " << (getLongestIdleTime()/windowsAvailable.getSize()) << " tick(s)" << std::endl;
    std::cout << "Longest student wait time: " << longestTime  << " tick(s)" << std::endl;
    std::cout << "Longest window idle time: " << getLongestIdleTime() << " tick(s)" << std::endl;
    std::cout << std::endl;
} 

int Office::getLongestIdleTime(){
    //iterates through every window to obtain the longest idle time
    int longestIdleTime = 0;

    for(int i = 0; i < windowsAvailable.getSize(); i++){
        Window* w = windowsAvailable.getFront();
        time = w->getLongestIdleTime();

        if(time > longestIdleTime){
            longestIdleTime = time;
        }

        windowsAvailable.removeFront();
        windowsAvailable.insertBack(w);
    }
    return longestIdleTime;

}

int Office::getWaitTimeOverTen(){
    return waitTimeOverTen;
}

int Office::getIdleWindowsOverFive(){
    //iterates through every window to see which were dile for 5+ minutes
    int numOfWindowsIdleOverFive = 0;

    for(int i = 0; i < windowsAvailable.getSize(); i++){
        Window* w = windowsAvailable.getFront();
        
        if(w->getLongestIdleTime() > 5){
            ++numOfWindowsIdleOverFive;
        }
    }
    return numOfWindowsIdleOverFive;
}

void Office::incrementWaitTime(){
    //incremenst the wait time of each customer in line
    for(int i = 0; i < customerQueue.size(); ++i){
        Customer* c = customerQueue.peek();
        c->addWaitTime();
        customerQueue.dequeue();
        customerQueue.enqueue(c);

        if(c->getWaitTime() > 10){ //if the customer has been waiting for 10+ minutes
            ++customerWaitingOverTen;
        }

        if(c->getWaitTime() > longestTime){ //keeps track of the longest wait time
            longestTime = c->getWaitTime();
        }
    }
}

int Office::getCustomersWaitingOverTen(){
    return customerWaitingOverTen;
}

