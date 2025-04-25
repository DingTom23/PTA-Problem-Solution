#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// 请在此处实现Shape、Rectangle和RegularPolygon类
/*
输出样例:
在这里给出相应的输出。例如：

Shape constructor: Default Rectangle
Shape constructor: Default Polygon
Shape constructor: Rectangle
Shape constructor: Hexagon
Rectangle: sides=4, width=0, height=0
Regular Polygon: sides=0, sideLength=0
Rectangle: sides=4, width=5, height=10
Regular Polygon: sides=6, sideLength=8
Shape destructor: Hexagon
Shape destructor: Rectangle
Shape destructor: Default Polygon
Shape destructor: Default Rectangle

*/

class Shape {
protected:
    string name;  // 图形名称
    int sides;    // 边数
public:
    Shape(string n, int s) : name(n), sides(s) {
        cout << "Shape constructor: " << name << endl;
    }
    virtual ~Shape() {
        cout << "Shape destructor: " << name << endl;
    }
    virtual void display() = 0;
};

class Rectangle : public Shape {
private:
    int width, height;
public:
    Rectangle() : Shape("Default Rectangle", 4), width(0), height(0) {}
    Rectangle(int w, int h) : Shape("Rectangle", 4), width(w), height(h) {}
    ~Rectangle() {}
    void display() override {
        cout << "Rectangle: sides=" << sides << ", width=" << width << ", height=" << height << endl;
    }
};

class RegularPolygon : public Shape {
private:
    int sideLength;
    static string getName(int s) {
        switch(s) {
            case 3: return "Triangle";
            case 4: return "Square";
            case 5: return "Pentagon";
            case 6: return "Hexagon";
            default: return "Regular Polygon";
        }
    }
public:
    RegularPolygon() : Shape("Default Polygon", 0), sideLength(0) {}
    RegularPolygon(int s, int l) : Shape(getName(s), s), sideLength(l) {}
    ~RegularPolygon() {}
    void display() override {
        cout << "Regular Polygon: sides=" << sides << ", sideLength=" << sideLength << endl;
    }
};

int main() {
    Rectangle r1;
    RegularPolygon p1;
    Rectangle r2(5, 10);
    RegularPolygon p2(6, 8);
    
    Shape* shapes[] = {&r1, &p1, &r2, &p2};
    for (auto shape : shapes) {
        shape->display();
    }
    return 0;
}
