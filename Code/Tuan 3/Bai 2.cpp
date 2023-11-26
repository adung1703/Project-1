#include <bits/stdc++.h>
using namespace std;

int getPushNum(string s) {
	int i;
	while (s[i] != ' ') i++;
	string x = s.substr(i+1, s.length()-i-1);
	return stoi(x);
}

int main(){
	string s;
	queue<int> q;
	getline(cin, s);
	while (s!="#") {
		if (s.substr(0,4) == "PUSH") {
			int n = getPushNum(s);
			q.push(n);
		}
		else if (s.substr(0,3) == "POP") {
			if (q.size() == 0) cout << "NULL" << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		getline(cin, s);
	}
}

