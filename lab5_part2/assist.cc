#include "include/assist.hpp"
#include "include/teacher.hpp"
#include "include/tax.hpp"
#include <string>
#include <print>
#include <iostream>
#include <fstream>

AssistProfessor::AssistProfessor(string surname, string name, string patronymic, int departmentNumber,
    int yearOfEmployment, double baseSalary, double vacationPayment, double materialAid, double additionalPayment)
    : Teacher(surname, name, patronymic, departmentNumber, yearOfEmployment, baseSalary, vacationPayment, materialAid, additionalPayment) {
    degreeBonus = baseSalary * 0.15;
    titleBonus = baseSalary * 0.25;
}

double AssistProfessor::calculateGrossSalary() const {
    return Teacher::calculateGrossSalary() + degreeBonus + titleBonus;
}

void AssistProfessor::displaySalaryInfo() const {
    std::print("Зарплата доцента: {} грн\n", getNetSalary());
}

void AssistProfessor::saveToFile(const string& filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "Доцент: " << surname << " " << name << " " << patronymic << " "
            << departmentNumber << " " << yearOfEmployment << " "
            << baseSalary << " " << vacationPayment << " "
            << materialAid << " " << additionalPayment << " " << getNetSalary() << "\n";
        file.close();
    }
}

void AssistProfessor::searchByFullName(const string& fullName, const string& filename) {
    ifstream file(filename);
    string line;

    bool found = false;
    while (getline(file, line)) {
        if (line.find(fullName) != string::npos) {
            print("Знайдено доцента: {}\n", line);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Доцента не знайдено." << endl;
    }
}