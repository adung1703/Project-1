#include <bits/stdc++.h>
using namespace std;

int inspect_cycle(map<string, vector<string>> inspect, string acc1, string acc2, int k, set<string>& visited){
	if (k < 0) return 0;
	if (k == 0) {
		if (acc1 != acc2) return 0;
		else return 1;
	}
	if (visited.find(acc1) != visited.end()) return 0;
	for (int i = 0; i < inspect[acc1].size(); i++) {
		string curAcc = inspect[acc1][i];
		if (visited.find(curAcc) != visited.end()) continue;
		map<string, vector<string>> current = inspect;
		current[acc1].erase(current[acc1].begin()+i);
		visited.insert(curAcc);
		if (inspect_cycle(current, curAcc, acc2, k-1, visited) == 1) return 1;
		visited.erase(curAcc);
	}
	return 0;
}


int main(){
	int number_transactions = 0;
	int total_money_transaction = 0;
	set<string> accounts;
	map<string, int> transaction_from;
	map<string, vector<string>> inspect;
	string acc1, acc2, time, atm;
	int money;
	cin >> acc1;
	while (acc1 != "#") { 
		cin >> acc2 >> money >> time >> atm;
		number_transactions++;
		total_money_transaction += money;
		accounts.insert(acc1);
		accounts.insert(acc2);
		transaction_from[acc1] += money;
		inspect[acc1].push_back(acc2);
		cin >> acc1;
	} 
	
	string query;
	cin >> query;
	
	while (query != "#") {
		if (query == "?number_transactions") cout << number_transactions << "\n";
		else if (query == "?total_money_transaction") cout << total_money_transaction << "\n";
		else if (query == "?list_sorted_accounts") {
			for (string acc : accounts) cout << acc << " ";
			cout << "\n";
		}
		else if (query == "?total_money_transaction_from") {
			string acc;
			cin >> acc;
			cout << transaction_from[acc] << "\n";
		}
		else if (query == "?inspect_cycle") {
			string acc;
			int k;
			cin >> acc >> k;
			set<string> visited;
			cout << inspect_cycle(inspect, acc, acc, k, visited) << "\n";
		}
		cin >> query;
	}
	return 0;
}

