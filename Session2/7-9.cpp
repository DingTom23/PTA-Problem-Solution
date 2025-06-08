#include <iostream>
using namespace std;

class Complex
{
    public:
        Complex(int r, int i){
            Real = r;
            Imag = i;
        }
        void disp()
        {
            cout << "(" << Real << "," << Imag << "i)" << endl;
        }
        void disp() const
        {
            cout << "[" << Real << "," << Imag << "j]" << endl;
        }
    private:
        int Real, Imag;
};

int main()
{

    int a, b;
    cin >> a >> b;
    Complex A(a, b);
    A.disp();
    int c, d;
    cin >> c >> d;
    const Complex B(c,d);
    B.disp();
    return 0;
}