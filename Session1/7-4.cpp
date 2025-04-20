#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    // a b c  c b a
    int a, b, c;
    a = n / 100;
    b = n / 10 - (a * 10);
    c =  n % 10;

    int newnum;
    newnum = c * 100 + b * 10 + a;
    cout << newnum << endl;
    return 0;
}