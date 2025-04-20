#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int N;
    cin >> N;
    for (int i = 1; i < N; i++){
        for (int j = 1; j <= i; j++){
            cout << j << '*' << i << '=' << setw(4) << left << i * j;
            // 这个地方要左对齐
        }
        cout << endl;
    }
    return 0;
}