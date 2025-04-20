#include <iostream>
#include <string>
using namespace std;

int main() {

    int N;
    cin >> N;

    while (N--) {
        string s;
        cin >> s;

        // 初始化
        char maxChar = s[0];    // 当前发现的最长连续字符
        int maxCount = 1;       // 该字符的连续次数
        char currentChar = s[0];
        int currentCount = 1;

        // 遍历字符串，从第1个字符（下标1）开始
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == currentChar) {
                currentCount++;
            } else {
                // 出现新字符，对比一下上次连续段与最大连续段
                if (currentCount > maxCount) {
                    maxCount = currentCount;
                    maxChar = currentChar;
                }
                // 重置统计为新字符
                currentChar = s[i];
                currentCount = 1;
            }
        }

        // 遍历结束后，再最后检查一次
        if (currentCount > maxCount) {
            maxCount = currentCount;
            maxChar = currentChar;
        }
        cout << maxChar << " " << maxCount << "\n";
    }

    return 0;
}