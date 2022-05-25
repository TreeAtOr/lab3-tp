#include "fulltimeworker.h"
#include "hourlyworker.h"
#include "shareworker.h"
#include "worker.h"
#include <cstdio>
#include <fstream>
#include <iostream>

#include <cstdlib>
#include <cstring>
#include <string>

#include <string>

using namespace std;

Worker **workers;
int w_size = 0;

void addWorker(string type) {
  std::string name;
  std::string surname;
  std::string phone;
  std::string address;

  double d;
  try {

    std::cout << "Enter <name> <surname> <phone> <address> <salary>"
              << std::endl;
    std::cin >> name >> surname >> phone >> address >> d;
    Worker *tmp;

    if (type == "worker")
      tmp = new Worker(name, surname, phone, address);
    else if (type == "fulltime")
      tmp = new FulltimeWorker(name, surname, phone, address, d);
    else if (type == "hourly")
      tmp = new HourlyWorker(name, surname, phone, address, d);
    else if (type == "share")
      tmp = new ShareWorker(name, surname, phone, address, d);
    else
      throw std::runtime_error("Incorrect type");

    if (w_size == 0) {
      workers = (Worker **)calloc(1, sizeof(Worker *));
      w_size += 1;
      workers[0] = tmp;
    } else {
      workers = (Worker **)realloc(workers, ++w_size * sizeof(Worker *));
      workers[w_size - 1] = tmp;
    }
  } catch (const std::exception e) {
    std::cout << e.what() << std::endl;
  }
};
void modifiyWorker(int index, std::string object) {
  if (index >= w_size) {
    std::cout << "Enter correct index";
    return;
  }

  std::string tmp;
  double d;
  try {
    if (object == "phone") {
      std::cout << "Enter phone number" << std::endl;
      std::cin >> tmp;
      workers[index]->setPhone(tmp);
    } else if (object == "addres") {
      std::cout << "Enter address" << std::endl;
      std::cin >> tmp;
      workers[index]->setAddress(tmp);
    } else if (object == "salary") {
      std::cout << "Enter salary" << std::endl;
      std::cin >> d;
      workers[index]->setSalary(d);
    } else
      return;
  } catch (std::exception e) {
    std::cout << e.what() << std::endl;
  }
};

void deleteWorker(int index) {
  if (index >= w_size) {
    std::cout << "Enter correct index" << std::endl;
    return;
  }
  delete workers[index];
  std::memcpy(workers + index, workers + index + 1, w_size - index);
  workers = (Worker **)realloc(workers, --w_size);
};

void printWorkers() {
  for (int i = 0; i < w_size; ++i) {
    std::cout << workers[i]->getName() << " " << workers[i]->getSurname() << " "
              << workers[i]->getAddress() << " " << workers[i]->getPhone()
              << " " << workers[i]->getSalary() << std::endl;
  }
};

void saveWorkers(std::string filename) {
  auto fout = std::ofstream(filename);
  fout << w_size << endl;
  for (int i = 0; i < w_size; ++i) {
    if (typeid(*workers[i]) == typeid(FulltimeWorker))
      fout << "fulltime ";
    if (typeid(*workers[i]) == typeid(ShareWorker))
      fout << "share ";
    if (typeid(*workers[i]) == typeid(HourlyWorker))
      fout << "hourly ";
    if (typeid(*workers[i]) == typeid(Worker))
      fout << "worker ";
    fout << workers[i]->getName() << " " << workers[i]->getSurname() << " "
         << workers[i]->getAddress() << " " << workers[i]->getPhone() << " "
         << workers[i]->getSalary() << std::endl;
  }
}

void loadWorkers(std::string filename) {
  auto fin = std::ifstream(filename);
  std::string type;
  std::string name;
  std::string surname;
  std::string phone;
  std::string address;

  double d;
  fin >> w_size;
  if (workers) {
    free(workers);
  }
  workers = (Worker **)calloc(w_size, sizeof(Worker *));

  for (int i = 0; i < w_size; ++i) {
    fin >> type >> name >> surname >> phone >> address >> d;
    Worker *tmp;
    if (type == "worker")
      tmp = new Worker(name, surname, phone, address);
    else if (type == "fulltime")
      tmp = new FulltimeWorker(name, surname, phone, address, d);
    else if (type == "hourly")
      tmp = new HourlyWorker(name, surname, phone, address, d);
    else if (type == "share")
      tmp = new ShareWorker(name, surname, phone, address, d);

    workers[i] = tmp;
  }
}

double calcSalary(int workerNumber, double amount) {
  if (workerNumber >= w_size) {
    std::cout << "Enter correct index" << std::endl;
    return -1;
  }
  Worker *worker = workers[workerNumber];
  if (typeid(worker) == typeid(ShareWorker))
    return worker->getSalary(amount) / 100;
  return worker->getSalary(amount);
}

int main() {
  std::cin.exceptions(std::iostream::failbit | std::iostream::badbit);

  std::cout << "Note: All values must be provided without spaces." << std::endl;

  std::string tmp;
  while (true) {
    try {
      std::cout << std::endl << "Enter command" << std::endl << "> ";
      std::cin >> tmp;
      if (tmp == "add") {
        std::cout << "Enter worker type ( worker/fulltime/hourly/share )"
                  << std::endl;
        std::cin >> tmp;
        addWorker(tmp);
        continue;
      }
      if (tmp == "mod") {
        double d;
        std::cout << "Enter worker index" << std::endl;
        std::cin >> d;
        std::cout << "Enter field name ( phone/address/salary )" << std::endl;
        std::cin >> tmp;
        modifiyWorker(d, tmp);
        continue;
      }
      if (tmp == "prt") {
        printWorkers();
        continue;
      }
      if (tmp == "sav") {
        saveWorkers("workers.txt");
        continue;
      }
      if (tmp == "lod") {
        loadWorkers("workers.txt");
        continue;
      }
      if (tmp == "del") {
        double d;
        std::cout << "Enter worker index" << std::endl;
        std::cin >> d;
        deleteWorker(d);
        continue;
      }
      if (tmp == "clc") {
        int d;
        std::cout << "Enter worker index" << std::endl;
        std::cin >> d;
        double amount;
        std::cout << "Enter amount" << std::endl;
        std::cin >> amount;
        std::cout << "Calculated salary: " << calcSalary(d, amount)
                  << std::endl;
        continue;
        
      }
      if (tmp == "q")
        return 0;
      std::cout << "Incorrect command" << std::endl
                << "add - to add worker" << std::endl
                << "mod - to modify worker" << std::endl
                << "del - to delete worker" << std::endl
                << "lod - to load workers" << std::endl
                << "sav - to save workers" << std::endl
                << "clc - to calculate salary" <<  std::endl
                << "q - to quit" << std::endl
                << "prt - to print" << std::endl;
    } catch (std::exception e) {
      std::cout << e.what() << std::endl;
    }
  }

  return 0;
}
