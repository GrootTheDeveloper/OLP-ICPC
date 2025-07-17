#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int oo = LLONG_MAX;
vector<int> adj[200005];
// vector<int> visited(200005, 0);
vector<int> parent(200005, 0);
vector<int> sz(200005, 1);
int component;
int maxSize;
int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    int a = find(u);
    int b = find(v);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
    component--;
    maxSize = max(maxSize, sz[a]);
}

signed main() {
    int n, m; cin >> n >> m;
    component = n;
    maxSize = 1;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        unite(u,v);
        cout << component << " " << maxSize << endl;
    }
}