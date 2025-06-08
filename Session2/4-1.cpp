#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    Student(int _num, char _name, int _age, int _maths, int _english, int _chinese) {
        num = _num;
        name = _name;
        age = _age;
        maths = _maths;
        english = _english;
        chinese = _chinese;
        ave = (_maths + _english + _chinese) / 3.0;
    }
    
    int getNum() const { return num; }
    char getName() const { return name; }
    double getAve() const { return ave; }
    
private:
    int num;
    char name;
    int age;
    int maths;
    int english;
    int chinese;
    double ave;
};

void output(Student students[], int count) {
    ofstream outfile("STUD.DAT", ios::out);
    for (int i = 0; i < count; i++) {
        outfile << students[i].getNum() << " " 
                << students[i].getName() << " " 
                << students[i].getAve() << endl;
    }
    outfile.close();
}

void mprint() {
    ifstream infile("STUD.DAT", ios::in);
    int num;
    char name;
    double ave;
    
    while (infile >> num >> name >> ave) {
        cout << num << " " << name << " " << ave << endl;
    }
    infile.close();
}

int main() {
    Student stu1(1, 'A', 19, 80, 79, 67);
    Student stu2(2, 'B', 20, 90, 68, 43);
    Student stu3(3, 'C', 19, 56, 48, 29);
    Student stu4(4, 'D', 20, 93, 44, 57);
    Student stu5(5, 'E', 19, 33, 55, 74);
    
    Student students[5] = {stu1, stu2, stu3, stu4, stu5};
    
    output(students, 5);
    
    mprint();
    
    return 0;
}
