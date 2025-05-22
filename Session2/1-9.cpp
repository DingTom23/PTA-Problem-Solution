#include <iostream>
#include <cmath>
using namespace std;

class Point_1D {
protected:
    float x;
public:
    Point_1D(float p = 0.0) : x(p) {}
    float distance(const Point_1D& p2) const {
        return abs(x - p2.x);
    }
};

class Point_2D : public Point_1D {
protected:
    float y;
public:
    Point_2D(float p = 0.0, float q = 0.0) : Point_1D(p), y(q) {}
    float distance(const Point_2D& p2) const {
        float dx = x - p2.x;
        float dy = y - p2.y;
        return sqrt(dx*dx + dy*dy);
    }
};

class Point_3D : public Point_2D {
protected:
    float z;
public:
    Point_3D(float p = 0.0, float q = 0.0, float r = 0.0) : Point_2D(p, q), z(r) {}
    float distance(const Point_3D& p2) const {
        float dx = x - p2.x;
        float dy = y - p2.y;
        float dz = z - p2.z;
        return sqrt(dx*dx + dy*dy + dz*dz);
    }
};

int main() {
    int type;
    while (cin >> type && type != 0) {
        if (type == 1) {
            float x;
            cin >> x;
            Point_1D p1(x), origin;
            cout << "Distance from Point " << x << " to Point 0 is " << p1.distance(origin) << endl;
        }
        else if (type == 2) {
            float x, y;
            cin >> x >> y;
            Point_2D p1(x, y), origin;
            cout << "Distance from Point(" << x << "," << y << ") to Point(0,0) is " << p1.distance(origin) << endl;
        }
        else if (type == 3) {
            float x, y, z;
            cin >> x >> y >> z;
            Point_3D p1(x, y, z), origin;
            cout << "Distance from Point(" << x << "," << y << "," << z << ") to Point(0,0,0) is " << p1.distance(origin) << endl;
        }
    }
    return 0;
}