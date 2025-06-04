#include <iostream>
using namespace std;

class Time {
private:
    int minute;
    int second;
public:
    Time(){
        minute = 0;
        second = 0;
    }
    Time(int m, int s) : minute(m), second(s) {};

    Time operator++();
    Time operator++(int);
    void display() const {
        cout << minute << " minute(s), " << second << " second(s)" << endl;
    }
};

Time Time::operator++(){
    if (second == 59){
        second = 0;
        minute++;
        return *this;
    }

    second++;
    return *this;

}

Time Time::operator++(int){
    Time temp = *this;
    if (second == 59){
        second = 0;
        minute++;
        return temp;
    }

    second++;
    return temp;
}