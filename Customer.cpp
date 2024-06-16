
//models a student coming into the service center
#include "Customer.h"

Customer::Customer(){
    officeTime = 0; //sets office time to 0
}
Customer::~Customer(){}
Customer::Customer(std::string customerInfo){ 
    
    this->customerInfo = new std::string[6];
    std::stringstream customer(customerInfo);
    std::string individualInfo;
    int i = 0;

    while(customer >> individualInfo){ //places all the customer information into an array
        //std::cout << individualInfo;
        this->customerInfo[i] = individualInfo;
        ++i;
    }
    this->infoSize = i;
}

std::string Customer::accessOfficeInfo(){
    std::string officeInfo = "";

    if(nextInfoIndex < infoSize/2){ //accesses the customer information when its time to move onto the next office
        officeInfo += customerInfo[nextInfoIndex]; //sets the time
        officeInfo += customerInfo[nextInfoIndex + infoSize/2]; //sets the office

        officeTime = officeInfo[0] - '0';

        if(officeTime == 0){ //if the office time is zero
            ++nextInfoIndex;
        }else{
            nextOffice = officeInfo[1];
            ++nextInfoIndex;
            //std::cout << nextInfoIndex << std::endl;
        }

    }else{
        return "-1";
    }
    return officeInfo;
}

std::string Customer::getOffice(){
    return nextOffice;
}

int Customer::getOfficeTime(){
    return officeTime;
}

void Customer::reduceTime(){ 
    --officeTime;
    if(officeTime < 0){
        isBeingAttended = false;
    }
}

void Customer::occoupied(){
    if(officeTime >= 0 && isBeingAttended)
        reduceTime();
}

void Customer::setIsBeingAttended(bool x){
    isBeingAttended = x;
}

bool Customer::getIsBeingAttended(){
    return isBeingAttended;
}

int Customer::getCustomerNum(){
    return customerNum;
}

void Customer::addWaitTime(){
    ++waitTime;
}

int Customer::getWaitTime(){
    return waitTime;
}