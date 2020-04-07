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
		string startStation = id_map[id].first;//���복վ��
		int checkIn_t = id_map[id].second;//�����ʱ��
		id_map.erase(id);//ɾ��
		double stay_t = t - checkIn_t;//ͣ����ʱ��
		start_end_map[make_pair(startStation, stationName)].first++;//������++
		start_end_map[make_pair(startStation, stationName)].second += stay_t;//��ʱ������

	}

	double getAverageTime(string startStation, string endStation) {
		int total_people = start_end_map[make_pair(startStation, endStation)].first;
		double total_time = start_end_map[make_pair(startStation, endStation)].second;
		return  total_time / total_people;
	}
private:
	//<id, <������վ������ʱ��>>�����ڳ�վ��ѯid�Ǻ�ʱ�Ӻδ�������
	unordered_map<int, pair<string, int>> id_map;
	//<<������վ�����ﳵվ>,<����������ʱ��>>��ע��ʱ����double
	//�����Խ� ������վ�͵��ﳵվ��������Ϊһ���ַ����������Ϳ���ʹ��unordered_map��
	map<pair<string, string>, pair<int, double>> start_end_map;
};

/**
* Your UndergroundSystem object will be instantiated and called as such:
* UndergroundSystem* obj = new UndergroundSystem();
* obj->checkIn(id,stationName,t);
* obj->checkOut(id,stationName,t);
* double param_3 = obj->getAverageTime(startStation,endStation);
*/