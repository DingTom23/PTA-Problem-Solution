#include <iostream>
#include <iomanip>
using namespace std;

struct scroces
{
    double ch;
    double mt;
    double en;
};

int main(){
    scroces std[6];

    for (int i = 0; i < 6; i++){
        cin >> std[i].ch;
    }

    for (int i = 0; i < 6; i++){
        cin >> std[i].mt;
    }

    for (int i = 0; i < 6; i++){
        cin >> std[i].en;
    }

    double sum_ch = 0, sum_mt = 0, sum_en = 0;
    for (int i = 0; i < 6; i++){
        sum_ch += std[i].ch;
        sum_mt += std[i].mt;
        sum_en += std[i].en;
    }

    double av_ch = sum_ch / 6.0;
    double av_mt = sum_mt / 6.0;
    double av_en = sum_en / 6.0;

    cout << setiosflags(ios::fixed) 
    << setprecision(2) 
    << av_ch 
    << ' ' 
    << av_mt 
    << ' ' 
    << av_en 
    << ' ' 
    << endl;

    double an_std[6];

    for (int i = 0; i < 6; i++){
        double sum = 0;
        sum += std[i].ch + std[i].mt + std[i].en;
        an_std[i] = sum / 3.0;
    }

    for (int i = 0; i < 6;i++){
        cout << setiosflags(ios::fixed) 
        << setprecision(2) 
        << an_std[i] 
        << ' ';
    }

    return 0;
}