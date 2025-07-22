#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
vector<int> adj[10005];
int n, m, timeDfs = 0;
const int MAXN = 1e4;
stack<int> st;
vector<bool> deleted(MAXN + 5, false);
vector<int> num(MAXN + 5, 0), low(MAXN + 5, 0);
int scc = 0;
void dfs(int u) {
    st.push(u);
    num[u] = low[u] = ++timeDfs;
    for (auto v : adj[u]) {
        if (num[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else {
            if (deleted[v] == false) low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u]) {
        int cur;
        scc++;
        do {
        cur = st.top();
        deleted[cur] = true;
        st.pop();
        } while (cur != u);
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }    
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            dfs(i);
        }
    }
    cout << scc;
}