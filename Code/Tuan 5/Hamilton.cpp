#include <bits/stdc++.h>
using namespace std;

int hamilton(vector<set<int>> adj, vector<bool> &mark, vector<int> &x, int k, int n, int &res){
	 for (int e : adj[x[k-1]]) {
	 	if (!mark[e]) {
	 		x[k] = e;
	 		mark[e] = 1;
	 		if (k == n && 
			 find(adj[x[1]].begin(), adj[x[1]].end(), e) != adj[x[1]].end()) res = 1;
	 		else hamilton(adj, mark, x, k+1, n, res);
	 		mark[e] = 0;
		 }
	 }
}

int main(){
	int num;
	cin >> num;
	vector<vector<set<int>>> graphs(num);
	for (int i = 0; i < num; i++) {
		int n, m;
		cin >> n >> m;
		graphs[i].resize(n+1);
		for (int j = 0; j < m; j++) {
			int u, v;
			cin >> u >> v;
			graphs[i][u].insert(v);
			graphs[i][v].insert(u);
		}
		vector<bool> mark(n+1);
		vector<int> x(n+1);
		x[1] = 1;
		mark[1] = true;
		int res = 0;
		hamilton(graphs[i], mark, x, 2, n, res);
		cout << res << endl;
	}
	
}

