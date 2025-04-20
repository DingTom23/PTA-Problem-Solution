#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * @brief 将 n 个 '1' 所组成的数除以 x，并返回商的字符串表示。
 * 
 * 例如：
 * 若 n = 5, 表示的数为 11111
 * 若 x = 3，则 11111 / 3 = 3703
 * 这里仅实现的是以“循环除法”的方式分批算出商的每一位。
 *
 * @param n  n 个 '1'
 * @param x  除数
 * @return   返回商（去掉前导零）的字符串，如果商为 0 则返回 "0"
 */
string divide_n_ones_by_x(int n, int x) {
    string quotient; // 存储结果商
    int carry = 0;   // 余数（带到下一位的“进位”）
    
    // 循环 n 次，每次相当于“多出一位 1”进行除法
    for (int i = 0; i < n; ++i) {
        // 由于上一轮可能有余数 carry，这一轮我们要将其乘以 10 再加上 1
        // 类似手动除法中“把余数左移”再加上下一位数字的过程
        int temp = carry * 10 + 1;
        
        // 当前位的商
        int quotient_digit = temp / x;
        // 当前位除以 x 的余数，继续带到下一轮
        carry = temp % x;
        
        // 将当前位的商转换为字符并加到商字符串后面
        quotient += (quotient_digit + '0');
    }

    // 去掉商的前导零
    size_t pos = quotient.find_first_not_of('0');
    if (pos != string::npos) {
        // 如果找到非零位置，则截断到那里
        return quotient.substr(pos);
    } else {
        // 如果整串都是 '0'，则返回 "0"
        return "0";
    }
}

int main() {
    int x;
    cin >> x;  // 读取要检测的除数 x

    // 初始余数 rem = 1 % x，对应最开始只有一个 '1'
    int rem = 1 % x;
    int n = 1; // 记录当前“1”的个数
    // 用一个哈希表来记录出现过的余数，检测是否会进入死循环（无法整除 x）
    unordered_set<int> remainders;
    remainders.insert(rem);

    // 循环直到余数变为 0（说明整除了）为止
    while (rem != 0) {
        // 余数更新公式：模拟在后面再加一个 '1'
        // 即把 rem * 10 + 1 后再对 x 取模
        rem = (rem * 10 + 1) % x;
        n++;

        // 如果这个余数在之前出现过，则说明出现了循环，永远也无法整除 x，直接结束
        if (remainders.count(rem)) {
            return 0; // 不输出任何结果
        }
        // 否则记录新的余数
        remainders.insert(rem);
    }

    // 能到这里说明余数等于 0，即 n 个 '1' 可以整除 x
    // 计算商并输出
    string s = divide_n_ones_by_x(n, x);
    cout << s << " " << n << endl;
    return 0;
}