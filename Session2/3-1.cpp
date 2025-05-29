/*
定义一个 Shape 基类：
包含虚函数 double getArea()，用于计算图形面积，返回 0.0 作为默认值。
包含虚函数 void input()，用于输入图形的相关参数。
定义一个派生类 Rectangle：
继承自 Shape 类。
重写 getArea 函数，计算矩形面积。
重写 input 函数，输入矩形的长和宽。
包含私有成员变量 length 和 width，表示矩形的长和宽。
不需要实现main函数，但是要求以上类代码应使得如下main函数功能正常执行：
创建基类指针，指向派生类对象。
指针调用 input 函数，输入矩形的长和宽。
指针调用 getArea 函数，输出矩形面积。
验证虚函数的多态性。
*/
#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() {
        return 0.0;
    }
    virtual void input() {
        
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    void input() {
        cin >> length;
        cin >> width;
    }

    double getArea() {
        return length * width;
    }
};


int main() {
    Shape* shape = new Rectangle();

    shape->input(); // 输入矩形的长和宽
    //cout << "Area: " << shape->getArea() << endl; // 输出矩形面积
    cout << shape->getArea() << endl; // 输出矩形面积

    delete shape;
    return 0;
}

