#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string doChange(string str)
{
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - 'A' + 'a';
        }else if (str[i] >= '0' && str[i] <= '9'){
            str[i] = str[i] - '0' + 'a';
        }
    }
    return str;
}

int main()
{
    string str;
    cin >> str;
    int len = str.length();
    int maxLen = 1;
    int curLen = 1;
    int from = 0;
    int to = 0;
    str = doChange(str);
    
    for (int i = 1; i < len; i++)
    {
        if (str[i] == str[i - 1]){
            curLen++;
        }else{
            if (curLen > maxLen)
            {
                maxLen = curLen;
                from = i - curLen + 1;
                to = i;
            }
            curLen = 1;
        }
    }
    if (curLen > maxLen) {
        maxLen = curLen;
        from = len - curLen;
        to = len - 1;
    }
    cout << "From=" << from << ",To=" << to << endl;
    cout << "MaxLen=" << maxLen << endl;
    return 0;
}