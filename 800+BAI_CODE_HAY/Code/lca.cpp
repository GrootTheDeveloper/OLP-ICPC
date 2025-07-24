#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, q, d[N], up[N][19];
vector<int> adj[N];

void pre_dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i <= 18; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];

    for (int v : adj[u]) if (v != p) {
        d[v] = d[u] + 1;
        pre_dfs(v, u);
    }
}

int lift(int u, int k) { // Tìm nút cha thứ k của u 
    for (int i = 18; i >= 0; i--)
        if (k >> i & 1) {
            u = up[u][i];
        }
    return u;
}

int lca(int u, int v) {
    if (d[u] > d[v]) swap(u, v);
    v = lift(v, d[v] - d[u]);

    if (u == v) return u;

    for (int i = 18; i >= 0; i--)
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }

    return up[u][0];
}

signed main() {
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pre_dfs(1, 0);

    cin >> q;
    for (int a, b, c; q--; ) {
        cin >> a >> b >> c;
        cout << lca(a,b) << ' ' << lift(a,c) << ' ' << lift(b,c) << '\n';  
    }
}
