#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string expression;
    cin >> expression;

    long long result = 0, currentNum = 0;
    char operation = '+';  // 初始为加法，用于处理第一个数字

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];

        if (isdigit(c)) {
            currentNum = currentNum * 10 + (c - '0');  // 解析当前数字
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=') {
            // 处理上一个运算符
            if (operation == '+') {
                result += currentNum;
            } else if (operation == '-') {
                result -= currentNum;
            } else if (operation == '*') {
                result *= currentNum;
            } else if (operation == '/') {
                if (currentNum == 0) {
                    cout << "ERROR" << endl;
                    return 0;
                }
                result /= currentNum;
            } else {
                cout << "ERROR" << endl;  // 非法运算符
                return 0;
            }

            // 更新运算符和当前数字
            operation = c;
            currentNum = 0;

            // 如果遇到等号，直接输出结果并结束程序
            if (c == '=') {
                cout << result << endl;
                return 0;
            }
        } else {
            cout << "ERROR" << endl;  // 非法字符
            return 0;
        }
    }
    return 0;
}