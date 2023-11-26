#include <bits/stdc++.h>
using namespace std;

int numPeople = 0;
string code, dob, fatherCode, motherCode, isAlive, regionCode, query;
map<string, int> bornAtDate;
map<string, int> bornBetween;
map<string, vector<string>> familyTree;
map<string, bool> alive;

int dfs(const string& person, int generation) {
    int maxGeneration = generation;

    for (const string& ancestor : familyTree[person]) {
        if (alive[ancestor]) {
            maxGeneration = max(maxGeneration, dfs(ancestor, generation + 1));
        }
    }

    return maxGeneration;
}

int main() {
    while (true) {
        cin >> code;
        if (code == "*") break;
        numPeople++;
        cin >> dob >> fatherCode >> motherCode >> isAlive >> regionCode;
        bornAtDate[dob]++;
        bornBetween[dob]++;
        if (isAlive == "Y") alive[code] = true;
        else alive[code] = false;
        familyTree[code].push_back(fatherCode);
        familyTree[code].push_back(motherCode);
    }
    bornBetween["1-1-1"] = 0;
    int prev = 0;
    for (auto &x : bornBetween) {
        x.second += prev;
        prev = x.second;
    }
    while (true) {
        cin >> query;
        if (query == "*") break;
        else if (query == "NUMBER_PEOPLE") cout << numPeople << "\n";
        else if (query == "NUMBER_PEOPLE_BORN_AT") {
            string date;
            cin >> date;
            cout << bornAtDate[date] << "\n";
        } else if (query == "MOST_ALIVE_ANCESTOR") {
            string person;
            cin >> person;
            int result = dfs(person, 0);
            cout << result << "\n";
        } else if (query == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string fromDate, toDate; cin >> fromDate >> toDate;

            auto itTo = bornBetween.lower_bound(toDate);
            auto itFrom = bornBetween.lower_bound(fromDate);

            if (itTo != bornBetween.begin() && itTo->first != toDate) {
                --itTo;
            }

            if (itFrom != bornBetween.begin() && itFrom->first != fromDate) {
                --itFrom;
            }else if (itFrom->first == fromDate) --itFrom;

            int ans = itTo->second - itFrom->second;
            cout << ans << "\n";
        } else if (query == "MAX_UNRELATED_PEOPLE") {
            set<string> s;
            bool check = true;
            for (auto &x : familyTree) {
                for (auto &y : x.second)
                    if (s.count(y)) check = false;
                if (check) s.insert(x.first);
                check = true;
            }
            cout << s.size() << "\n";
        }

    }
}
