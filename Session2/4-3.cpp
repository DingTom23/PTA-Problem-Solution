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

/*
"最近世界不太平啊！"胸怀世界、心系人类的我注视着桌面上的世界地图不禁感慨。现代战争，空军先行。我仿佛看到各国空军化作粗大的箭头在地图运动，Moscow、Kyiv、Paris、London、New York……向这些地点发动空袭（口误）我是说，运送人道主义救援物资……要飞多远呢？显然不能在三维空间划直线，那样会钻到地球里面去的。

一番搜索后我找到了球面余弦公式，已知两点的经纬度可以算出对地心的夹角，再配合地球半径就能算出大圆航线上的最短距离。

已知两地纬度alat, blat、经度alng， blng，那么两地与地心所成的球面角：
= ArcCos(Sin(alat) * Sin(blat) + Cos(alat) * Cos(blat) * Cos(alng - blng)) 单位是弧度。
地球当成个理想的圆球，半径按6378.1公里算。
于是最短距离对应的圆弧长等于弧度乘以半径。
我准备找些大城市的经纬度来计算下，看看和航空里程数据差多少。可惜网上找到的是份CSV的数据，里面有些无用的列。还得写个程序从里面过滤出城市名称和经纬度来。

输入规格
数据前面部分是CSV格式的城市数据，首行是标题，说明各列的含义。
经度范围是正负180，纬度范围正负90，单位是角度。
CSV数据到=====（5个等号）行为止。我想最多也就二百多个城市。
后续测试数据部分每行为一组：有两个城市的名称，用,隔开（城市名称可能有空格或连字符但没有逗号）。读取到EOF为止。数量较多，请逐行计算并输出。
输出规格
对每组测试数据，计算两城市间最短的飞行距离并输出一行结果（保留1位小数）。

样例输入
city_ascii,lat,lng,iso2,iso3,population
San Salvador,13.6989,-89.1914,SV,SLV,567698
Jakarta,-6.2146,106.8451,ID,IDN,34540000
Port-au-Prince,18.5425,-72.3386,HT,HTI,987310
Tokyo,35.6897,139.6922,JP,JPN,37977000
Maputo,-25.9153,32.5764,MZ,MOZ,1191613
=====
Tokyo,Jakarta
Jakarta,Tokyo
Maputo,Maputo
样例输出
5792.5
5792.5
0.0
样例解释
两城市间的距离应该是对称的。
可能有多余的城市数据，如"San Salvador"。
列的数量和顺序是固定的（废话，CSV文件都下载好了）。虽然有些列用不上，如iso2/population等。
另外，俄罗斯看起来好宽，东西跨度足有中国的三倍，真是这样吗？
补充了Maputo同城的情况，在GCC、VC结果不同，直接计算可能由于浮点误差导致NaN。
*/
