#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

int timeToSecond(string time) {
	return stoi(time.substr(0, 2)) * 3600 + stoi(time.substr(3, 2)) * 60 + stoi(time.substr(6, 2));
}

int main(){
	struct order{
		int price;
		int time;
		order (int _price, int _time): 
		price(_price), time(_time){};
	};
	
	int num_orders = 0;
	int total_revenue = 0;
	map<string, int> revenue_of;
	map<pair<string, string>, int> consume;
	vector<order> orders;
	
	string cid, pid, shopid, time;
	int price;
	cin >> cid;
	while (cid != "#") {
		cin >> pid >> price >> shopid >> time;
		num_orders++;
		total_revenue += price;
		revenue_of[shopid] += price;
		consume[{cid, shopid}] += price;
		int time_second = timeToSecond(time);
		orders.push_back(order(price, time_second));
		cin >> cid;
	}
	
	string query;
	cin >> query;
	while(query != "#") {
		if (query == "?total_number_orders") cout << num_orders << "\n";
		else if (query == "?total_revenue") cout << total_revenue << "\n";
		else if (query == "?revenue_of_shop") {
			string sid;
			cin >> sid;
			cout << revenue_of[sid] << "\n";
		}
		else if (query == "?total_consume_of_customer_shop") {
			string cid, sid;
			cin >> cid >> sid;
			cout << consume[{cid, sid}] << "\n";
		}
		
		else if (query == "?total_revenue_in_period") {
			int result = 0;
			string from, to;
			cin >> from >> to;
			int from_second = timeToSecond(from);
			int to_second = timeToSecond(to);
			for (struct order i : orders) {
				if (i.time >= from_second && i.time <= to_second) result += i.price;
			}
			cout << result << "\n";
		}
		cin >> query;
	}
}
