#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

struct City {
    double lat, lng;
};

const double EARTH_RADIUS = 6378.1;
const double PI = acos(-1.0);

// 角度转弧度
double toRadians(double degrees) {
    return degrees * PI / 180.0;
}

// 计算两城市间的球面距离
double calculateDistance(const City& a, const City& b) {
    // 如果是同一个城市，直接返回0
    if (abs(a.lat - b.lat) < 1e-9 && abs(a.lng - b.lng) < 1e-9) {
        return 0.0;
    }
    
    double alat = toRadians(a.lat);
    double blat = toRadians(b.lat);
    double alng = toRadians(a.lng);
    double blng = toRadians(b.lng);
    
    // 球面余弦公式
    double cosAngle = sin(alat) * sin(blat) + cos(alat) * cos(blat) * cos(alng - blng);
    
    // 防止浮点误差导致的NaN
    if (cosAngle > 1.0) cosAngle = 1.0;
    if (cosAngle < -1.0) cosAngle = -1.0;
    
    double angle = acos(cosAngle);
    return angle * EARTH_RADIUS;
}

// 解析CSV行
vector<string> parseCSVLine(const string& line) {
    vector<string> result;
    stringstream ss(line);
    string field;
    
    while (getline(ss, field, ',')) {
        result.push_back(field);
    }
    return result;
}

int main() {
    map<string, City> cities;
    string line;
    
    // 跳过标题行
    getline(cin, line);
    
    // 读取城市数据
    while (getline(cin, line) && line != "=====") {
        vector<string> fields = parseCSVLine(line);
        if (fields.size() >= 3) {
            string cityName = fields[0];
            double lat = stod(fields[1]);
            double lng = stod(fields[2]);
            cities[cityName] = {lat, lng};
        }
    }
    
    // 处理查询
    while (getline(cin, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != string::npos) {
            string city1 = line.substr(0, commaPos);
            string city2 = line.substr(commaPos + 1);
            
            if (cities.find(city1) != cities.end() && cities.find(city2) != cities.end()) {
                double distance = calculateDistance(cities[city1], cities[city2]);
                cout << fixed << setprecision(1) << distance << endl;
            }
        }
    }
    
    return 0;
}
