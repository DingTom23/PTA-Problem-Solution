#include <iostream>
using namespace std;

template<typename T>
void myswap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a, b;
    cin >> a >> b;
    myswap(a, b); // 交换两个数
    cout << a << " " << b << endl;                                             

    double x, y;
    cin >> x >> y;
    myswap(x, y); // 交换两个数
    cout << x << " " << y << endl;                                             
    return 0;
}