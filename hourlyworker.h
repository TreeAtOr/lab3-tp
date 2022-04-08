#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H
#include "worker.h"

class HourlyWorker final : public Worker
{
    double hour_salary;
public:
    HourlyWorker(
        std::string name,
        std::string surname,
        std::string phone,
        std::string address,
        double      hour_salary
    );
    double getSalary(double _) override; 
};

#endif // HOURLYWORKER_H
