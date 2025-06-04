#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Date
{
protected:
  int year;
  int month;
  int day;
};

class Time
{
protected:
  int hour;
  int minute;
  int second;
};

class Schedule : public Date, public Time
{
public:
  Schedule(int mID, const string &mDate, const string &mTime) : ID(mID)
  {

    size_t pos1 = mDate.find('/');
    size_t pos2 = mDate.find('/', pos1 + 1);
    year = stoi(mDate.substr(0, pos1)); // stoi: string 转 int / atoi 也是转换但是无视长度限制
    // 类似会有 to_string() int 转 string 都在 cstring.h 里面
    month = stoi(mDate.substr(pos1 + 1, pos2 - pos1 - 1));
    day = stoi(mDate.substr(pos2 + 1));

    size_t tpos1 = mTime.find(':');
    size_t tpos2 = mTime.find(':', tpos1 + 1);
    hour = stoi(mTime.substr(0, tpos1));
    minute = stoi(mTime.substr(tpos1 + 1, tpos2 - tpos1 - 1));
    second = stoi(mTime.substr(tpos2 + 1));
  }

  bool operator<(const Schedule &s2) const
  {
    if (year != s2.year)
      return year < s2.year;
    if (month != s2.month)
      return month < s2.month;
    if (day != s2.day)
      return day < s2.day;
    if (hour != s2.hour)
      return hour < s2.hour;
    if (minute != s2.minute)
      return minute < s2.minute;
    return second < s2.second;
  }

  int getID() const { return ID; }
  int getYear() const { return year; }
  int getMonth() const { return month; }
  int getDay() const { return day; }
  int getHour() const { return hour; }
  int getMinute() const { return minute; }
  int getSecond() const { return second; }

private:
  int ID;
};

int main()
{
  int id;
  Schedule *earliest = nullptr;

  while (cin >> id && id != 0)
  {
    string date, time;
    cin >> date >> time;
    Schedule s(id, date, time);

    if (!earliest || s < *earliest)
    {
      if (earliest)
        delete earliest;
      earliest = new Schedule(s);
    }
  }

  if (earliest)
  {
    cout << "The urgent schedule is No." << earliest->getID() << ": "
         << earliest->getYear() << "/" << earliest->getMonth() << "/" << earliest->getDay() << " "
         << earliest->getHour() << ":" << earliest->getMinute() << ":" << earliest->getSecond() << endl;
    delete earliest;
  }

  return 0;
}

/*
-----
s.find(str)

string s, c;
int main() {
  s = "apple";
  c = "l";
  int index = s.find(c);
  if (index != string::npos)
    cout << index << endl;
}

3

-----
s.find(str, pos)

string s, c;
int main() {
  s = "laaaal";
  c = "l";
  int index = s.find(c,3); // 从字符串s下标3的位置开始寻找
  if (index != string::npos) // npos表示size_t的最大值
  cout << index << endl;
}

-----
s.find_first_of(str) / s.find_last_of(str)

string s, c;
int main() {
  s = "laaaal";
  c = "l";
  cout << "first index:" << s.find_first_of(c) << endl;
  cout << "last index:" << s.find_last_of(c) << endl;
}

first index:0
last index:5

-----
string s, c;

int main() {
  while (cin >> s >> c) {
    int index = 0; // 用来存储不断更新最新找到的位置
    int sum = 0; // 累加出现的次数
    while ((index = s.find(c,index)) != string::npos) {
      cout << "sum: " << sum+1 << " index: " << index <<endl;
      index += c.length(); // 上一次s中与c完全匹配的字符应跳过，不再比较
      sum++;
    }
    cout << sum << endl;
  }
}

llllll
ll
sum: 1 index: 0
sum: 2 index: 2
sum: 3 index: 4
3

-----
s.rfind(str)

string s = "apple";
cout << s.rfind("l") << endl;

3

*/