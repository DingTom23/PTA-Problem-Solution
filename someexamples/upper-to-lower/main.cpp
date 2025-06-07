#include <iostream>
#include <algorithm>
 
using namespace std;
string s;
int main() {
    cout<<"请输入一个含大写的字符串：";
    string str;
    cin >> str;

    transform(str.begin(),str.end(),str.begin(),::tolower);
    cout<<"转化为小写后为："<<str<<endl;
    transform(str.begin(),str.end(),str.begin(),::toupper);
    cout<<"转化为大写后为："<<str<<endl;

    // 或者手动实现
    cout << "请再输入一个字符串进行手动转换：";
    string str2;
    cin >> str2;

    // 转换为小写
    string lower_str = str2;
    for (int i = 0; i < lower_str.size(); i++){
        if (lower_str[i] >= 'A' && lower_str[i] <= 'Z'){
            lower_str[i] = lower_str[i] + 32;  // 大写转小写
        }
    }
    cout << "手动转换为小写：" << lower_str << endl;

    // 转换为大写
    string upper_str = str2;
    for (int i = 0; i < upper_str.size(); i++){
        if (upper_str[i] >= 'a' && upper_str[i] <= 'z'){
            upper_str[i] = upper_str[i] - 32;  // 小写转大写
        }
    }
    cout << "手动转换为大写：" << upper_str << endl;

    return 0;
}