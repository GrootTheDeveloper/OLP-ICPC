#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int oo = 1e18;
const int MAXN = 100005;

int n, m, s;
vector< pair<int, int> > adj[MAXN];
vector<int> dist(MAXN, oo), trace(MAXN, -1);
vector<bool> visited(MAXN, false);

void dijkstra(int s) {
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    dist[s] = 0;
    pq.push({0, s});

    while (pq.empty() == false) {
        int du = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u] == true) continue;
        visited[u] = true;

        for (auto e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                trace[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(s);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == oo) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << endl;
}
