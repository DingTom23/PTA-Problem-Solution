#include <iostream>

using namespace std;

static int sum = 0;

int calc(int n){
    if(n == 0){
        return 0;
    }
    sum += n * n;
    calc(n-1);
    return sum;
}

int main(){
    int i;
    cin >> i;
    calc(i);
    cout << sum;
    return 0;
}