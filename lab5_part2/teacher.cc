#include "include/teacher.hpp"
#include "include/tax.hpp"
#include <string>
#include <iostream>
#include <fstream>


Teacher::Teacher(string surname, string name, string patronymic, int departmentNumber,
    int yearOfEmployment, double baseSalary, double vacationPayment, double materialAid, double additionalPayment)
    : surname(surname), name(name), patronymic(patronymic), departmentNumber(departmentNumber),
    yearOfEmployment(yearOfEmployment), baseSalary(baseSalary), vacationPayment(vacationPayment),
    materialAid(materialAid), additionalPayment(additionalPayment) {
    calculateSeniorityBonus();
}

void Teacher::calculateSeniorityBonus() {
    int yearsOfExperience = 2024 - yearOfEmployment;
    int category = (yearsOfExperience > 20) ? 3 : (yearsOfExperience > 10) ? 2 : (yearsOfExperience > 3) ? 1 : 0;

    switch (category) {
    case 3:
        seniorityBonus = baseSalary * 0.3;
        break;
    case 2:
        seniorityBonus = baseSalary * 0.2;
        break;
    case 1:
        seniorityBonus = baseSalary * 0.1;
        break;
    default:
        seniorityBonus = 0;
        break;
    }
}

double Teacher::calculateGrossSalary() const {
    return baseSalary + seniorityBonus + additionalPayment + materialAid + vacationPayment;
}

double Teacher::getNetSalary() const {
    Tax tax(calculateGrossSalary());
    return tax.calculateNetSalary();
}

void Teacher::saveToFile(const string& filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "Викладач: " << surname << " " << name << " " << patronymic << " "
            << departmentNumber << " " << yearOfEmployment << " "
            << baseSalary << " " << vacationPayment << " "
            << materialAid << " " << additionalPayment << " " << getNetSalary() << "\n";
        file.close();
    }
}

void Teacher::displaySalaryInfo() const {
    cout << "Розмір зарплати: " << getNetSalary() << " грн" << endl;
}

void Teacher::searchByFullName(const string& fullName, const string& filename){
    ifstream file(filename);
    string line;

    bool found = false;
    while (getline(file, line)) {
        if (line.find(fullName) != string::npos) {
            cout << "Знайдено викладача: " << line << endl;
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "Викладача не знайдено." << endl;
    }
}