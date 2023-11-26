#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int num_orders = 0; //for ?total_number_orders
	int total_revenue = 0; // for ?total_revenue
	vector<pair<string, pair<string, int>>> order; //cid, shopid, price
	vector<pair<string, int>> revenue_in; //for ?total_revenue_in_period
	
	string cid, pid, shopid, time;
	int price;
	cin >> cid;
	while (cid != "#") {
		cin >> pid >> price >> shopid >> time;
		num_orders++;
		total_revenue += price;
		order.push_back({cid, {shopid, price}});
		revenue_in.push_back({time, price});
		cin >> cid;
	}
	
	string query;
	cin >> query;
	while(query != "#") {
		if (query == "?total_number_orders") cout << num_orders << "\n";
		else if (query == "?total_revenue") cout << total_revenue << "\n";
		else if (query == "?revenue_of_shop") {
			int revenue_of = 0;
			string sid;
			cin >> sid;
			for (pair<string, pair<string, int>> i : order) {
				if (i.second.first == sid) revenue_of += i.second.second;
			}
			cout << revenue_of << "\n";
		}
		else if (query == "?total_consume_of_customer_shop") {
			int result = 0;
			string cid, sid;
			cin >> cid >> sid;
			for (pair<string, pair<string, int>> i : order) {
				if (i.first == cid && i.second.first == sid)  
					result += i.second.second;
			}
			cout << result << "\n";
		}
		
		else if (query == "?total_revenue_in_period") {
			int result = 0;
			string from, to;
			cin >> from >> to;
			for (pair<string, int> i : revenue_in) {
				if (i.first >= from && i.first <= to) result += i.second;
			}
			cout << result << "\n";
		}
		cin >> query;
	}
}

