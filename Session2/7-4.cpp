/*
7-4 类的定义和使用
请定义一个Point类，有两个数据成员：x和y, 分别代表x坐标和y坐标，
并有若干构造函数和一个移动的成员函数，可输出移动后新的坐标值。

输入:
第一行的两个数 分别表示  点的x坐标和y坐标。
第二行的两个数 分别表示  x和y方向移动的距离。

输出:
移动后的点的x坐标和y坐标。

输入样例:
1  5
2  5

输出样例:
3 10
*/

#include <iostream>
using namespace std;

class Point
{
    public:
        Point(int x, int y, int x_move, int y_move){
            this->x = x;
            this->y = y;
            this->x_move = x_move;
            this->y_move = y_move;
        };
        void move(int x_move, int y_move){
            x += x_move;
            y += y_move;
        };
        void print(){
            cout << x << " " << y << endl;
        };

    private:
        int x;
        int y;
        int x_move;
        int y_move;
};

int main(){
    int x, y, x_move, y_move;
    cin >> x >> y;
    cin >> x_move >> y_move;
    Point p(x, y, x_move, y_move);
    p.move(x_move, y_move);
    p.print();
    return 0;
}