#include "worker.h"

Worker::Worker(
        std::string name,
        std::string surname,
        std::string phone,
        std::string address
    ){
        this->name = name;
        this->surname = surname;
        this->phone = phone;
        this->address = address;
}

Worker::~Worker(){};

void Worker::setAddress(std::string address){
    this->address = address;
}
void Worker::setPhone(std::string phone){
    this->phone = phone;
}
void Worker::setSalary(double _) { 
    
}
double Worker::getSalary(double _){ return _; }


std::string Worker::getAddress(){ return this->address; }
std::string Worker::getSurname(){ return this->surname; }
std::string Worker::getPhone(){ return this->phone;}
std::string Worker::getName() { return this->name; }