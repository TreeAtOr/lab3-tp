#ifndef FULLTIMEWORKER_H
#define FULLTIMEWORKER_H
#include "worker.h"

class FulltimeWorker final : public Worker
{
    double month_salary;
public:
    FulltimeWorker(
        std::string name,
        std::string surname,
        std::string phone,
        std::string address,
        double      month_salary
    );
    double getSalary(double _) override; 
};

#endif // FULLTIMEWORKER_H
