#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imag;
public:
    Complex() : real(0), imag(0) {};
    Complex(int r) : real(r), imag(0) {}; // convert int to Complex
    Complex(int r, int i) : real(r), imag(i) {};
    
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);

    operator int() const {
        return real;
    }
};

ostream& operator<<(ostream& os, const Complex& c) {
    
    if (c.imag < 0) {
        os << c.real << c.imag << "i";
    } else if (c.imag == 0) {
        os << c.real;
    } else {
        os << c.real << "+" << c.imag << "i";
    }
    
    return os;
}

istream& operator>>(istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}

