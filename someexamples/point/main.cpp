#include <iostream>
#include "point.h"

using namespace std;

int main(){
    
    Cylinder cy1(1, 2, 3, 4);
    
    cout << "cy1: " << cy1 << endl;

    cout << "x = " << cy1.getX() << endl;
    cout << "y = " << cy1.getY() << endl;
    cout << "radius = " << cy1.getRadius() << endl;
    cout << "height = " << cy1.getHeight() << endl;
    cout << "area = " << cy1.area() << endl;
    
    return 0;
}