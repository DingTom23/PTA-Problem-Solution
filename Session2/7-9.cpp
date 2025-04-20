/*
类中的常对象选择调用常成员函数。语法要点: 如果将一个对象说明为常对象，则通过该常对象只能调用它的常成员函数,而不能调用其他成员函数。补充完整复数类的定义（复数类Complex,数据成员：构造函数，以常成员函数重载的输出函数。数据成员有实部与虚部）使得程序的输出结果符合题意的输出结果。
class Complex
{
    public:
        /补充完整类的定义/
    private:
        int Real,Imag;
};
int main()
{   
    Complex a(2,3);
    a.disp();            //调用void disp()
    const Complex b(10,20);
    b.disp();  //调用void disp() const
    return 0;
}

输入格式:
读入两行，第一行读入两个整数，表示复数a的实部与虚部，第二行读入两个整数，表示复数b的实部与虚部。

输出格式:
输出两行不同格式表示的复数形式。

输入样例:
在这里给出一组输入。例如：

1 2
10 20
输出样例:
在这里给出相应的输出。例如：

(1,2i)
[10,20j]
*/

#include <iostream>
using namespace std;

class Complex
{
    public:
        Complex(int r, int i){
            Real = r;
            Imag = i;
        }
        void disp()
        {
            cout << "(" << Real << "," << Imag << "i)" << endl;
        }
        void disp() const
        {
            cout << "[" << Real << "," << Imag << "j]" << endl;
        }
    private:
        int Real, Imag;
};

int main()
{

    int a, b;
    cin >> a >> b;
    Complex A(a, b);
    A.disp();
    int c, d;
    cin >> c >> d;
    const Complex B(c,d);
    B.disp();
    return 0;
}