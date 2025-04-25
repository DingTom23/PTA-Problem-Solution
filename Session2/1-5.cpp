/*
本题目要求读入3个整数A、B和C，
然后按照下列要求完成相关设计：
1.定义一个基类A，在其中包含保护的数据成员int i，
设计类A的带参构造函数对i进行初始化，定义成员函数display（）显示i值； 
2.定义基类A的公有派生类A1，且A是A1的虚基类；
A1中包含保护的数据成员int j，设计类A1的构造函数；
 3.定义基类A的公有派生类A2，且A是A2的虚基类；
 A2中包含保护的数据成员int k，设计类A2的构造函数； 
 4.定义类A3，A3是A1和A2以多继承方式生成的公有派生类，设计类A3的构造函数；
 定义成员函数disp（）在其中调用display（）函数显示i值，另外输出j和k值； 
 5.在main（）中定义类A3的1个对象变量，通过输入的3个整数完成对象的创建；
 调用类A3的成员函数disp（）输出信息。
*/

#include <iostream>
using namespace std;

class A {
protected:
    int i;
public:
    A(int a) : i(a) {
        cout << "Call A:i=" << i << endl;
    }
    void display() {
        cout << "i=" << i << endl;
    }
};

class A1 : virtual public A {
protected:
    int j;
public:
    A1(int a, int b) : A(a), j(b) {
        cout << "Call A1:i=" << i << endl;
    }
};

class A2 : virtual public A {
protected:
    int k;
public:
    A2(int a, int c) : A(a), k(c) {
        cout << "Call A2:i=" << i << endl;
    }
};

class A3 : public A1, public A2 {
public:
    A3(int a, int b, int c) : A(a), A1(a, b), A2(a, c) {
        cout << "Call A3:i=" << i << endl;
    }
    void disp() {
        display();
        cout << "j=" << j << endl;
        cout << "k=" << k << endl;
    }
};

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    A3 obj(A, B, C);
    obj.disp();
    return 0;
}
