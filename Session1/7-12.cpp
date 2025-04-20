#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int peaches = 1; 
    
    for (int i = 1; i < N; ++i) {
        peaches = (peaches + 1) * 2;
    }

    cout << peaches << endl;

    return 0;
}