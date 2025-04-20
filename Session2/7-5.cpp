/*
7-5 字符统计问题
【问题描述】
实验室有个胖子叫小明，他第一天进来，
老师就叫他练打字，开始练的是打英文字母，
小明打了一小时就累啦，
老师看他累就叫他不用再练啦，
但前提是必须知道他打的英文字母串里连续相同的字符最多到底有几个？
亲爱的同学们，如果你们同情胖子小明，
那么你就帮他写个程序，计算一下在一个字符串里面连续相同的字符最多到底有多少个？这里我们假定字符串都是由英文小写字母、大写字母和数字组成的；字符串的长度不超过100000；我们规定“相同”的定义为：
1：不区分大小写；
2：“0”=“a”=“A”；“1”=“b”=“B”；……；“9”=“j”=“J”；
【输入输出】
输入是一行字符串，输出有两行，
第一行的格式是：“From=XX,To=XX”，
第二行的格式是：“MaxLen=XX”。
本问题有多组测试数据。如果有多组符合要求的解，那么输出起始位置最小的解。  

Sample Input：
iaaaaa000AAAAwh  

Sample Output：
From=2,To=13
MaxLen=12
*/

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