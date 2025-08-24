#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

vector<int> parent(1005), sz(1005);
vector<pair<int,int>> close_edges, new_edges;

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
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
    int n; cin >> n;
    for (int i = 1; i <= n; i++) make_set(i);

    vector<pair<int,int>> edges;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        edges.push_back({u, v});
    }

    for (auto [u, v] : edges) {
        if (find_set(u) != find_set(v)) {
            union_sets(u, v);
        } else {
            close_edges.push_back({u, v});
        }
    }

    vector<int> reps;
    for (int i = 1; i <= n; i++) {
        if (find_set(i) == i) reps.push_back(i);
    }

    for (int i = 0; i + 1 < reps.size(); i++) {
        new_edges.push_back({reps[i], reps[i+1]});
        union_sets(reps[i], reps[i+1]);
    }

    cout << close_edges.size() << endl;
    for (int i = 0; i < (int)close_edges.size(); i++) {
        cout << close_edges[i].first << " " 
             << close_edges[i].second << " "
             << new_edges[i].first << " "
             << new_edges[i].second << endl;
    }
}
