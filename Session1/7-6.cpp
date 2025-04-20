#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double kw;
    cin >> kw;
    if (kw < 0) {
        cout << "Invalid Value!" << endl;
        return 0;
    }

    double cost;
    if (kw <= 50.0) {
        cost = kw * 0.53;
    }
    else {
        cost = 0.53 * 50 + (kw - 50.0) * 0.58;
    }

    cout << "cost = " << setiosflags(ios::fixed)
        << setprecision(2)
        << cost << endl;
    return 0;
}