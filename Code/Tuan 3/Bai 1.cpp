#include <bits/stdc++.h>
using namespace std;
int getPushNum(string s) {
	int i = 0;
	while (s[i] != ' ') i++;
	string x = s.substr(i+1,s.length()-i-1);
	return stoi(x);
}
int main(){
	vector<int> v;
	string s;	
	getline(cin, s);
	while (s != "#") {
		if (s.substr(0,4) == "PUSH") {
			int n = getPushNum(s);
			v.push_back(n);
		} else if (s.substr(0,3) == "POP") {
			if (v.size() == 0) cout << "NULL" << endl;
			else {
				int n = v.back();
				v.pop_back();
				cout << n << endl;
			}
		}
//		cin.ignore();
		getline(cin, s);
	}
	return 0;
}

