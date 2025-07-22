#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
vector<int> adj[805];
const int MAXN = 800;
int n, m, timeDfs = 0;
vector<int> num(MAXN + 5, 0), low(MAXN + 5, 0);
vector<bool> deleted(MAXN + 5, false);
stack<int> st;
int scc = 0;
vector<int> comp(MAXN + 5);

void dfs(int u) {
    st.push(u);
    num[u] = low[u] = ++timeDfs;
    for (auto v : adj[u]) {
        if (deleted[v]) continue;
        if (num[v] == 0) {
            dfs(v);
            low[u] = min(low[v], low[u]);
        }
        else {
            low[u] = min(low[u], num[v]);
        }
    }    
    if (num[u] == low[u]) {
        int cur;
        do {
            cur = st.top(); st.pop();
            deleted[cur] = true;
            comp[cur] = scc;
        } while (cur != u);
        scc++;
    }
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) dfs(i);
    }
    vector<int> in_deg(scc, 0);
    for (int u = 1; u <= n; u++) {
        for (auto v : adj[u]) {
            if (comp[u] != comp[v]) {
                in_deg[comp[v]]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < scc; i++) {
        if (in_deg[i] == 0) {
            ans++;
        }
    }
    cout << ans;
}