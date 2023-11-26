#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a;
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (s.find(a) != s.end()) { //Neu tim thay
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
			s.insert(a);
		}
	}
	
}

