#include <string>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

class UndergroundSystem {
public:
	UndergroundSystem() {

	}

	void checkIn(int id, string stationName, int t) {
		id_map[id] = make_pair(stationName, t);
	}

	void checkOut(int id, string stationName, int t) {
		string startStation = id_map[id].first;//进入车站名
		int checkIn_t = id_map[id].second;//进入的时间
		id_map.erase(id);//删除
		double stay_t = t - checkIn_t;//停留的时间
		start_end_map[make_pair(startStation, stationName)].first++;//总人数++
		start_end_map[make_pair(startStation, stationName)].second += stay_t;//总时间增加

	}

	double getAverageTime(string startStation, string endStation) {
		int total_people = start_end_map[make_pair(startStation, endStation)].first;
		double total_time = start_end_map[make_pair(startStation, endStation)].second;
		return  total_time / total_people;
	}
private:
	//<id, <出发车站，出发时间>>，用于出站查询id是何时从何处进来的
	unordered_map<int, pair<string, int>> id_map;
	//<<出发车站，到达车站>,<总人数，总时间>>，注意时间用double
	//还可以将 出发车站和到达车站合起来作为一个字符串，这样就可以使用unordered_map了
	map<pair<string, string>, pair<int, double>> start_end_map;
};

/**
* Your UndergroundSystem object will be instantiated and called as such:
* UndergroundSystem* obj = new UndergroundSystem();
* obj->checkIn(id,stationName,t);
* obj->checkOut(id,stationName,t);
* double param_3 = obj->getAverageTime(startStation,endStation);
*/