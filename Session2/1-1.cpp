//
// Created by DingTom on 25-4-20.
//

#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.14;

class Dot {
protected:
  float x;
  float y;
public:
  Dot(float x, float y) : x(x), y(y) {
    cout << "Dot constructor called" << endl;
  }

  ~Dot(){
    cout << "Dot destructor called" << endl;
  }
};

class Cir : public Dot {
private:
  float r;
public:
  Cir(float x, float y, float r)
      : Dot(x, y), r(r) {
    cout << "Cir constructor called" << endl;
      }

  float getArea() {
    return PI * r * r;
  }
  ~Cir(){
    cout << "Cir destructor called" << endl;
  }
};

int main() {
  float x, y, r;
  cin >> x >> y >> r;
  Cir c(x, y, r);
  cout << fixed << setprecision(2) << c.getArea() << endl;
  return 0;
}

