#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int oo = 1e18;
const int MAXN = 100005;

//vector<pair<int,int>>

struct Edge {
    int u, v, w;
};

bool compare(const Edge &cur, const Edge &other) {
    return cur.w < other.w;
}

vector<Edge> Graph;
vector<int> parent, sz;
int ans = 0;
int C(int n) {
    return n * (n - 1) / 2;
}

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v]) return v;
    int p = find_set(parent[v]);
    parent[v] = p;
    return p;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        ans += C(sz[a] + sz[b]) - C(sz[a]) - C(sz[b]);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

signed main() {
    int n, m; cin >> n >> m;
    parent.resize(n + 1); sz.resize(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        Edge cur;
        cin >> cur.u >> cur.v >> cur.w;
        Graph.push_back(cur);
    }
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }

    sort(Graph.begin(), Graph.end(), compare);
    vector<pair<int,int>>q(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> q[i].first;
        q[i].second = i;
    }

    sort(q.begin() + 1, q.end());

    int idx = 0;
    
    vector<int> res(m + 1);
    for (int i = 1; i <= m; i++) {
        int val = q[i].first;
        while (idx <= n - 2 && Graph[idx].w <= val) {
            union_sets(Graph[idx].u,Graph[idx].v);
            idx++;
        }
        res[q[i].second] = ans;
    }
    for (int i = 1; i <= m; i++) {
        cout << res[i] << " ";
    }
}
