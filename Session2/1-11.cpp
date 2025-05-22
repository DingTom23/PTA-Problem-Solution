// 我写的一代，有点问题

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    string r, v;
    if (s[0] != '-'){
        if (s.find('i') == string::npos){
            cout << "complex " << s << endl;
            cout << "the real part is " << s << endl;
            cout << "and the imaginary part is " << '0' << endl;
            return 0;
        }
        
        try
        {
            if (s.find('+') != string::npos){ 
                r = s.substr(0, s.find('+')); 
                // substr 就是一种字符串拷贝，类似于切片
                v = s.substr(s.find('+')+1);
                v.pop_back();
            }
            else { 
                r = s.substr(0, s.find('-')); 
                v = s.substr(s.find('-'));
                v.pop_back();
            }
            cout << "complex " << s << endl;
            cout << "the real part is " << r << endl;
            cout << "and the imaginary part is " << v << endl;
        }
        catch(const std::exception& e)
        {
            cout << "complex " << s << endl;
            cout << "the real part is " << '0' << endl;
            if (s[0] == 'i'){} else {s.pop_back();}
            cout << "and the imaginary part is " << s << endl;
            return 0;
        }
        
            
    }else {

        if (s.find('i') == string::npos){
            cout << "complex " << s << endl;
            cout << "the real part is " << s << endl;
            cout << "and the imaginary part is " << '0' << endl;
            return 0;
        }
        try
        {
            s = s.substr(1, s.size());
            if (s.find('+') != string::npos){ 
                r = s.substr(0, s.find('+')); 
                v = s.substr(s.find('+')+1);
                v.pop_back();
            }
            else { 
                r = s.substr(0, s.find('-')); 
                v = s.substr(s.find('-'));
                v.pop_back();
            }
            cout << "complex -" << s << endl;
            cout << "the real part is -" << r << endl;
            cout << "and the imaginary part is " << v << endl;
        }
        catch(const std::exception& e)
        {
            cout << "complex -" << s << endl;
            cout << "the real part is " << '0' << endl;
            if (s[0] == ' '){cout << "and the imaginary part is -i" << endl;} 
            else{s.pop_back();
            cout << "and the imaginary part is -" << s << endl;}
            return 0;
        }
    }
    
    return 0;
}
