#include <iostream>
#include <iomanip>
#include <string>
#include <bitset>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    cout << "DEC: " << dec << n << endl;
    cout << "HEX: " << hex << n << endl;
    cout << "OCT: " << oct << n << endl;

    // setbase() 函数只支持 8、10、16 进制
    cout << "HEX: " << setbase(16) << n << endl;
    cout << "BIN(error): " << setbase(2) << n << endl; // 会默认以 10 进制输出
    cout << "BIN: " << bitset<32>(n) << endl;

    string s = "Hello World";
    
    cout << s << endl;
    
    cout << setw(20) << s << endl;
    cout << setfill('*') << setw(20) << s << endl;
    cout << setfill('*') << right << setw(20) << s << endl;
    cout << setfill('*') << left << setw(20) << s << endl;

    double pi = 22.0/7.0;
    
    cout << setiosflags(ios::scientific) << setprecision(5) << pi << endl;
    cout << "pi=" << pi << endl;

    cout << "pi=" << setprecision(2) << pi << endl;

    cout << "pi=" << setiosflags(ios::fixed) << setprecision(5) << pi << endl;

    return 0;
}