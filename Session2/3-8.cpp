#include <iostream>
#include <string>
using namespace std;

// 抽象基类 Shape
class Shape {
public:
    virtual void draw() = 0;         // 纯虚函数，用于绘制图形
    virtual void inputInfo() = 0;    // 纯虚函数，用于输入图形相关信息
    virtual ~Shape() {}              // 虚析构函数
};

// 颜色类 Color
class Color {
protected:
    string colorName;  // 颜色名称
public:
    Color(string color) : colorName(color) {}  // 构造函数初始化颜色
    string getColor() const { return colorName; }  // 获取颜色名称
};

// 多继承类 ColoredShape，继承自Shape和Color
class ColoredShape : public Shape, public Color {
public:
    ColoredShape(string color) : Color(color) {}  // 构造函数
    virtual ~ColoredShape() {}  // 虚析构函数
    
    // 输入颜色信息
    void inputInfo() override {
        cout << "Enter color: ";
        cin >> colorName;
    }
    
    // 绘制彩色图形，输出颜色信息
    void draw() override {
        cout << "Color: " << colorName << endl;
    }
};

// 矩形类，继承自ColoredShape
class Rectangle : public ColoredShape {
private:
    double width;   // 宽度
    double height;  // 高度
public:
    Rectangle(string color) : ColoredShape(color) {}  // 构造函数
    
    // 输入矩形信息
    void inputInfo() override {
        cout << "Enter rectangle width:" << endl;
        cin >> width;
        cout << "Enter rectangle height:" << endl;
        cin >> height;
    }
    
    // 绘制矩形
    void draw() override {
        cout << "Drawing Rectangle with width " << width 
             << ", height " << height 
             << " and color " << getColor() << endl;
    }
};

// 圆形类，继承自ColoredShape
class Circle : public ColoredShape {
private:
    double radius;  // 半径
public:
    Circle(string color) : ColoredShape(color) {}  // 构造函数
    
    // 输入圆形信息
    void inputInfo() override {
        cout << "Enter circle radius:" << endl;
        cin >> radius;
    }
    
    // 绘制圆形
    void draw() override {
        cout << "Drawing Circle with radius " << radius 
             << " and color " << getColor() << endl;
    }
};

// 三角形类，继承自ColoredShape
class Triangle : public ColoredShape {
private:
    double side1, side2, side3;  // 三边长度
public:
    Triangle(string color) : ColoredShape(color) {}  // 构造函数
    
    // 输入三角形信息
    void inputInfo() override {
        cout << "Enter triangle side 1:" << endl;
        cin >> side1;
        cout << "Enter triangle side 2:" << endl;
        cin >> side2;
        cout << "Enter triangle side 3:" << endl;
        cin >> side3;
    }
    
    // 绘制三角形
    void draw() override {
        cout << "Drawing Triangle with sides " << side1 
             << ", " << side2 << ", " << side3 
             << " and color " << getColor() << endl;
    }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Rectangle("Red");
    shapes[1] = new Circle("Blue");
    shapes[2] = new Triangle("Green");

    for (int i = 0; i < 3; ++i) {
        cout << "Input info for shape " << i + 1 << ":" << endl;
        shapes[i]->inputInfo();
    }

    for (int i = 0; i < 3; ++i) {
        cout << "Drawing shape " << i + 1 << ":" << endl;
        shapes[i]->draw();
    }

    for (int i = 0; i < 3; ++i) {
        delete shapes[i];
    }

    return 0;
}