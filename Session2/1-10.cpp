#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class polygon {
protected:
    int number; // 边数
private:
    int side_length[100]; // 边长数据（最多支持100条边）
public:
    polygon() : number(0) {
        for (int i = 0; i < 100; i++) {
            side_length[i] = 0;
        }
    }

    void set_sides(const int* sides, int count) {
        if (count < 0 || count > 100) {
            number = 0; // 可选：处理非法输入
            return;
        }
        number = count; // 直接设置边数
        for (int i = 0; i < count; i++) {
            side_length[i] = sides[i]; // 正确复制元素
        }
    }

    void display() {
        int result = 0; // 初始化result
        for (int i = 0; i < number; i++) {
            result += side_length[i];
        }
        cout << number << ' ' << result << endl;
    }
};

class rectangle : public polygon{ // 矩形
    private:
        int height;
        int width;
    public:
        rectangle(){};
        void set_dimensions(int h, int w){
            height = h;
            width = w;
            number = 4;
        }
        int perimeter(int h, int w){
            int result;
            result = (h*2) + (w*2);
            return result;
        }
        void display(){
            int result = perimeter(height, width);
            cout << number << ' ' << result << endl;
        }
};

class equal_polygon : public polygon{
    public:
        equal_polygon(){}
        void set_equal_sides(int sides, int mlen){
            number = sides;
            len = mlen;
        }

        void display(){
            int result = number * len;
            cout << number << ' ' << result << endl;
        }
    private:
        int len;
};

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        if (type == 0) {
            polygon p;
            int sides[100];
            int count = 0;
            int len;
            while (cin >> len && len != -1) {
                sides[count++] = len;
            }
            p.set_sides(sides, count);
            p.display();
        }
        else if (type == 1) {
            rectangle r;
            int h, w;
            cin >> h >> w;
            r.set_dimensions(h, w);
            r.display();
        }
        else if (type == 2) {
            equal_polygon ep;
            int sides, len;
            cin >> sides >> len;
            ep.set_equal_sides(sides, len);
            ep.display();
        }
    }

    return 0;
}