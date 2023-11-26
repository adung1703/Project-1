#include <bits/stdc++.h>
using namespace std;

//struct database{
//	string code;
//	string birth;
//	string father;   
//	string mother;
//	char alive;
//	string region;
//	database(string _code, string _birth, string _father, string _mother, char _alive, string _region) :
//		code(_code), birth(_birth), father(_father), mother(_mother), alive(_alive), region(_region){	}
//};

int ancestor(map<pair<string, char>, pair<string, string>> family, string start) {
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
	string code, birth, father, mother, region;
	char alive;
	int NUMBER_PEOPLE = 0; //for NUMBER_PEOPLE
	map<string, int> BORN_AT; //for NUMBER_PEOPLE_BORN_AT
	map<pair<string, char>, pair<string, string>> family; //for MOST_ALIVE_ANCESTOR and MAX_UNRELATED_PEOPLE
	vector<string> dates; //for NUMBER_PEOPLE_BORN_BETWEEN
	
	cin >> code;
	while (code != "*") {
		cin >> birth >> father >> mother >> alive >> region;
		NUMBER_PEOPLE++;
		BORN_AT[birth]++;
		family[{code, alive}] = {father, mother};
		dates.push_back(birth);
		cin >> code;
	}
	string query;
	cin >> query;
	while (query != "***") {
		if (query == "NUMBER_PEOPLE") cout << NUMBER_PEOPLE << "\n";
		else if (query == "NUMBER_PEOPLE_BORN_AT") {
			string date;
			cin >> date;
			cout << BORN_AT[date] << "\n";
		}
		else if (query == "MOST_ALIVE_ANCESTOR") {
			string s;
			cin >> s;
			cout << ancestor(family, s) << "\n";
		}
		else if (query == "NUMBER_PEOPLE_BORN_BETWEEN") {
			string from, to;
			cin >> from >> to;
			int people = 0;
			for (string d : dates) {
				if (d >= from && d <= to) people++;
			}
			cout << people << "\n";
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

