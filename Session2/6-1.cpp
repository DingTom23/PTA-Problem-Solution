#include <iostream>
using namespace std;

class Car{
    private:
        int m_nWheels;
    public:
        Car(){
            m_nWheels = 0;
        }

        void disp_welcomemsg(){
            cout << "Welcome to the car world!" << endl;
        }

        void set_wheels(int n){
            m_nWheels = n;
        }

        int get_wheels(){
            return m_nWheels;
        }
};

int main(){

    int n;
    cin >> n;
    Car myfstcar, myseccar;
    myfstcar.disp_welcomemsg();
    myfstcar.set_wheels(n);
    myseccar.set_wheels(n+4);

    cout << "my first car wheels num = " << myfstcar.get_wheels() << endl;
    cout << "my second car wheels num = " << myseccar.get_wheels();

    return 0;
}