#ifndef SHAREWORKER_H
#define SHAREWORKER_H
#include "worker.h"

class ShareWorker final : public Worker
{
    double procentage;
public:
    ShareWorker(
        std::string name,
        std::string surname,
        std::string phone,
        std::string address,
        double      procentage
    );
    double getSalary(double _) override; 
};

#endif // FULLTIMEWORKER_H