
#include "ServiceCenter.h"

//models the service center
ServiceCenter::ServiceCenter(){}

ServiceCenter::ServiceCenter(std::string inputFile){ //takes in an input file
    bool serviceIsOpen = true;
    std::ifstream file;
    std::string fileLine;

    file.open(inputFile);

    if(file.fail()){
        std::cout << "File could not be opened" << std::endl;
    }else{
        while(std::getline(file,fileLine)){ //sets all the values and information onto an queue
            fileValues.enqueue(fileLine);
        }
        file.close();
    }

    cashierOffice = new Office("Cashier", stringToInt(fileValues.peek())); //sets window information for cashier
    fileValues.dequeue();

    registrarOffice = new Office("Registrar", stringToInt(fileValues.peek())); //sets window information for registrar
    fileValues.dequeue();

    finacialOffice = new Office("Financial Aid", stringToInt(fileValues.peek())); //sets window information for finacial aid
    fileValues.dequeue();

    arrivalTime = stringToInt(fileValues.peek());
    fileValues.dequeue();

    while(serviceIsOpen){
        //updates all office & customers within
        updateOffice(cashierOffice);
        updateOffice(finacialOffice);
        updateOffice(registrarOffice);

        if(clockTime == arrivalTime){ //at arrival time, customers are set
            newCustomerAmount = stringToInt(fileValues.peek());
            fileValues.dequeue();

            for (int i = 0; i < newCustomerAmount; i++){ //sets up new customer information
                Customer* c = new Customer(fileValues.peek());
                newCustomers.enqueue(c);
                fileValues.dequeue();
                ++totalCustomers;
            }

            for(int i = 0; i < newCustomerAmount; i++){ //acceses customers first office
                Customer* c = newCustomers.peek();
                c->accessOfficeInfo();
                addCustomerToLine(c);
                newCustomers.dequeue();
            }

            if(!fileValues.isEmpty()){ //sets the arrival time for the next customers
                arrivalTime = stringToInt(fileValues.peek());
                fileValues.dequeue();
            }
        }
        clockTick(); 

        if(totalCustomers == finishedCustomers.size()){ //once all the customers are finished, service center is closed 
            serviceIsOpen = false;
            officeResults();
        }

    }
}

ServiceCenter::~ServiceCenter(){

}

int ServiceCenter::stringToInt(std::string string){
    int x = stoi(string);
    return x;
}

void ServiceCenter::clockTick(){
    ++clockTime;
}

void ServiceCenter::addCustomerToLine(Customer* c){

    //places customers in their respective office line
    if (c->getOffice() == "R"){
        registrarOffice->addCustomerToLine(c);
    }else if(c->getOffice() == "F"){
        finacialOffice->addCustomerToLine(c);
    }else if(c->getOffice() == "C"){
        cashierOffice->addCustomerToLine(c);
    }
}

void ServiceCenter::updateOffice(Office* pOffice){
    ListQueue<Customer*> currCustomers = pOffice->updateCustomersInOffice();
    //upates the customer information

    for(int i = 0; i < currCustomers.size(); ++i){
        Customer* c = currCustomers.peek();
        std::string output = c->accessOfficeInfo();

        std::string out;
        out = output[0];

        //if a customer wants to soend 0 time at a office, it will loop until it finds an office the customer wishes to visit or until they are finished
        while(out == "0" && output != "-1"){
            output = c->accessOfficeInfo();
            out = output[0];
        }

        if(output == "-1"){ //customer is done
            finishedCustomers.enqueue(c);
        }else{
            addCustomerToLine(c);
        }

        currCustomers.dequeue();
        currCustomers.enqueue(c); //allows to access all other customers
    }
}

void ServiceCenter::officeResults(){
    //prints all the office mean and longest information
    cashierOffice->getOfficeStats();
    finacialOffice->getOfficeStats();
    registrarOffice->getOfficeStats();

    //cumulative information across all offices.
    std::cout << "Number of students waiting over 10 minutes across all office: " << cashierOffice->getCustomersWaitingOverTen() + 
    registrarOffice->getCustomersWaitingOverTen() + finacialOffice->getCustomersWaitingOverTen() << " tick(s)" << std::endl;
    std::cout << "Number of windows idle for over 5 minutes across all offices: " << cashierOffice->getIdleWindowsOverFive() + 
    registrarOffice->getIdleWindowsOverFive() + finacialOffice->getIdleWindowsOverFive() << " tick(s)" << std::endl;
}