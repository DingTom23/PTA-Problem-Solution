// 如何转换到 二进制 
#include <iostream>
#include <bitset>

using namespace std;

int main(){

    int n = 99;
    cout << "n= " << n << endl;

    // 除二取余法

    cout << "First Method: " << endl;

    if (n == 0) {
        cout << "0" << endl;
    } else {
        string result = "";
        while (n > 0) {
            result = (n % 2 == 0 ? "0" : "1") + result;
            n = n / 2;          
        }
        cout << result << endl;
        cout << endl;
    }

    // 库函数

    cout << "Second Method: " << endl;

    bitset<32> x(n);
    cout << x << endl;
    cout << endl;

    // 除二取余法2

    cout << "Third Method: " << endl;

    void printBinary(int n);
    printBinary(n);
    cout << endl;

    return 0;
}

void printBinary(int n) {
    if (n > 1) {
        printBinary(n / 2);
    }
    cout << n % 2;
}