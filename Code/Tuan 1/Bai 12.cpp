//C/C++ 
#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
	int n, k, a[n], q=0, weight = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];	
	}
	for (int i = 0; i < k; i++) {
		weight += a[i];
	}
	if (weight%2 == 0) q++;
	for (int i = 0; i < n-k; i++) {
		weight = weight - a[i] + a[i+k];
		if (weight%2 == 0) q++;		
	}
	cout << q;
}
