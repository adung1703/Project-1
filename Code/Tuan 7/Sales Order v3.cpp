#include <bits/stdc++.h>
using namespace std;

int timeToSecond(string time) {
	return stoi(time.substr(0, 2)) * 3600 + stoi(time.substr(3, 2)) * 60 + stoi(time.substr(6, 2));
}

int main(){
	int num_orders = 0;
	int total_revenue = 0;
	unordered_map<string, int> revenue_of;
	unordered_map<string, int> consume;
	vector<int> revenueInTime(86400, 0);
	
	string cid, pid, shopid, time;
	int price;
	cin >> cid;
	while (cid != "#") {
		cin >> pid >> price >> shopid >> time;
		num_orders++;
		total_revenue += price;
		revenue_of[shopid] += price;
		consume[cid + shopid] += price;
		revenueInTime[timeToSecond(time)] += price;
		cin >> cid;
	}
	
	for (int i = 1; i < 86400; i++) revenueInTime[i] += revenueInTime[i-1];
	
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
			cout << consume[cid + sid] << "\n";
		}
		
		else if (query == "?total_revenue_in_period") {
			int result = 0;
			string from, to;
			cin >> from >> to;
			int second_from = timeToSecond(from);
			int second_to = timeToSecond(to);
			if (second_from != 0) result = revenueInTime[second_to] - revenueInTime[second_from - 1];
			else result = revenueInTime[second_to];
			cout << result << "\n";
		}
		cin >> query;
	}
}
