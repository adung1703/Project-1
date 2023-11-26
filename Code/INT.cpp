#include <bits/stdc++.h>
using namespace std;

int increase (int n) {
	bool check = true;
	int a[100];
	int i = 0;
	int k = n;
	while (k != 0) {
		a[i] = k%10;
		k /= 10;
		i++;
	}
	for (int j = 0; j < i-1; j++) {
		if (a[j] < a[j+1]) {
			check = false;
			break;
		}
	}
	if (check) return n;
	else increase(n+1);
}

int main(){
	cout << increase (103);
}

