/*
米尔科需要在平面上选择四个点，
以便它们形成一个矩形，边与轴平行。
输入格式:
已经选择的三个点中的每一个都将在单独的行中给出。
所有坐标都是1到1000之间的整数。

输出格式:
输出矩形第四个顶点的坐标。
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    vector<pair<int, int>> points(3);
    map<int, int> x_count, y_count;
    
    // 读取三个点并统计x、y坐标的出现次数
    for (int i = 0; i < 3; i++) {
        cin >> points[i].first >> points[i].second;
        x_count[points[i].first]++;
        y_count[points[i].second]++;
    }
    
    int target_x, target_y;
    
    // 找出出现次数为1的x坐标（第四个点的x坐标）
    for (auto& p : x_count) {
        if (p.second == 1) {
            target_x = p.first;
            break;
        }
    }
    
    // 找出出现次数为1的y坐标（第四个点的y坐标）
    for (auto& p : y_count) {
        if (p.second == 1) {
            target_y = p.first;
            break;
        }
    }
    
    cout << target_x << " " << target_y << endl;
    
    return 0;
}