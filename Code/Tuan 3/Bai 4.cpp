#include <bits/stdc++.h>
using namespace std;

int steps(int a, int b, int c) {
	queue<pair<pair<int, int>, int>> v;
	set<pair<int, int>> visited;
	v.push({{0, 0}, 0});
	
	while (!v.empty()) {
		pair<pair<int, int>, int> cur = v.front();
		int jug1 = cur.first.first;
		int jug2 = cur.first.second;
		int step = cur.second;
		v.pop();
		
		if (jug1 == c || jug2 == c) return step;
		
		if (visited.count({jug1, jug2})) continue;
		visited.insert({jug1, jug2});
		
		v.push({{a, jug2}, step + 1}); // Do day xo 1
		v.push({{jug1, b}, step + 1}); // Do day xo 2
		v.push({{0, jug2}, step + 1}); // Do xo 1 di
		v.push({{jug1, 0}, step + 1}); // Do xo 2 di
		// Do xo 1 vao xo 2
		if ((jug1 + jug2) > b) { 
			v.push({{jug1 - (b - jug2), b}, step + 1});
		} else v.push({{0, jug1+jug2}, step + 1});
		// Do xo 2 vao xo 1
		if ((jug1 + jug2) > a) { 
			v.push({{a, jug1 + jug2 - a}, step + 1});
		} else v.push({{jug1 + jug2, 0}, step + 1});
	}
	return -1;
}

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	cout << steps(a, b, c);
}

