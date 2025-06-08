#include <iostream>
using namespace std;

class Student
{
    public:
        Student(int n, int s){
            num = n;
            score = s;
        }
        
        void disp() {
            cout << num << " " << score << endl;
        }
    private:
        int num, score;
};

int main()
{
    Student *p[5];
    for (int i = 0; i < 5; i++)
    {
        int n, s;
        cin >> n >> s;
        p[i] = new Student(n, s);
    }
    for (int i = 0; i < 5; i++)
    {
        p[i]->disp();
    }
    return 0;
}