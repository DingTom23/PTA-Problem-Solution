#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    int id;
    
    Employee(string name = "", int id = 0) : name(name), id(id) {}
    
    virtual double calculateSalary() { return 0.0; }
    virtual void input() { cin >> id; }
    virtual ~Employee() {}
    
protected:
    string name;
};

class Manager : public Employee {
private:
    double baseSalary;
    double bonus;
public:
    Manager(string name = "", int id = 0, double baseSalary = 0.0, double bonus = 0.0)
        : Employee(name, id), baseSalary(baseSalary), bonus(bonus) {}
    
    double calculateSalary() override {
        return baseSalary + bonus;
    }
    
    void input() override { // override 用于显式地表明一个成员函数是覆盖（override）基类中的虚函数
        Employee::input();
        cin >> baseSalary >> bonus;
    }
};

int main() {
    Employee* employee = new Manager();

    employee->input();
    cout << employee->id << ":" << employee->calculateSalary() << endl;

    delete employee;
    return 0;
}

/*
基类 Employee 要求
数据成员：
int id：员工编号。
成员函数：
构造函数：初始化员工姓名和编号。
虚函数 double calculateSalary()：计算员工工资，返回 0.0 作为默认值。
虚函数 void input()：输入员工姓名和编号。
虚析构函数：确保派生类析构函数被调用。
派生类 Manager 要求
数据成员：
double baseSalary：基本工资。
double bonus：奖金。
成员函数：
构造函数：初始化经理的姓名、编号、基本工资和奖金。
重写虚函数 calculateSalary()：计算经理的工资，计算方法为基本工资加上奖金。
重写虚函数 input()：输入经理的姓名、编号、基本工资和奖金。
不需要实现main函数，但是要求以上类代码应使得如下main函数功能正常执行：
创建基类指针，指向派生类对象。
调用 input 函数，输入经理的基本工资和奖金。
调用 calculateSalary 函数，输出经理的工资。
展示虚函数的多态性。
*/