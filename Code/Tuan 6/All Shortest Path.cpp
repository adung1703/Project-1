#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

vector<vector<int>> dist;

void dijkstra(vector<vector<pair<int, int>>>& adj, int source) {
    int n = adj.size();
    vector<bool> visited(n, false);

    dist[source][source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Custom min-heap

    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!visited[v] && dist[source][u] + weight < dist[source][v]) {
                dist[source][v] = dist[source][u] + weight;
                pq.push({dist[source][v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    dist.resize(n+1);
    for (int i = 1; i <=n; i++) {
        dist[i].resize(n+1);
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }
    vector<vector<pair<int, int>> > adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    for (int i = 1; i <= n; i++) {
        dijkstra(adj, i);
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] < INF) cout << dist[i][j] << " ";
            else cout << -1 << " ";
        }
        cout << "\n";
    }

    return 0;
}

