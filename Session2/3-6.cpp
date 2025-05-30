#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string NO; // 车牌号
public:
    Vehicle(string no) : NO(no) {} // 构造函数初始化车牌号
    virtual void display() = 0; // 纯虚函数，用于输出费用
};

class Car : public Vehicle {
private:
    int guest; // 载客数
    int weight; // 重量
public:
    Car(string no, int g, int w) : Vehicle(no), guest(g), weight(w) {}
    void display() override {
        int fee = guest * 8 + weight * 2; // 计算费用：8*载客数 + 2*重量
        cout << NO << " " << fee << endl;
    }
};

class Truck : public Vehicle {
private:
    int weight; // 重量
public:
    Truck(string no, int w) : Vehicle(no), weight(w) {}
    void display() override {
        int fee = weight * 5; // 计算费用：5*重量
        cout << NO << " " << fee << endl;
    }
};

class Bus : public Vehicle {
private:
    int guest; // 载客数
public:
    Bus(string no, int g) : Vehicle(no), guest(g) {}
    void display() override {
        int fee = guest * 3; // 计算费用：3*载客数
        cout << NO << " " << fee << endl;
    }
};

int main() {
    Vehicle *pv[10]; // 基类指针数组
    int type, count = 0; // 车辆类型和计数器
    string no;
    int guest, weight;

    while (cin >> type) {
        if (type == 0) break; // 输入0结束
        cin >> no; // 读取车牌号
        switch (type) {
            case 1: // Car
                cin >> guest >> weight;
                pv[count] = new Car(no, guest, weight);
                break;
            case 2: // Truck
                cin >> weight;
                pv[count] = new Truck(no, weight);
                break;
            case 3: // Bus
                cin >> guest;
                pv[count] = new Bus(no, guest);
                break;
        }
        count++;
    }

    // 遍历数组，调用display输出结果
    for (int i = 0; i < count; i++) {
        pv[i]->display();
        delete pv[i]; // 释放动态分配的内存
    }

    return 0;
}