#include <bits/stdc++.h>
using namespace std;

void bfs(vector<set<int>> adj, int u, vector<bool> &visited){
	queue<int> q;
	q.push(u);
	while (!q.empty()) {
		int currentV = q.front();
		q.pop();
		
		if(visited[currentV]) continue;
		cout << currentV <<" ";
		visited[currentV] = true;
		for(int V : adj[currentV]) {
			if(!visited[V]) {
				q.push(V);
			}
		}
	}
	for (int i = 1; i < visited.size(); i++) {
		if(!visited[i]) bfs(adj, i, visited);
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<set<int>> adj(n+1);
	for (int i = 0; i < m; i++)	 {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	vector<bool> visited(adj.size());
	bfs(adj, 1, visited);
	return 0;
}

