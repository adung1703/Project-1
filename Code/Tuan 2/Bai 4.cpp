#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &v){
	do {
		for (int i = 0; i < v.size(); i++) {
			if (i!=0) cout << " ";
			cout << v[i];
		}
		cout << endl;
	} while (next_permutation(v.begin(),v.end()));
}


int main(){
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 1; i <= n; i++) v.push_back(i);
	f(v);
}

