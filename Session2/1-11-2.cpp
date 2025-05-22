#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    string r, v;

    if (s.empty()) {
        cout << "complex 0" << endl;
        cout << "the real part is 0" << endl;
        cout << "and the imaginary part is 0" << endl;
        return 0;
    }

    if (s[0] != '-') {
        size_t plus_pos = s.find('+');
        size_t minus_pos = s.find('-');
        
        if (plus_pos != string::npos) {
            r = s.substr(0, plus_pos);
            v = s.substr(plus_pos + 1);
            v.pop_back(); // 去掉最后的i
        } else if (minus_pos != string::npos) {
            r = s.substr(0, minus_pos);
            v = s.substr(minus_pos);
            v.pop_back();
        } else {
            // 没有分隔符
            if (s.find('i') != string::npos) {
                // 只有虚部
                r = "0";
                size_t i_pos = s.find('i');
                string v_part = s.substr(0, i_pos);
                if (v_part.empty() || v_part == "+") {
                    v = "1";
                } else if (v_part == "-") {
                    v = "-1";
                } else {
                    v = v_part;
                }
            } else {
                // 只有实部
                r = s;
                v = "0";
            }
        }
        cout << "complex " << s << endl;
        cout << "the real part is " << r << endl;
        cout << "and the imaginary part is " << v << endl;
    } else {
        s = s.substr(1); // 去掉前导 '-'
        size_t plus_pos = s.find('+');
        size_t minus_pos = s.find('-');
        
        if (plus_pos != string::npos || minus_pos != string::npos) {
            // 有分隔符
            size_t split_pos;
            char op;
            if (plus_pos != string::npos) {
                split_pos = plus_pos;
                op = '+';
            } else {
                split_pos = minus_pos;
                op = '-';
            }
            r = s.substr(0, split_pos);
            if (op == '+') {
                v = s.substr(split_pos + 1);
            } else {
                v = s.substr(split_pos);
            }
            v.pop_back();
            // 实部加上前导负号
            r = "-" + r;
        } else {
            // 没有分隔符
            if (s.find('i') != string::npos) {
                // 只有虚部
                r = "0";
                size_t i_pos = s.find('i');
                string v_part = s.substr(0, i_pos);
                if (v_part.empty() || v_part == "+") {
                    v = "-1";
                } else if (v_part == "-") {
                    v = "1";
                } else {
                    v = "-" + v_part;
                }
            } else {
                // 只有实部
                r = "-" + s;
                v = "0";
            }
        }
        cout << "complex -" << s << endl;
        cout << "the real part is " << r << endl;
        cout << "and the imaginary part is " << v << endl;
    }
    
    return 0;
}