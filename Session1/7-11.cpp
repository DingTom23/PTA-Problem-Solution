#include <iostream>
#include <algorithm>

using namespace std;

int min(const int n){
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    return arr[0];
}

int main(){
    int n;
    cin >> n;
    int i = min(n);
    cout << i << endl;

    return 0;
}