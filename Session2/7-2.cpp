/*
7-2 立方体类
定义立方体类Box，数据成员有长宽高且都是整数，构造函数初始化数据成员，成员函数计算体积，主函数中输入长宽高，输出立方体体积。

输入格式:
输入立方体的长宽高，中间用空格分隔。

输出格式:
输出体积并换行。

输入样例:
在这里给出一组输入。例如：

1 2 3
输出样例:
在这里给出相应的输出。例如：
6
*/

#include <iostream>
using namespace std;

class Box{
    public:
    Box(int l, int w, int h){
        length = l;
        width = w;
        height = h;
    }
    int volume(){
        return length * width * height;
    }
    private:
    int length, width, height;
};

int main(){
    int l, w, h;
    cin >> l >> w >> h;
    Box box(l, w, h);
    cout << box.volume() << endl;
    return 0;
}