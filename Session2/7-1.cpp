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