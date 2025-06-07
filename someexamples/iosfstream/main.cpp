#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

    ofstream out("file.txt", ios::out);
    if (!out) {
        cerr << "Cannot open the file." << endl;
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int num = rand() % 100 + 1;
        out << num << " ";
    }
    out.close();

    int a[10], max, i, order;

    ifstream in("file.txt", ios::in);
    if (!in) {
        cerr << "Cannot open the file." << endl;
        return 1;
    }

    for (i = 0; i < 10; i++) {
        in >> a[i];
        cout << a[i] << " ";
    }
    cout << endl;

    in.close();

    max=a[0];
    order=0;
    for (i = 0; i < 10; i++) {
        if (a[i] > max) {
            max = a[i];
            order = i;
        }
    }

    cout << "The max number is: " << max << endl;
    return 0;

}