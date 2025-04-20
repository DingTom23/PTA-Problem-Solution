/*
鸿鸿哥家的院子里有一棵桃子树，每到秋天树上就会结出10个桃子。
桃子成熟的时候，鸿鸿哥就会跑去摘桃子。
鸿鸿哥有个30厘米高的板凳，当他不能直接用手摘到桃子的时候，
就会踩到板凳上再试试。 现在已知10个桃子到地面的高度，
以及鸿鸿哥把手伸直的时候能够达到的最大高度，
请帮鸿鸿哥算一下他能够摘到的桃子的数目。假设他碰到桃子，桃子就会掉下来。

输入格式:
第一行中给出10个桃子到地面的高度(cm)。

第二行中输入鸿鸿哥把手伸直能够达到的最大高度(cm)。

输出格式:
输出鸿鸿哥能够摘到的桃子数目n。

输入样例:
在这里给出一组输入。例如：

26 95 43 77 49 31 87 19 35 65
40
输出样例:
在这里给出相应的输出。例如：

7
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    int max_height;
    int n = 0;
    for (int i = 0; i < 10; i++)
    {
        int height;
        cin >> height;
        v.push_back(height);
    }
    cin >> max_height;
    for (int i = 0; i < 10; i++)
    {
        if (v[i] <= max_height + 30)
        {
            n++;
        }
    }
    cout << n << endl;
    return 0;
}