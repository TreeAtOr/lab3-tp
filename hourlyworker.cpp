#include "hourlyworker.h"

HourlyWorker::HourlyWorker(
        std::string name,
        std::string surname,
        std::string phone,
        std::string address,
        double      hour_salary
    ) : Worker(name,surname,phone,address){
        this->hour_salary = hour_salary;
}

double HourlyWorker::getSalary(double _){
    return hour_salary * _;
}