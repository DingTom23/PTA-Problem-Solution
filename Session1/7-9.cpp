#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 定义水果的单价
    const double prices[5] = {0.0, 3.00, 2.50, 4.10, 10.20};
    
    // 显示菜单
    cout << "[1] apple\n";
    cout << "[2] pear\n";
    cout << "[3] orange\n";
    cout << "[4] grape\n";
    cout << "[0] exit\n";
    
    // 变量定义
    int input;
    int query_count = 0;
    
    // 连续输入用户查询
    while (cin >> input) {
        // 如果查询次数超过5次，自动退出
        if (query_count >= 5) {
            break;
        }
        // 如果输入0，则退出
        if (input == 0) {
            break;
        }
        // 如果输入是1到4，则输出对应价格
        if (input >= 1 && input <= 4) {
            cout << fixed << setprecision(2) << "price = " << prices[input] << endl;
            query_count++;
        }
        // 如果输入其他数字，则输出0.00
        else {
            cout << fixed << setprecision(2) << "price = 0.00" << endl;
        }
    }

    return 0;
}