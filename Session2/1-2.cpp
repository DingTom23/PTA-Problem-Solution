//
// Created by DingTom on 25-4-21.
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Dot{

  public:
    Dot(float x, float y)
        : x(x), y(y) {
      cout << "Dot constructor called" << endl;

    }
    float getX() const { return x; }
    float getY() const { return y; }
    ~Dot(){

      cout << "Dot destructor called" << endl;

    }

  private:

    float x, y;
};

class Color{
  public:

    Color(string colorName)
        : colorName(colorName) {

      cout << "Color constructor called" << endl;

    }
    string getColor(){

      return colorName;

    }
    ~Color(){

      cout << "Color destructor called" << endl;

    }
  private:

    string colorName;
};

class ColorCircle : public Dot, public Color{
  public:

    ColorCircle(float x, float y, float radius, string colorName)
        : Dot(x, y) , radius(radius),Color(colorName){

      cout << "ColorCircle constructor called" << endl;

    }

    float getArea(){
      return 3.14 * radius * radius;
    }

    void showInfo(){
      cout << "Position: (" << getX() << ", " << getY() << "), ";
      cout << "Radius: " << radius << ", ";
      cout << "Color: " << getColor() << endl;
    }

    ~ColorCircle(){
      cout << "ColorCircle destructor called" << endl;
    }

  private:

    float radius;

};

int main() {
  float x, y, r;
  string color;
  cin >> x >> y >> r >> color;

  ColorCircle cc(x, y, r, color);
  cout << fixed << setprecision(2);
  cout << "Area: " << cc.getArea() << endl;
  cout << "Color: " << cc.getColor() << endl;
  cc.showInfo();

  return 0;
}