#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    int min_value = numbers[0];
    int min_index = 0;
    
    for (int i = 1; i < n; i++) {
        if (numbers[i] < min_value) {
            min_value = numbers[i];
            min_index = i;
        }
    }
    
    cout << min_value << " " << min_index << endl;
    
    return 0;
}