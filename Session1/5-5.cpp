#include <string>
#include <iostream>

using namespace std;

int main(){
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    string str = str1 + str2;
    cout << str;
    return 0;
}