/*
编程构建一个Student类，
并在main函数中创建5个对象（对象信息如输入样例所示），
其中每个对象的数据
包括学号num、姓名name、年龄age以及数学maths、英语english、语文chinese三门功课的分数，
然后求出每个人的平均分数ave，将学号、姓名和平均分数输出到磁盘文件STUD.DAT中，
最后从STUD.DAT文件中读出这些数据，并显示在屏幕上。
*/
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
