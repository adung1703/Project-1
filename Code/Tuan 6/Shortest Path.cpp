#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void dijkstra(const vector<vector<int>>& adj, int source, int destination) {
    int n = adj.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == destination) {
            cout << dist[destination];
            return;
        }

        if (visited[u]) continue;
        visited[u] = true;

        for (int v = 1; v < n; v++) {
            if (adj[u][v] != INF) {
                int new_dist = dist[u] + adj[u][v];
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    pq.push({-dist[v], v});
                }
            }
        }
    }

    cout << -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v], w);
    }

    int u, v;
    cin >> u >> v;
    dijkstra(adj, u, v);

    return 0;
}

