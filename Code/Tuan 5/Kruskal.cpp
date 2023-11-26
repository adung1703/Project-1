#include <bits/stdc++.h>
using namespace std;

struct edge{
	int u;
	int v;
	int w;
};

struct DisjointSetUnion {
    vector<int> par;

    void init(int n) {
        par.resize(n + 5, 0);
        for (int i = 1; i <= n; i++) par[i] = i;
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        par[v] = u;
        return true;
    }
} disjoint;

int main(){
	int n, m;
	cin >> n >> m;
	int res = 0;
	vector<edge> edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		int w;
		cin >> u >> v >> w;
		struct edge e;
		e.u = u;
		e.v = v;
		e.w = w;
		edges.push_back(e);
	}
	disjoint.init(n);

	sort(edges.begin(), edges.end(), [](edge & x, edge & y) {
        return x.w < y.w;
    });
	for (edge e: edges) {
		if (!disjoint.join(e.u, e.v)) continue;
        res += e.w;
	}
	cout << res;
}

