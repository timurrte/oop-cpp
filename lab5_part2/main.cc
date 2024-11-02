#include "include/teacher.hpp"
#include "include/assist.hpp"
#include "include/tax.hpp"
#include <iostream>
#include <vector>

int main() {
    vector<Teacher*> teachers;
    char chglobal;

    do {
        int choice;
        cout << "Оберіть дію:\n";
        cout << "1. Додати викладача\n";
        cout << "2. Додати доцента\n";
        cout << "3. Знайти викладача\n";
        cout << "4. Вихід\n";
        cout << "Введіть вибір: ";
        cin >> choice;

        if (choice == 4) {
            break;
        }
        
        if (choice == 3) {
                string fullName;
                cout << "Введіть повне ім'я: ";
                cin.ignore();
                getline(cin, fullName);
                Teacher::searchByFullName(fullName, "data.txt");
                continue;
        }

        string surname, name, patronymic;
        int departmentNumber, yearOfEmployment;
        double baseSalary, vacationPayment, materialAid, additionalPayment;

        cout << "Прізвище: ";
        cin >> surname;
        cout << "Ім'я: ";
        cin >> name;
        cout << "По батькові: ";
        cin >> patronymic;
        cout << "Номер департаменту: ";
        cin >> departmentNumber;
        cout << "Рік прийняття на роботу: ";
        cin >> yearOfEmployment;
        cout << "Базова зарплата: ";
        cin >> baseSalary;
        cout << "Оплата відпустки: ";
        cin >> vacationPayment;
        cout << "Матеріальна допомога: ";
        cin >> materialAid;
        cout << "Надбавка: ";
        cin >> additionalPayment;

        if (choice == 1) {
            teachers.push_back(new Teacher(surname, name, patronymic, departmentNumber,
                yearOfEmployment, baseSalary, vacationPayment,
                materialAid, additionalPayment));
        }
        else if (choice == 2) {
            teachers.push_back(new AssistProfessor(surname, name, patronymic, departmentNumber,
                yearOfEmployment, baseSalary, vacationPayment,
                materialAid, additionalPayment));
        }
        else {
            cout << "Неправильний вибір.\n";
            break;
        }

        teachers.back()->displaySalaryInfo(); 
        teachers.back()->saveToFile("data.txt"); 

        cout << "Продовжити? (y/n): ";
        cin >> chglobal;
    } while (chglobal == 'y' || chglobal == 'Y');

    for (const auto& teacher : teachers) {
        delete teacher;
    }

    return 0;
}