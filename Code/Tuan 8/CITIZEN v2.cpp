#include <bits/stdc++.h>
using namespace std;

string code, birth, father, mother, region;
char alive;
int NUMBER_PEOPLE = 0; //for NUMBER_PEOPLE
vector<int> BORN_AT(1116000, 0); //for NUMBER_PEOPLE_BORN_AT
map<pair<string, char>, pair<string, string>> family; //for MOST_ALIVE_ANCESTOR and MAX_UNRELATED_PEOPLE
vector<int> dates(1116000, 0); //for NUMBER_PEOPLE_BORN_BETWEEN

inline int date_to_day(string &day) {
	return stoi(day.substr(0,4))*372 + stoi(day.substr(5,2))*31 + stoi(day.substr(8,2));
}

int ancestor(map<pair<string, char>, pair<string, string>> &family, string &start) {
	int k = 0;
	queue<pair<string, int>> q;
	q.push({start, k});
	while (!q.empty()) {
		string current = q.front().first;
		k = q.front().second;
		q.pop();
		string father = family[{current, 'Y'}].first;
		string mother = family[{current, 'Y'}].second;
		if (father != "0000000") {
			q.push({father, k + 1});
		}
		if (mother != "0000000") {
			q.push({mother, k + 1});
		}
	}
	return k;
}

int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	cin >> code;
	while (code != "*") {
		cin >> birth >> father >> mother >> alive >> region;
		NUMBER_PEOPLE += 1;
		int birth_day = date_to_day(birth);
		BORN_AT[birth_day] += 1;
		family[{code, alive}] = {father, mother};
		dates[birth_day] += 1;
		cin >> code;
	}
	for (int i = 1; i < dates.size(); i++) {
		dates[i] += dates[i-1];
	}
	string query;
	cin >> query;
	while (query != "***") {
		if (query == "NUMBER_PEOPLE") cout << NUMBER_PEOPLE << "\n";
		else if (query == "NUMBER_PEOPLE_BORN_AT") {
			string date;
			cin >> date;
			cout << BORN_AT[date_to_day(date)] << "\n";
		}
		else if (query == "MOST_ALIVE_ANCESTOR") {
			string s;
			cin >> s;
			cout << ancestor(family, s) << "\n";
		}
		else if (query == "NUMBER_PEOPLE_BORN_BETWEEN") {
			string from, to;
			cin >> from >> to;
			int day_from = date_to_day(from);
			int day_to = date_to_day(to);
			if (day_to != 0) cout << dates[day_to] - dates[day_from - 1] << "\n";
			else cout << dates[day_to] << "\n";
		}
		else if (query == "MAX_UNRELATED_PEOPLE") {
			set<string> s;
			for (auto f : family) {
				if (!s.count(f.second.first) && !s.count(f.second.second)) s.insert(f.first.first);
			}
			cout << s.size() << "\n";
		}
		cin >> query;
	}
}

