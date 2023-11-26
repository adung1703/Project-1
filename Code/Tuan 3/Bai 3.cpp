#include <bits/stdc++.h>
using namespace std;

bool check(string x) {
	if (x.length()%2 != 0) return false;
 	stack<char> s;
	for (int i = 0; i < x.length(); i++) {
		if (x[i] == '(' || x[i] == '[' || x[i] == '{') s.push(x[i]);
		else if (x[i] == ')') {
			if (s.top() == '(') s.pop();
			else return false;
		}
		else if (x[i] == ']') {
			if (s.top() == '[') s.pop();
			else return false;
		}
		else if (x[i] == '}') {
			if (s.top() == '{') s.pop();
			else return false;
		}
	}
	return true;
}

int main(){
	string x;
	getline (cin, x);
	if (check(x)) cout << 1;
	else cout << 0;
}

