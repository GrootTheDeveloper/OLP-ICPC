#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MAXN = 2e5;
vector<int> adj[200005];
unordered_map<int, int> edge_cnt;
int n;
int low[MAXN + 5] = {0}, num[MAXN + 5] = {0};
int bridge = 0, timeDfs = 0;

int id(int a, int b) {
    return min(a, b) * MAXN + max(a,b);
}
void dfs(int u, int parent) {
    low[u] = num[u] = ++timeDfs;

    for (auto v : adj[u]) {
        if (v == parent) continue;
        if (num[v] == 0) {
            dfs(v, u);
            low[u] = min(low[v], low[u]);
            int a = u, b = v;
            if (low[v] > num[u] && edge_cnt[id(a,b)] == 1) {
                bridge++;
            }
        }
        else {
            low[u] = min(low[u], num[v]);
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge_cnt[id(u,v)]++;
    }
    int m; cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (u > v) swap(u, v);
        if (edge_cnt.find(id(u,v)) != edge_cnt.end()) edge_cnt[id(u,v)]++;
    }

    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            dfs(i,i);
        }
    }

    cout << bridge;

    return 0;
}
