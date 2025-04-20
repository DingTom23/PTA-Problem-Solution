#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

static char arr[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
static double weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

// 判断是否是数字
bool isDi(string str) {
    for (int i = 0; i < 17; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// 判断数组的每个元素是不是数字正确的
vector<bool> isDiStr(vector<string> id) {
    vector<bool> key(id.size(), false);
    for (int i = 0; i < id.size(); i++) {
        key[i] = isDi(id[i]);
    }
    return key;
}


bool checkCheck(string id){
    int s = 0;
    for (int i = 0; i < 17; i++){
        int num;
        if(id[i] == 'X'){
            num = 10 * weight[i];
        }else{
            num = (id[i] - '0') * weight[i];
        }
        s += num;
    }

    int check = s % 11;
    return (id[17] == arr[check]);
}

// 判断格式是否正确
void isPass(vector<string> id, const int N){
    bool check = true;
    vector<bool> pass = isDiStr(id);
    for (int i = 0; i < N; i++){
        if (pass[i]){
            if(!checkCheck(id[i])){
                pass[i] = false;
            }
        }

        if (!pass[i]){
            cout << id[i] << endl;
            check = false;
        }
    }

    if (check){
        cout << "All passed";
    }
}

int main() {
    int N;
    cin >> N;
    
    cin.get();

    vector<string> id(N);
    for (int i = 0; i < N; i++) {
        getline(cin, id[i]);
    }

    // 执行验证
    isPass(id,N);
    return 0;
}