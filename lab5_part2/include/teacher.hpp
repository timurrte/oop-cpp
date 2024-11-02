#ifndef TEACHER_H
#define TEACHER_H

#include <string>
using namespace std;

class Teacher {
protected:
    string surname, name, patronymic;
    unsigned int departmentNumber, yearOfEmployment;
    double baseSalary, seniorityBonus, vacationPayment, materialAid, additionalPayment;

public:
    Teacher(string surname, string name, string patronymic, int departmentNumber,
        int yearOfEmployment, double baseSalary, double vacationPayment, double materialAid, double additionalPayment);
    virtual ~Teacher() = default;

    void calculateSeniorityBonus();
    virtual double calculateGrossSalary() const;
    double getNetSalary() const;

    virtual void saveToFile(const string& filename) const;
    virtual void displaySalaryInfo() const;
    static void searchByFullName(const string& fullName, const string& filename);
};


#endif 
