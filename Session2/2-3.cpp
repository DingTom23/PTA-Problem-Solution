#include <iostream>
using namespace std;

template<typename T>
class Square {
private:
    T width; // 正方形的边长

public:
    // 构造函数
    Square(T w) {
        width = w;
    }

    // 计算正方形的面积
    T getArea() {
        return width * width;
    }
};

int main() {
    int width1;
    cin >> width1; // 输入正方形的边长
    Square<int> square1(width1);
    cout << square1.getArea() << endl; // 输出正方形的面积

    double width2;
    cin >> width2; // 输入正方形的边长
    Square<double> square2(width2);
    cout << square2.getArea() << endl; // 输出正方形的面积

    return 0;
}