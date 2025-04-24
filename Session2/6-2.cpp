#include<iostream>
#include<cstring>
using namespace std;
class Stud{
    public:
        Stud(int no,const char* n, double s){
            No = no;
            strcpy(name, n);
            score = s;
            sum += score;
            num++;
        }
    void disp(){
        
    }

    static double avg(){
        return sum / num;
    }
    private:
        int No;
        char name[50];
        double score;
        static double sum;
        static int num;
};
double Stud::sum=0;
int Stud::num=0;
int main()
{
    int No,n;
    cin>>n;
    char name[50];
    double score;
    while(n--){
        cin>>No;
        cin>>name;
        cin>>score;
        Stud stu(No,name,score);
        stu.disp();
    }
    printf("avg=%.2lf\n",Stud::avg());
    return 0;
}

