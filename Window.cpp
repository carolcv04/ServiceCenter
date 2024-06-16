#include "Window.h"
//models a single window in one of the offices

Window::Window(){
    isOccupied = false;
}

Window::~Window(){}

bool Window::isIdle(){
    if(isOccupied)
        return false;
    return true;

}

void Window::attendCustomer(Customer* c){
    if(isIdle()){ //if a window is available
        customerAtWindow.enqueue(c);
        setOccupied(true);
        ++customersAttended;
        idleTime = 0;
    }
}

void Window::setOccupied(bool occ){
    isOccupied = occ;
}

Customer* Window::getCustomerAtWindow(){
    return customerAtWindow.peek();
}

bool Window::getIsOccupied(){
    return isOccupied;
}

void Window::removeCustomer(){
    setOccupied(false);
    customerAtWindow.dequeue();
}

void Window::incrementIdleTime(){
    if (!isOccupied){  //if a window is not occupied, idle time is increased
        ++idleTime;
    }
    totalIdleTime += idleTime;
    if(totalIdleTime > 5){
        idleForMoreThanFive = true;
    }
    idleTime = 0;
}

int Window::getIdleTime(){
    return idleTime;
}

int Window::getLongestIdleTime(){
    return totalIdleTime;
}

int Window::getCustomersAttended(){
    return customersAttended;
}

bool Window::getIdleForMoreThanFive(){
    return idleForMoreThanFive;
}
