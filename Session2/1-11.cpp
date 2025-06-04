#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    string r, v;

    if (s[0] != '-') { // 首先检测 - 号 eg. 1+3i 1-3i 3i 4 i
        size_t plus_pos = s.find('+'); // 找到 + 号的位置
        size_t minus_pos = s.find('-'); // 找到 - 号的位置·
        
        if (plus_pos != string::npos) { // 如果 + 号存在 那么意味着一定有 实部 因为是连接实部与虚部的部分 eg. 1+3i
            r = s.substr(0, plus_pos); // 截取实数部分
            v = s.substr(plus_pos + 1); // 截取虚部部分
            v.pop_back(); // 去掉虚部部分的 'i'

        } else if (minus_pos != string::npos) { // eg. 1-3i
            r = s.substr(0, minus_pos);
            v = s.substr(minus_pos); // 把虚部取出来
            v.pop_back(); // 去掉虚部部分的 'i'

        } else { // eg. 3i i
            if (s.find('i') != string::npos) {
                r = "0"; // 实部为 0
                size_t i_pos = s.find('i');
                string v_part = s.substr(0, i_pos);
                if (v_part.empty()) { // eg. i
                    v = "1";
                } else { // eg. 3i
                    v = v_part;
                }
            } else { // eg. 4
                r = s;
                v = "0";
            }
        }
        cout << "complex " << s << endl;
        cout << "the real part is " << r << endl;
        cout << "and the imaginary part is " << v << endl;
    } else { // 有 - 号 eg. -1+3i -1-3i -3i -4 -i
        s = s.substr(1); // 去掉前导 '-'
        size_t plus_pos = s.find('+'); 
        size_t minus_pos = s.find('-'); 
        
        if (plus_pos != string::npos || minus_pos != string::npos) { // eg. -1+3i -1-3i
            size_t split_pos;
            char op;
            if (plus_pos != string::npos) { // eg. -1+3i 
                split_pos = plus_pos;
                op = '+';
            } else { // eg.-1-3i
                split_pos = minus_pos;
                op = '-';
            }
            r = s.substr(0, split_pos);
            
            if (op == '+') {
                v = s.substr(split_pos + 1); // eg. -1+3i 
            } else {
                v = s.substr(split_pos); // eg.-1-3i
            }
            v.pop_back();
            r = "-" + r;
        } else {
            if (s.find('i') != string::npos) {
                r = "0";
                size_t i_pos = s.find('i');
                string v_part = s.substr(0, i_pos);
                if (v_part.empty()) { // eg. -i
                    v = "-1";
                } else { // eg. -3i
                    v = "-" + v_part;
                }
            } else { // eg. -4
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