#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    int max_height;
    int n = 0;

    for (int i = 0; i < 10; i++) {
        int height;
        cin >> height;
        v.push_back(height);
    }
    
    cin >> max_height;
    
    for (int i = 0; i < 10; i++){

        if (v[i] <= max_height + 30) {
            n++;
        }
    }
    cout << n << endl;
    return 0;
}