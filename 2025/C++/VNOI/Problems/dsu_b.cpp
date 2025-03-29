/*
Status: Accepted
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int SIZE = 300005;

vector<int> parent(SIZE);
vector<int> sz(SIZE, 1);
vector<int> min_val(SIZE);
vector<int> max_val(SIZE);

// tìm gốc của tập hợp
int find(int u) {
    if (parent[u] != u) 
        parent[u] = find(parent[u]);
    return parent[u];
}

// gộp hai tập hợp
void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v); // u có size lớn hơn
    parent[v] = u;
    sz[u] += sz[v];
    min_val[u] = min(min_val[u], min_val[v]);
    max_val[u] = max(max_val[u], max_val[v]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        min_val[i] = max_val[i] = i;
    }

    while (m--) {
        string type; cin >> type;
        if (type == "union") {
            int u, v; cin >> u >> v;
            unite(u, v);
        } else if (type == "get") {
            int u; cin >> u;
            int root = find(u);
            cout  << min_val[root] << " " << max_val[root] << " " << sz[root] << endl;
        }
    }

    return 0;
}