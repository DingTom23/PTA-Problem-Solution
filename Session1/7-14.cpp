#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // 这个地方获得一行的输入
    string line;
    getline(cin, line);

    // 把空格提取出来
    istringstream in(line);
    vector<int> numbers;
    int num;
    while (in >> num) {
        numbers.push_back(num);
    }

    bool found = false;
    int position = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 250) {
            position = i + 1; 
            found = true;
            break;
        }
    }

    if (found) {
        cout << position << endl;
    }

    return 0;
}