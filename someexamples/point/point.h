#include <iostream>

using namespace std;

class Sharp{
    public:
        virtual float area() const = 0;
        virtual float volume () const = 0;
        virtual void sharpName() const = 0;
};

class Point : public Sharp{
    protected:
        float x;
        float y;
    public:

        Point(float x = 0, float y = 0){
            this->x = x;
            this->y = y;
        }

        void setPoint(float a, float b){
            this->x = a;
            this->y = b;
        }

        float getX() const { return x; }
        float getY() const { return y; }

        virtual void sharpName() const{
            cout << "Point: " << endl;
        }

        friend ostream &operator<<(ostream &, const Point &);
        friend istream &operator>>(istream &, Point &);
};

ostream &operator<<(ostream &output, const Point &p){
    output << "[" << p.x << ", " << p.y << "]";
    return output;
}

istream &operator>>(istream &input, Point &p){
    input >> p.x >> p.y;
    return input;
}

class Circle : public Point{
    protected:
        float radius;
    public:
        Circle(float x = 0, float y = 0, float r = 0) : Point(x, y){
            radius = r;
        }

        void setRadius(float r){
            radius = r;
        }

        float getRadius() const { return radius; }

        float area() const { return 3.14159 * radius * radius; }
        float volume() const { return 0; }

        friend ostream &operator<<(ostream &, const Circle &);
        friend istream &operator>>(istream &, Circle &);

};

ostream &operator<<(ostream &output, const Circle &c){
    output << "Center = [" << c.x << ", " << c.y << "], r = " << c.radius << ", area = " << c.area();
    return output;
}

istream &operator>>(istream &input, Circle &c){
    input >> c.x >> c.y >> c.radius;
    return input;
}

class Cylinder : public Circle{
    protected:
        float height;
    public:
        Cylinder(float x = 0, float y = 0, float r = 0, float h = 0) : Circle(x, y, r){
            height = h;
        }

        void setHeight(float h){
            height = h;
        }

        float getHeight() const { return height; }

        float area() const { return 2 * 3.14159 * radius * radius + 2 * 3.14159 * radius * height; }
        float volume() const { return 3.14159 * radius * radius * height; }

        friend ostream &operator<<(ostream &, const Cylinder &);
        friend istream &operator>>(istream &, Cylinder &);
};

ostream &operator<<(ostream &output, const Cylinder &c){
    output << "Center = [" << c.x << ", " << c.y << "], r = " << c.radius << ", h = " << c.height << ", area = " << c.area() << ", volume = " << c.volume();
    return output;
}

istream &operator>>(istream &input, Cylinder &c){
    input >> c.x >> c.y >> c.radius >> c.height;
    return input;
}







