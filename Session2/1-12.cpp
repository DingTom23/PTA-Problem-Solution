 #include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Time {
protected:
    int second;
    int minute;
    int hour;
public:
    virtual void operator++() = 0;
    virtual void operator--() = 0;
    virtual int getHour() const = 0;
    virtual int getMinute() const = 0;
    virtual int getSecond() const = 0;
    virtual ~Time() {}
};

class Time_12hours : public Time {
public:
    string type;
    string interval;

    Time_12hours(int h, int m, int s, string interv) {
        hour = h;
        minute = m;
        second = s;
        interval = interv;
        type = "12-hours-time";
    }

    void operator++() override {
        second++;
        if (second >= 60) {
            second = 0;
            minute++;
            if (minute >= 60) {
                minute = 0;
                hour++;
                if (hour >= 12) {
                    hour = 0;
                    interval = (interval == "AM") ? "PM" : "AM";
                }
            }
        }
    }

    void operator--() override {
        second--;
        if (second < 0) {
            second = 59;
            minute--;
            if (minute < 0) {
                minute = 59;
                hour--;
                if (hour < 0) {
                    hour = 11;
                    interval = (interval == "AM") ? "PM" : "AM";
                }
            }
        }
    }

    int getHour() const override { return hour; }
    int getMinute() const override { return minute; }
    int getSecond() const override { return second; }
};

class Time_24hours : public Time {
public:
    string type;

    Time_24hours(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
        type = "24-hours-time";
    }

    void operator++() override {
        second++;
        if (second >= 60) {
            second = 0;
            minute++;
            if (minute >= 60) {
                minute = 0;
                hour++;
                hour %= 24;
            }
        }
    }

    void operator--() override {
        second--;
        if (second < 0) {
            second = 59;
            minute--;
            if (minute < 0) {
                minute = 59;
                hour--;
                if (hour < 0) {
                    hour = 23;
                }
            }
        }
    }

    int getHour() const override { return hour; }
    int getMinute() const override { return minute; }
    int getSecond() const override { return second; }
};

int main() {
    int type;
    while (cin >> type && type != 0) {
        int h, m, s;
        char op;
        int times;
        cin >> h >> m >> s >> op >> times;

        if (type == 121 || type == 122) {
            string interval = (type == 121) ? "AM" : "PM";
            Time_12hours t(h, m, s, interval);
            for (int i = 0; i < times; ++i) {
                if (op == '+') {
                    t.operator++();
                } else {
                    t.operator--();
                }
            }
            cout << t.interval << " "
                 << setw(2) << setfill('0') << t.getHour() << ":"
                 << setw(2) << setfill('0') << t.getMinute() << ":"
                 << setw(2) << setfill('0') << t.getSecond() << endl;
        } else if (type == 24) {
            Time_24hours t(h, m, s);
            for (int i = 0; i < times; ++i) {
                if (op == '+') {
                    t.operator++();
                } else {
                    t.operator--();
                }
            }
            cout << setw(2) << setfill('0') << t.getHour() << ":"
                 << setw(2) << setfill('0') << t.getMinute() << ":"
                 << setw(2) << setfill('0') << t.getSecond() << endl;
        }
    }
    return 0;
}