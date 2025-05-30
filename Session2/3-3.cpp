#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() const = 0;
    virtual void input() = 0;
    virtual ~Shape() {};
};

class Rectangle : public Shape {
    private:
        double length;
        double width;
    public:
        Rectangle(double length = 0.0, double width = 0.0) : length(length), width(width) {}
        double getArea() const override {
            return length * width;
        }
        void input() override {
            cout << "Enter length:";
            cin >> length;
            cout << "Enter width:"; 
            cin >> width;
        }
};

class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(double radius = 0.0) : radius(radius) {}
        double getArea() const override {
            return 3.14159 * radius * radius;
        }
        void input() override {
            cout << "Enter radius:";
            cin >> radius;
        }
};

class Triangle : public Shape {
    private:
        double base;
        double height;
    public:
        Triangle(double base = 0.0, double height = 0.0) : base(base), height(height) {}
        double getArea() const override {
            return 0.5 * base * height;
        }
        void input() override {
            cout << "Enter base:";
            cin >> base;
            cout << "Enter height:"; 
            cin >> height;
        }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Rectangle();
    shapes[1] = new Circle();
    shapes[2] = new Triangle();

    for (int i = 0; i < 3; ++i) {
        cout << "Input for Shape " << i + 1 << ":" << endl;
        shapes[i]->input();
    }

    for (int i = 0; i < 3; ++i) {
        cout << "Shape " << i + 1 << " Area: " << shapes[i]->getArea() << endl;
    }

    // 释放内存
    for (int i = 0; i < 3; ++i) {
        delete shapes[i];
    }

    return 0;
}


/*
 图形面积计算
基类 Shape 要求
数据成员：无。
成员函数：
**纯虚函数 double getArea() const**：用于计算图形面积，必须由派生类重写。
**纯虚函数 void input()**：用于输入图形的相关参数，必须由派生类重写。
虚析构函数：确保派生类的析构函数被调用。
派生类 Rectangle 要求
数据成员：
double length：矩形的长。
double width：矩形的宽。
成员函数：
构造函数：初始化矩形的长和宽。
重写 getArea 函数：计算矩形面积，公式为 length * width。
重写 input 函数：输入矩形的长和宽。
派生类 Circle 要求
数据成员：
double radius：圆的半径。
成员函数：
构造函数：初始化圆的半径。
重写 getArea 函数：计算圆面积，公式为 π * radius * radius。
重写 input 函数：输入圆的半径。
派生类 Triangle 要求
数据成员：
double base：三角形的底。
double height：三角形的高。
成员函数：
构造函数：初始化三角形的底和高。
重写 getArea 函数：计算三角形面积，公式为 0.5 * base * height。
重写 input 函数：输入三角形的底和高。
不需要实现main函数，通过实现以上类的定义，保证题目给出的main函数运行后能够实现要求的功能，产生指定的样例输出。
*/