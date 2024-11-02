#ifndef ASSIST_H
#define ASSIST_H

#include <string>
#include "teacher.hpp"

class AssistProfessor : public Teacher {
private:
    double degreeBonus;
    double titleBonus;

public:
    AssistProfessor(string surname, string name, string patronymic, int departmentNumber,
        int yearOfEmployment, double baseSalary, double vacationPayment, double materialAid, double additionalPayment);

    double calculateGrossSalary() const override;
    void displaySalaryInfo() const override;
    void saveToFile(const string& filename) const override;
    static void searchByFullName(const string& fullName, const string& filename);
};

#endif