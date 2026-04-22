#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove this line if graph is directed
    }

    int source;
    cin >> source;

    // Distance array
    vector<int> dist(n + 1, INT_MAX);
    dist[source] = 0;

    // Min heap: {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});

    while(!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if(d > dist[node]) continue;

        for(auto [neighbor, weight] : adj[node]) {
            if(dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Output
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}