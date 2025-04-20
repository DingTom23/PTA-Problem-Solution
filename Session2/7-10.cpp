/*
设计一个类，主函数中建立一个对象数组，
输入5个学生数据（学号、成绩），
用对象指针指向数组首元素，输出5个学生的数据。

输入格式:
输入5个学生数据（学号、成绩），
学号为不超过10000的正整数，成绩为0-100的正整数。

输出格式:
按顺序输出学生的学号和成绩，每行显示一个学生的信息。

输入样例:
在这里给出一组输入。例如：

101 90
102 80
103 70
104 60
105 50
输出样例:
在这里给出相应的输出。例如：

101 90
102 80
103 70
104 60
105 50
*/

#include <iostream>
using namespace std;

class Student
{
    public:
        Student(int n, int s)
        {
            num = n;
            score = s;
        }
        void disp()
        {
            cout << num << " " << score << endl;
        }
    private:
        int num, score;
};

int main()
{
    Student *p[5];
    for (int i = 0; i < 5; i++)
    {
        int n, s;
        cin >> n >> s;
        p[i] = new Student(n, s);
    }
    for (int i = 0; i < 5; i++)
    {
        p[i]->disp();
    }
    return 0;
}