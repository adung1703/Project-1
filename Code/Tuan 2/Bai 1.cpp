#include <bits/stdc++.h>
using namespace std;
long m[1000][1000];

long compute (int k, int n) {
	if (m[k][n] > 0) return m[k][n] % 1000000007;
	else if (m[k][n-1] > 0 && m[k-1][n-1] > 0) {
		m[k][n] = m[k][n-1] + m[k-1][n-1];
		return m[k][n]%1000000007;
	} 
	else if (m[k][n-1] > 0) {
		m[k-1][n-1] = compute(k-1, n-1);
		m[k][n] = m[k][n-1] + m[k-1][n-1];
		return m[k][n]%1000000007;
	}
	else if (m[k-1][n-1] > 0) {
		m[k][n-1] = compute(k, n-1);
		m[k][n] = m[k][n-1] + m[k-1][n-1];
		return m[k][n]%1000000007;
	}
	else {
		m[k-1][n-1] = compute(k-1, n-1);
		m[k][n-1] = compute(k, n-1);
		m[k][n] = m[k][n-1] + m[k-1][n-1];
		return m[k][n]%1000000007;
	}
}
int main(){
	int k, n;
	cin >> k >> n;
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++) {
			if (i == 0 || i == j) m[i][j] = 1;
			else m[i][j] = 0;
		}
	cout << compute(k,n);
}
