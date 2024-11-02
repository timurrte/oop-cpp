#include "include/tax.hpp"
#include "include/teacher.hpp"

Tax::Tax(double salaryAmount) : salary(salaryAmount) {}

double Tax::calculateESV() const {
    return salary * 0.061;
}

double Tax::calculateIncomeTax() const {
    double afterESV = salary - calculateESV();
    return afterESV * 0.15;
}

double Tax::calculateTotalDeductions() const {
    return calculateESV() + calculateIncomeTax();
}

double Tax::calculateNetSalary() const {
    return salary - calculateTotalDeductions();
}