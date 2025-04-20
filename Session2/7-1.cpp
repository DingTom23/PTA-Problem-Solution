/*
7-1 宿舍谁最高？
学校选拔篮球队员，每间宿舍最多有 4 个人。现给出宿舍列表，请找出每个宿舍最高的同学。定义一个学生类 Student，有身高 height，体重 weight 等。

输入格式:
首先输入一个整型数 n （1≤n≤10^6），表示有 n 位同学。 

紧跟着 n 行输入，每一行格式为：宿舍号 name height weight。
宿舍号的区间为 [0, 999999]， name 由字母组成，长度小于 16，height，weight 为正整数。  

输出格式:
按宿舍号从小到大排序，输出每间宿舍身高最高的同学信息。题目保证每间宿舍只有一位身高最高的同学。

注意宿舍号不足 6 位的，要按 6 位补齐前导 0。

输入样例:
7
000000 Tom 175 120
000001 Jack 180 130
000001 Hale 160 140
000000 Marry 160 120
000000 Jerry 165 110
000003 ETAF 183 145
000001 Mickey 170 115

输出样例:
000000 Tom 175 120
000001 Jack 180 130
000003 ETAF 183 145

*/

#include <iostream>
#include <vector>

using namespace std;

class Student {
    public:
        friend void Asort(int n, vector<Student> &data);
        friend vector<Student> Bsort(int n, vector<Student> &data);
        void input(){
            cin >> ID >> name >> height >> weight;
        }
        void output(){
            cout.width(6);
            cout.fill('0');
            cout << ID << ' ' << name << ' ' << height << ' ' << weight << endl;
        }
        int ID;
    private:
        string name;
        int height;
        int weight;
};

void Asort(int n, vector<Student> &data) {
    for (int i = 1; i < n; i++) {
        Student key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].ID > key.ID) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

vector<Student> Bsort(int n, vector<Student> &data) {
    for (int i = 1; i < n; i++) {
        Student key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].ID == key.ID && data[j].height < key.height) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
    return data;
}

int main(){
    int n;
    cin >> n;
    vector<Student> data(n);
    for (int i = 0; i < n; i++){
        data[i].input();
    }

    Asort(n, data);
    data = Bsort(n, data);
    for (int i = 0; i < n; i++){
        if (i > 0 && data[i].ID == data[i - 1].ID) continue;
        data[i].output();
    }
    return 0;
}