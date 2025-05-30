#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void move() = 0;     // 纯虚函数，描述移动方式
    virtual void input() = 0;    // 纯虚函数，输入参数
    virtual ~Vehicle() {}        // 虚析构函数
};

class Car : public Vehicle {
private:
    int speed;  // 汽车速度
public:
    Car() : speed(0) {}  // 默认构造函数
    void input() override {
        cout << "Enter car speed (km/h):" << endl;
        cin >> speed;
    }
    void move() override {
        cout << "Car moves on roads at speed " << speed << " km/h." << endl;
    }
};

class Bicycle : public Vehicle {
private:
    int speed;  // 自行车速度
public:
    Bicycle() : speed(0) {}  // 默认构造函数
    void input() override {
        cout << "Enter bicycle speed (km/h):" << endl;
        cin >> speed;
    }
    void move() override {
        cout << "Bicycle moves on roads at speed " << speed << " km/h." << endl;
    }
};

class Airplane : public Vehicle {
private:
    int altitude;  // 飞机高度
public:
    Airplane() : altitude(0) {}  // 默认构造函数
    void input() override {
        cout << "Enter airplane altitude (meters):" << endl;
        cin >> altitude;
    }
    void move() override {
        cout << "Airplane flies in the sky at altitude " << altitude << " meters." << endl;
    }
};

// 注意：以下main函数是题目给定的，不可修改
int main() {
    Vehicle* vehicles[3];
    vehicles[0] = new Car();
    vehicles[1] = new Bicycle();
    vehicles[2] = new Airplane();

    for (int i = 0; i < 3; ++i) {
        cout << "Input for Vehicle " << i + 1 << ":" << endl;
        vehicles[i]->input();
    }

    for (int i = 0; i < 3; ++i) {
        cout << "Vehicle " << i + 1 << ": ";
        vehicles[i]->move();
    }

    // 释放内存
    for (int i = 0; i < 3; ++i) {
        delete vehicles[i];
    }

    return 0;
}