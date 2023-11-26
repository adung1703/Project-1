#include <bits/stdc++.h>
using namespace std;

int main(){
	set<string> data;
	int n;
	string s;
	cin >> s;
	while (s != "***") {
		if (s != "find" && s != "insert" && s != "*") data.insert(s);
		else if (s == "find") {
			string t;
			cin >> t;
			if (data.find(t) != data.end()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (s == "insert") {
			string t;
			cin >> t;
			if (data.find(t) != data.end()) cout << 0 << endl;
			else {
				cout << 1 << endl;
				data.insert(t);
			}
		}
		cin.ignore();
		cin >> s;
	}
	return 0;
}

