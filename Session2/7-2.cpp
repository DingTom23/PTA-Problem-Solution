#include <iostream>

using namespace std;

class Box{
    private:
        int length, width, height;

    public:
        Box(int l, int w, int h) {
            length = l;
            width = w;
            height = h;
        }
        int volume() {
            return length * width * height;
        }
};

int main(){
    int l, w, h;
    cin >> l >> w >> h;
    
    Box box(l, w, h);
    cout << box.volume() << endl;

    return 0;
}