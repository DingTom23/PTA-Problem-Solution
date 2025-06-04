#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {
        cout << "构造Person: " << name << endl;
    }
    virtual ~Person() {
        cout << "析构Person: " << name << endl;
    }
    virtual void show() {
        cout << "姓名: " << name << ", 年龄: " << age;
    }
};

class Teacher : public Person {
    string subject;
public:
    Teacher(string name, int age, string subject)
        : Person(name, age), subject(subject) {
        cout << "构造Teacher: " << name << endl;
    }
    
    void show() override{
        Person::show();
        cout << ", 科目: " << subject << endl;
    }
    
    ~Teacher() {
        cout << "析构Teacher: " << name << endl;
    }
};

class Student : public Person {
    int grade;
public:
    Student(string name, int age, int g)
        : Person(name, age), grade(g) {
        cout << "构造Student: " << name << endl;
    }
    
    void show() override {
        Person::show();
        cout << ", 年级: " << grade << endl;
    }
    
    ~Student() {
        cout << "析构Student: " << name << endl;
    }
};

int main() {
    string name, subject;
    int age, grade;
    
    cin >> name >> age >> subject;
    Teacher t(name, age, subject);
    
    cin >> name >> age >> grade;
    Student s(name, age, grade);
    
    t.show();
    s.show();
    
    return 0;
}
