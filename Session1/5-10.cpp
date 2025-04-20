#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 读取数据
    int n;
    cin >> n;
    
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    // 逆序输出
    reverse(numbers.begin(), numbers.end());
    
    // 输出
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << (i == n - 1 ? '\n' : ' ');
    }
    return 0;
}