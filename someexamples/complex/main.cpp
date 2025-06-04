#include <iostream>
#include "complex.h"

using namespace std;

int main() {
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    cout << c3 << endl;
    cout << c4 << endl;
    return 0;

    Complex c5;
    int n = 5;
    c5 = n + c1; // application: convert int to Complex
    cout << c5 << endl;
    return 0;
}