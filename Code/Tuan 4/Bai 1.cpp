#include <iostream>
#include <string>
using namespace std;
int hashCode(string s, int m) {
	int len = s.length();
	long pow = 1;
	long sum = 0;
	for (int i = len - 1; i >= 0; i--) {
		sum = (sum + (s[i]*pow)%m) % m;
		pow = pow * 256 % m;
	}
	return sum;
}
int main(){
	string s;
	int n, m;
	cin >> n >> m;
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	s.reserve(200); 
	for (int i = 0; i < n; i++) {
		cin >> s;
		cout << hashCode(s, m) << endl;
	}
}

