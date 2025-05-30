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
/* 请在这里填写答案 */

/*
员工工资计算II
基类 Employee 要求
数据成员：
int id：员工编号。
成员函数：
构造函数：初始化员工编号。
**纯虚函数 double calculateSalary()**：用于计算员工工资，必须由派生类重写。
**纯虚函数 void input()**：用于输入员工的相关信息，必须由派生类重写。
虚析构函数：确保派生类的析构函数被调用。
派生类 Manager 要求
数据成员：
double baseSalary：基本工资。
double bonus：奖金。
成员函数：
构造函数：初始化经理的编号、基本工资和奖金。
重写 calculateSalary 函数：计算经理的工资，公式为 baseSalary + bonus。
重写 input 函数：输入经理的编号、基本工资和奖金。
派生类 Programmer 要求
数据成员：
double hourlyRate：小时工资。
double hoursWorked：工作小时数。
成员函数：
构造函数：初始化程序员的编号、小时工资和工作小时数。
重写 calculateSalary 函数：计算程序员的工资，公式为 hourlyRate * hoursWorked。
重写 input 函数：输入程序员的编号、小时工资和工作小时数。
派生类 Tester 要求
数据成员：
double baseSalary：基本工资。
double overtimePay：加班费。
成员函数：
构造函数：初始化测试员的编号、基本工资和加班费。
重写 calculateSalary 函数：计算测试员的工资，公式为 baseSalary + overtimePay。
重写 input 函数：输入测试员的编号、基本工资和加班费。
不需要实现main函数，通过实现以上类的定义，保证题目给出的main函数运行后能够实现要求的功能，产生指定的样例输出。
在这里给出相应的输出。例如：

Input for Employee 1:
Enter ID:
Enter base salary:
Enter bonus:
Input for Employee 2:
Enter ID:
Enter hourly rate:
Enter hours worked:
Input for Employee 3:
Enter ID:
Enter base salary:
Enter overtime pay:
Employee 5: - Salary:4200
Employee 6: - Salary:12000
Employee 9: - Salary:7700


*/