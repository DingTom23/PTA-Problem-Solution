#include <iostream>
#include <string>
using namespace std;

int main(){
    int i = 0;
    string str;
    getline(cin, str);

    char ch;
    cin >> ch;

    for(char v_ch : str){
        if(v_ch == ch){
            i++;
        }
    }

    cout << i;
    return 0;
}