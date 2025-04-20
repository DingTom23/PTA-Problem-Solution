#include <iostream>
#include <vector>

using namespace std;

// 建立结构体，用来保存身体的健康信息
struct Health{
    string name;
    int respiratory_rate;
    int pulse;
};

int main(){

    int N;
    cin >> N;
    vector<Health> Health_data(N);

    // 写入信息
    for (int i = 0; i < N; i++){
        cin >> Health_data[i].name 
        >> Health_data[i].respiratory_rate 
        >> Health_data[i].pulse;
    }

    // 读取信息
    for (int i = 0; i < N; i++){
        if(Health_data[i].respiratory_rate < 15 || Health_data[i].respiratory_rate > 20){
            cout << Health_data[i].name << endl;
        }else if(Health_data[i].pulse > 70 || Health_data[i].pulse < 50){
            cout << Health_data[i].name << endl;
        }
    }
    

    return 0;
}