#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> parent, sz;

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
    }
}

signed main() {
    int n, m, k; cin >> n >> m >> k;
    parent.resize(n + 1), sz.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
    }
    vector<pair<string, pair<int,int>>> q(k + 1);
    for (int i = 1; i <= k; i++) {
        string type; cin >> type;
        int u, v; cin >> u >> v;
        q[i] = {type, {u, v}};
    }
    vector<string> ans;
    for (int i = k; i >= 1; i--) {
        string type = q[i].first;
        auto [u, v] = q[i].second;
        if (type == "cut") {
            union_sets(u, v);
        }
        else {
            int a = find_set(u);
            int b = find_set(v);
            if (a == b) ans.push_back("YES");
            else ans.push_back("NO");
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto s : ans) cout << s << endl;
    return 0;
}