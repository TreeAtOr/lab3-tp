#ifndef WORKER_H
#define WORKER_H
/*
Создать базовый класс «Работник» и производные классы «Слу-
жащий с почасовой оплатой», «Служащий в штате» и «Служащий
с процентной ставкой». Базовый класс определяет для каждого ра-
ботника наличие имени, фамилии, телефона, адреса. Определить
функцию начисления зарплаты.
*/
#include <string>
class Worker
{
    std::string name;
    std::string surname;
    std::string phone;
    std::string address;

    static int count;

public:
    explicit Worker(
        std::string name,
        std::string surname,
        std::string phone,
        std::string address
    );
    ~Worker();

    virtual double getSalary(double _ = 1);
    virtual void setSalary(double _);

    std::string getName();
    std::string getSurname();
    std::string getPhone();
    std::string getAddress();

    void setPhone(std::string);
    void setAddress(std::string);
};

#endif // WORKER_H
