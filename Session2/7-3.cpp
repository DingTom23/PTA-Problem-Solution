#include <iostream>
using namespace std;

class Complex{
    private:
        double real;
        double image;

    public:
        Complex(double m_real, double m_image){
            real = m_real;
            image = m_image;
        }

        friend Complex comPlus(Complex &c1, Complex &c2);
        friend Complex comPlus2(Complex &c1, Complex &c2);
        
        void Print(){
            cout << "(" << real << ", " << image << ")" << endl;
        }
};

Complex comPlus(Complex &c1, Complex &c2){
    double real = c1.real + c2.real;
    double image = c1.image + c2.image;
    Complex temp(real, image);
    return temp;
}

Complex comPlus2(Complex &c1, Complex &c2){
    double real = c1.real + -c2.real;
    double image = c1.image + -c2.image;
    Complex temp(real, image);
    return temp;
}

int main(){
    double real1, image1;
    double real2, image2;
    cin >> real1 >> image1;
    cin >> real2 >> image2;
    
    Complex c1(real1, image1);
    Complex c2(real2, image2);
    
    Complex cp = comPlus(c1, c2);
    cp.Print();
    
    Complex cp2 = comPlus2(c1, c2);
    cp2.Print();
    c2.Print();
    
    return 0;
}