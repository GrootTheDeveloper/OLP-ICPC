#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

vector<int> parentM1, parentM2, szM1, szM2;

void make_set(int v, vector<int> &parent, vector<int> &sz) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v, vector<int> &parent) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &sz) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += b;
    }
}

signed main() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    parentM1.resize(n + 1, 0), parentM2.resize(n + 1, 0);
    szM1.resize(n + 1, 0), szM2.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        make_set(i, parentM1, szM1);
        make_set(i, parentM2, szM2);
    }

    for (int i = 1; i <= m1; i++) {
        int u, v; cin >> u >> v;
        union_sets(u, v, parentM1, szM1);
    }
    for (int i = 1; i <= m2; i++) {
        int u, v; cin >> u >> v;
        union_sets(u, v, parentM2, szM2);
    }
    vector<pair<int,int>> ans;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (find_set(i, parentM1) != find_set(j, parentM1) &&
                find_set(i, parentM2) != find_set(j, parentM2)) {
                    ans.push_back({i, j});
                    union_sets(i, j, parentM1, szM1);
                    union_sets(i, j, parentM2, szM2);
                }
        }
    }
    cout << ans.size() << endl;
    for (auto [u,v] : ans) {
        cout << u << " " << v << endl;
    }
}
