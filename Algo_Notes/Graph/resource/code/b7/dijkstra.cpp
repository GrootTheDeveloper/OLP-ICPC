#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int oo = 1e18;
const int MAXN = 100005;

int n, m, S;
vector< pair<int, int> > adj[MAXN];
vector<int> dist(MAXN, oo), trace(MAXN, -1);
vector<bool> visited(MAXN, false);

void dijkstra(int s) {
    dist[s] = 0;
    for (int i = 1; i <= n; i++) {
        int uBest;
        int Min = oo;
        for (int u = 1; u <= n; u++) {
            if (visited[u] == false && dist[u] < Min) {
                Min = dist[u];
                uBest = u;
            }
        }

        int u = uBest;
        visited[u] = true;

        for (auto x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                trace[v] = u;
            }
        }
    }
}

signed main() {
    cin >> n >> m >> S;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(S);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == oo) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << endl;
}
