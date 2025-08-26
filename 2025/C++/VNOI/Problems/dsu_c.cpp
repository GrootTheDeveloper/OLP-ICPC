#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> parent, sz, cow;

void make_set(int v) {
    parent[v] = v; sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        cow[a] += cow[b];
    }
}

signed main() {
    int n, k; cin >> n >> k;
    parent.resize(n + 1), sz.resize(n + 1), cow.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) make_set(i);

    for (int i = 1; i <= k; i++) {
        string type; cin >> type;
        if (type == "join") {
            int u, v; cin >> u >> v;
            union_sets(u, v);
        }
        else if (type == "add") {
            int u, v; cin >> u >> v;
            cow[find_set(u)] += v;
        }
        else{
            int u; cin >> u;
            cout << cow[find_set(u)] << endl;
        }
    }
    return 0;
}