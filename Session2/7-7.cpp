#include <iostream>
using namespace std;

class Student {
private:
    int score;
    static int total_score;
    static int count;

public:
    Student(int s) : score(s) {
        total_score += s;
        count++;
    }

    static int getTotal() {
        return total_score;
    }

    static double getAverage() {
        if (count == 0) return 0;
        return static_cast<double>(total_score) / count;
    }
};

int Student::total_score = 0;
int Student::count = 0;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int score;
        cin >> score;
        Student stu(score);
    }
    cout << Student::getTotal() << endl;
    cout << Student::getAverage() << endl;
    return 0;
}