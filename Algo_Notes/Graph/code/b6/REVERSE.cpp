#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int oo = 1e18;
const int MAXN = 100005;

int n, m;
int dist[MAXN];
vector <pair<int, int>> adj[MAXN];

void bfs(int s) {
    for (int i = 1; i <= n; i++) dist[i] = oo;
    deque <int> q;
    q.push_back(s);
    dist[s] = 0;
    while (q.empty() == false) {
        int u = q.front();
        q.pop_front();
        if (u == n) break;
        for (auto edge : adj[u]) {
            int w = edge.first;
            int v = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) q.push_front(v);
                else q.push_back(v);
            }
        }
    }
    if (dist[n] == oo) dist[n] = -1;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back({0, v});
        adj[v].push_back({1, u});
    }
    bfs(1);
    cout << dist[n];
}
