#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// 请在此处实现Person、Teacher、Student和GraduateStudent类

class Person {
    private:
        string idNumber;    // 身份证号，私有成员
    protected:
        string name;       // 姓名，保护成员
    public:
        int age;          // 年龄，公开成员
    
        Person(string id, string n, int a) : idNumber(id), name(n), age(a) {}
        
        void displayBasicInfo() {
            cout << "姓名：" << name << "，年龄：" << age << endl;
        }
};

class Teacher : public Person{
    public:
        Teacher(string id, string n, int a, string employeeId, string department)
        : Person(id, n, a), employeeId(employeeId), department(department){}

        void displayTeacherInfo(){
            Person::displayBasicInfo();
            cout << "教职工号：" <<  employeeId << "，院系：" << department << endl;
        }
    private:
        string employeeId;
    protected:
        string department;
};

class Student : protected Person {
    public:
        Student(string id, string n, int a, string sid)
        : Person(id, n, a), studentId(sid) {}

        void displayStudentInfo() {
            Person::displayBasicInfo();
            cout << "学号：" << studentId << endl;
        }
    private:
        string studentId;
};

class GraduateStudent : private Student{
    public:
        GraduateStudent(string id, string n, int a, string studentId , string rtc)
        : Student(id, n, a, studentId), researchTopic(rtc){};
        void displayGraduateInfo(){
            Student::displayStudentInfo();
            cout << "研究课题：" << researchTopic << endl;
        }
    private:
        string researchTopic;
};

int main() {
    // 创建教师对象
    Teacher t("110101199001011234", "张老师", 35, "T001", "计算机学院");
    
    // 创建学生对象
    Student s("110101200201011235", "李同学", 20, "S2021001");
    
    // 创建研究生对象
    GraduateStudent g("110101199901011236", "王同学", 24, "S2019001", "人工智能");
    
    // 测试1：教师信息访问
    t.displayTeacherInfo();
    // t.name = "张教授";  // 这行应该报错，为什么？
    
    // 测试2：学生信息访问
    s.displayStudentInfo();
    // s.age = 21;  // 这行应该报错，为什么？
    
    // 测试3：研究生信息访问
    g.displayGraduateInfo();
    // g.displayStudentInfo();  // 这行应该报错，为什么？
    
    return 0;
}