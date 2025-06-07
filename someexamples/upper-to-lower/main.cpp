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

    // 或者

    for (int i = 0; i < str.size(); i++){
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'){
            
        }
    }

    return 0;
}