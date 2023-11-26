#include <bits/stdc++.h>
using namespace std;

string code, birth, father, mother, region;
char alive;
int NUMBER_PEOPLE = 0; //for NUMBER_PEOPLE
vector<int> BORN_AT(1116000, 0); //for NUMBER_PEOPLE_BORN_AT
map<string, pair<string, string>> family; //for MOST_ALIVE_ANCESTOR and MAX_UNRELATED_PEOPLE
map<string, bool> Alive;
vector<int> dates(1116000, 0); //for NUMBER_PEOPLE_BORN_BETWEEN

inline int date_to_day(string &day) {
	return stoi(day.substr(0,4))*372 + stoi(day.substr(5,2))*31 + stoi(day.substr(8,2));
}

int ancestor(string &start, int k) {
    string father = family[start].first;
    string mother = family[start].second;
    int result = k;
    int length_father = 0;
    int length_mother = 0;
    if (Alive[father]) {
        length_father = ancestor(father, k+1);
    }
    if (length_father > result) result = length_father;
    if (Alive[mother]) {
        length_mother = ancestor(mother, k+1);
    }
    if (length_mother > result) result = length_mother;
    return result;
}


int main(){
	
	cin >> code;
	while (code != "*") {
		cin >> birth >> father >> mother >> alive >> region;
		NUMBER_PEOPLE += 1;
		int birth_day = date_to_day(birth);
		BORN_AT[birth_day] += 1;
		family[code] = {father, mother};
		if (alive == 'Y') Alive[code] = true;
		dates[birth_day] += 1;
		cin >> code;
	}
	
	int at = 0;
	for (int i = 0; i < dates.size(); i++) {
		dates[i] += at;
		at = dates[i];
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
			cout << ancestor(s, 0) << "\n";
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
			for (auto &f : family) {
				if (!s.count(f.second.first) && !s.count(f.second.second)) s.insert(f.first);
			}
			cout << s.size() << "\n";
		}
		cin >> query;
	}
}

