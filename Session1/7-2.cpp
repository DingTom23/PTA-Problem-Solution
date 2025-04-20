#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
	string year_str;
	cin >> year_str;

	
	if (year_str.length() != 4) {
		cout << "输入数据类型错误，请重新输入:\n";
		return 0;
	}
	int year;

	try {
		int year = stoi(year_str);
	}
	catch (...) {
		cout << "输入数据类型错误，请重新输入:\n";
	}

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		cout << year << "是闰年";
	}else {
		cout << year << "不是闰年";
	}

	return 0;
}