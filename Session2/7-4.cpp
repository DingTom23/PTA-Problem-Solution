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