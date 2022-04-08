#include "shareworker.h"

ShareWorker::ShareWorker(
        std::string name,
        std::string surname,
        std::string phone,
        std::string address,
        double      procentage
    ) : Worker(name,surname,phone,address){
        this->procentage = procentage;
}
double ShareWorker::getSalary(double _){
    return this->procentage * _;
}