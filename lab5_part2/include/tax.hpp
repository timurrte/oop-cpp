#ifndef TAX_H
#define TAX_H

class Tax {
private:
    double salary;

public:
    Tax(double salaryAmount);
    double calculateESV() const;
    double calculateIncomeTax() const;
    double calculateTotalDeductions() const;
    double calculateNetSalary() const;
};

#endif