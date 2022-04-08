#include "fulltimeworker.h"

FulltimeWorker::FulltimeWorker(
        std::string name,
        std::string surname,
        std::string phone,
        std::string address,
        double      month_salary
    ) : Worker(name,surname,phone,address){
        this->month_salary = month_salary;
}
double FulltimeWorker::getSalary(double _){
    return this->month_salary * _;
}