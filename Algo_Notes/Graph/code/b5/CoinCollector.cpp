#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n, m, timeDfs = 0, scc = 0;
const int MAXN = 1e5;
vector<int> k, adj[100005], num(MAXN + 5, 0), low(MAXN + 5, 0), comp(MAXN + 5, 0);
vector<bool> deleted(MAXN + 5, false);
vector<int> cost(MAXN + 5, 0), dp;
vector<vector<int>> bigNode;
stack<int> st;
void dfs(int u) {
    st.push(u);
    num[u] = low[u] = ++timeDfs;
    for (auto v : adj[u]) {
        if (deleted[v] == true) continue;
        if (num[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], num[v]);
        }
    }
    if (num[u] == low[u]) {
        int v;
        do {
            v = st.top(); st.pop();
            deleted[v] = true;
            comp[v] = scc;
            cost[scc] += k[v];
        } while (v != u);
        scc++;
    }
}

void findCost(int u) {
    if (dp[u] != -1) return;
    dp[u] = cost[u];
    for (auto v : bigNode[u]) {
        findCost(v);
        dp[u] = max(dp[u], dp[v] + cost[u]);
    }
}

signed main() {
    cin >> n >> m;
    k.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) dfs(i);
    }
    bigNode.resize(scc);
    dp.resize(scc, -1);
    for (int u = 1; u <= n; u++) {
        for (auto v : adj[u]) {
            if (comp[u] != comp[v]) {
                bigNode[comp[u]].push_back(comp[v]);
            }
        }
    }
    for (int i = 0; i < scc; i++) {
        if (dp[i] == -1) {
            findCost(i);
        }
    }
    cout << *max_element(dp.begin(), dp.end());   
}