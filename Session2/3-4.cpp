#include <iostream>
using namespace std;

class Employee
{
public:
    int id;
    Employee(int mid=0) : id(mid){};
    virtual double calculateSalary() const = 0;
    virtual void input() = 0;
    virtual ~Employee() {}
};

class Manager : public Employee
{
private:
    double baseSalary;
    double bonus;
public:
    Manager() : Employee(0), baseSalary(0), bonus(0){};
    double calculateSalary() const override{
        return baseSalary + bonus;
    }
    void input() override {
        cout << "Enter ID:" << endl;
        cin >> id;
        cout << "Enter base salary:" << endl;
        cin >> baseSalary;
        cout << "Enter bonus:" << endl;
        cin >> bonus;
    }
};

class Programmer : public Employee
{
private:
    double hourlyRate;
    double hoursWorked;
public:
    Programmer() : Employee(0), hourlyRate(0), hoursWorked(0){};
    double calculateSalary() const override{
        return hourlyRate * hoursWorked;
    }
    void input() override {
        cout << "Enter ID:" << endl;
        cin >> id;
        cout << "Enter hourly rate:" << endl;
        cin >> hourlyRate;
        cout << "Enter hours worked:" << endl;
        cin >> hoursWorked;
    }

};

class Tester : public Employee
{
private:
    double baseSalary;
    double overtimePay;
public:
    Tester() : Employee(0), baseSalary(0), overtimePay(0){};
    double calculateSalary() const override{
        return baseSalary + overtimePay;
    }
    void input() override {
        cout << "Enter ID:" << endl;
        cin >> id;
        cout << "Enter base salary:" << endl;
        cin >> baseSalary;
        cout << "Enter overtime pay:" << endl;
        cin >> overtimePay;
    }
};


int main() {
    Employee* employees[3];
    employees[0] = new Manager();
    employees[1] = new Programmer();
    employees[2] = new Tester();

    for (int i = 0; i < 3; ++i) {
        cout << "Input for Employee " << i + 1 << ":" << endl;
        employees[i]->input();
    }

    for (int i = 0; i < 3; ++i) {
        cout << "Employee " << employees[i]->id << ":"<< " - Salary: " << employees[i]->calculateSalary() << endl;
    }

    // 释放内存
    for (int i = 0; i < 3; ++i) {
        delete employees[i];
    }

    return 0;
}
