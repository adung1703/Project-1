#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, a, sum = 0;
	cin >> n >> m;
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (s.find(m-a) != s.end()) sum ++;
		s.insert(a);
	}
	cout << sum;
	return 0;
}

