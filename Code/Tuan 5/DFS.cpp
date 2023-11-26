#include <bits/stdc++.h>
using namespace std;
void dfs(vector<set<int>> adj) {
	int currentV;
	stack<int> s;
	vector<bool> visited(adj.size());
	s.push(1);
	
	while (!s.empty()) {
		currentV = s.top();
		s.pop();
		if (!visited[currentV]) {
			cout << currentV << " ";
			visited[currentV] = true;
			
			stack<int> s1;
			for (int i : adj[currentV]) {
				if (!visited[i]) s1.push(i);
			}
			
			while(!s1.empty()) {
				s.push(s1.top());
				s1.pop();
			}
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<set<int>> adj;
	adj.resize(n+1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	dfs(adj);
}

