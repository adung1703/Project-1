#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;

bool bfs(vector<vector<int>> adj, int s, int t, int pre[]){
	int n = adj.size();
	vector<bool> visited(n, false);
	visited[s] = true;
	pre[s] = -1;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 1; v <= n; v++) { //v la dinh con cua u
			if (adj[u][v] > 0 && !visited[v]) {
				pre[v] = u;
				visited[v] = true;
				if (v == t) return true;
				q.push(v);
			}
		}
	}
	return false;
}

int maxFlow(vector<vector<int>> adj, int s, int t) {
	int max_flow = 0;
	int n = adj.size();
	int pre[n];
	while (bfs(adj, s, t, pre)) {
		int path_flow = INF;
		for (int v = t; v != s; v = pre[v]) {
			path_flow = min (path_flow, adj[pre[v]][v]);
		}
		for (int v = t; v != s; v = pre[v]) {
			adj[pre[v]][v] -= path_flow;
			adj[v][pre[v]] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}

int main(){
	int n, m, s, t;
	cin >> n >> m;
	cin >> s >> t;
	vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u][v] = c;
	}
	
	cout << maxFlow(adj, s, t);
	return 0;
}

