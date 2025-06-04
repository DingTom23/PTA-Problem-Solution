#include <iostream>
#include "time.h"

using namespace std;

int main(){
    Time t1(34, 59);
    cout << "t1 = ";
    t1.display();
    cout << "++t1 = ";
    (++t1).display();
    cout << "t1++ = ";
    (t1++).display();
    cout << "t1 = ";
    t1.display();
    return 0; // end of main()
}