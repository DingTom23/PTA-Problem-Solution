

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Group
{
public:
    virtual int add(int x, int y) = 0; // 输出加法的运算结果
    virtual int sub(int x, int y) = 0; // 输出减法的运算结果
    virtual ~Group() {}
};

// GroupA: 正确完成三位整数加减法
class GroupA : public Group
{
public:
    int add(int x, int y) override {
        return x + y;
    }
    
    int sub(int x, int y) override {
        return x - y;
    }
};

// GroupB: 正确完成加法，减法忘记借位
class GroupB : public Group
{
public:
    int add(int x, int y) override {
        return x + y;
    }
    
    int sub(int x, int y) override {
        // 减法忘记借位：每位单独计算，不够减时当作够减来算
        string sx = to_string(x);
        string sy = to_string(y);
        
        // 从右往左补齐到相同位数
        int maxLen = max(sx.length(), sy.length());
        while(sx.length() < maxLen) sx = "0" + sx;
        while(sy.length() < maxLen) sy = "0" + sy;
        
        string result = "";
        for(int i = 0; i < maxLen; i++) {
            int digit1 = sx[i] - '0';
            int digit2 = sy[i] - '0';
            
            if(digit1 >= digit2) {
                result += to_string(digit1 - digit2);
            } else {
                // 忘记借位，当作digit1+10来减
                result += to_string(digit1 + 10 - digit2);
            }
        }
        
        return stoi(result);
    }
};

// GroupC: 加法忘记进位，减法忘记借位
class GroupC : public Group
{
public:
    int add(int x, int y) override {
        // 加法忘记进位：逐位相加，超过9时只保留个位
        string sx = to_string(x);
        string sy = to_string(y);
        
        // 从右往左补齐到相同位数
        int maxLen = max(sx.length(), sy.length());
        while(sx.length() < maxLen) sx = "0" + sx;
        while(sy.length() < maxLen) sy = "0" + sy;
        
        string result = "";
        for(int i = 0; i < maxLen; i++) {
            int digit1 = sx[i] - '0';
            int digit2 = sy[i] - '0';
            int sum = digit1 + digit2;
            result += to_string(sum % 10); // 忘记进位，只保留个位
        }
        
        return stoi(result);
    }
    
    int sub(int x, int y) override {
        // 减法忘记借位：每位单独计算，不够减时当作够减来算
        string sx = to_string(x);
        string sy = to_string(y);
        
        // 从右往左补齐到相同位数
        int maxLen = max(sx.length(), sy.length());
        while(sx.length() < maxLen) sx = "0" + sx;
        while(sy.length() < maxLen) sy = "0" + sy;
        
        string result = "";
        for(int i = 0; i < maxLen; i++) {
            int digit1 = sx[i] - '0';
            int digit2 = sy[i] - '0';
            
            if(digit1 >= digit2) {
                result += to_string(digit1 - digit2);
            } else {
                // 忘记借位，当作digit1+10来减
                result += to_string(digit1 + 10 - digit2);
            }
        }
        
        return stoi(result);
    }
};

int main() {
    int n;
    cin >> n;
    
    Group* students[20];
    
    // 读取学生类别并创建对应对象
    for(int i = 0; i < n; i++) {
        int type;
        cin >> type;
        
        if(type == 1) {
            students[i] = new GroupA();
        } else if(type == 2) {
            students[i] = new GroupB();
        } else {
            students[i] = new GroupC();
        }
    }
    
    string line;
    getline(cin, line); // 读取换行符
    
    while(getline(cin, line)) {
        if(line[0] == '0') break;
        
        // 解析输入
        istringstream iss(line);
        string part;
        iss >> part; // 学生编号
        int studentId = stoi(part) - 1; // 转换为数组索引
        
        iss >> part; // 数学表达式
        
        // 解析表达式
        int opPos = -1;
        char op;
        for(int i = 0; i < part.length(); i++) {
            if(part[i] == '+' || part[i] == '-') {
                opPos = i;
                op = part[i];
                break;
            }
        }
        
        int x = stoi(part.substr(0, opPos));
        int y = stoi(part.substr(opPos + 1));
        
        int result;
        if(op == '+') {
            result = students[studentId]->add(x, y);
        } else {
            result = students[studentId]->sub(x, y);
        }
        
        cout << result << endl;
    }
    
    // 释放内存
    for(int i = 0; i < n; i++) {
        delete students[i];
    }
    
    return 0;
}

/*
2-1 2017Final进位与借位

凤湖小学二年级的陈老师吃惊地发现班上的同学竟然可以分成三类，一类总是可以正确地完成三位整数加减法(GroupA)；一类总是可以正确地完成三位整数的加法，但对于减法运算来说，总是忘记借位的处理(GroupB)；剩下的人总是忘记加法的进位，也总是忘记减法的借位(GroupC)。
现在请给出一次陈老师在课堂提问时，同学们会给出的回答。
实现时请基于下面的基类框架
class Group
{
public:
virtual int add(int x, int y)=0;//输出加法的运算结果
virtual int sub(int x, int y)=0;//输出减法的运算结果
}
构建出GroupA, GroupB和GroupC三个派出类:
并编写主函数，要求主函数中有一个基类Group指针数组，通过该数组元素统一地进行add和sub运算。
输入格式:
首先输入一个整数n，这是班级的人数, 不超过20。
接下来再输入n个数字(取值为1,2,或3)，它是各个学生所属的类别，
第一个数字是第一位学生的类别，接下来是第二位学生的类别，...,   
最后是第n位学生的类别。类别为1时，表明该学生是第A类；为2时，表明该生是B类，为3时表明是C类。
接下来每一行输入一个数学问题。数学问题由两部分构成，第一部分被提问学生的编号，
它是一个不超过n的正整数，1表示第一位学生，2表示第二位学生,n表示第n位学生；
 第二部分是具体的数学题，可能是加法，也可能是减法。注意：运算对象和加减号之间没有空格，
 两个运算对象均是不超过999的非负整数， 减法时，被减数不小于减数。
如果某一行以0开头，则说明提问结束。

输出格式:
输出指定学生对于给定的问题的回答。

输入样例:
4
1 2 3 3
1 79+81
2 81-79
4 183+69
0
输出样例:
160
12
142
*/