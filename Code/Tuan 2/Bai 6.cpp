#include <bits/stdc++.h>
using namespace std;

void f(int k, int M, vector<int> &v) {
	if(k == 0) {
		if (M == 0) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= M - k + 1; i++) {
		v.push_back(i);
		f(k-1, M-i, v);
		v.pop_back();
	}
}
int main(){
	int n, M;
	vector<int> v;
	cin >> n >> M;
	f(n, M, v);
}

