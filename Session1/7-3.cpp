#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    cout << "交换后, firstNumber ="
        << setiosflags(ios::fixed)
        << setprecision(2)
         << b << endl;
    cout << "交换后, secondNumber ="
        << setiosflags(ios::fixed)
        << setprecision(2)
        << a << endl;
    return 0;
}