#include<iostream>
#include<cstring>
using namespace std;

class Stud {
private:
    int No;          // 学号
    char name[50];   // 姓名
    double score;    // 成绩
    static double sum; // 静态成员，用于累加所有学生的成绩
    static int num;    // 静态成员，用于记录学生人数

public:
    // 构造函数
    Stud(int no, const char* n, double s) {
        No = no;
        strcpy(name, n);
        score = s;
        sum += score; // 累加成绩
        num++;        // 增加学生人数
    }

    // 显示学生信息
    void disp() {
        cout << No << " " << name << " " << score << endl;
    }

    // 静态函数，计算平均分
    static double avg() {
        return sum / num;
    }
};

// 初始化静态成员
double Stud::sum = 0;
int Stud::num = 0;

int main() {
    int No, n;
    cin >> n;
    char name[50];
    double score;

    while (n--) {
        cin >> No;
        cin >> name;
        cin >> score;
        Stud stu(No, name, score); // 创建学生对象
        stu.disp();                // 显示学生信息
    }

    // 输出平均分，保留两位小数
    printf("avg=%.2lf\n", Stud::avg());
    return 0;
}