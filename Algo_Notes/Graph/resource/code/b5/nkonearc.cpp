#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
vector<int> adj[2005];
const int MAXN = 2000;
int n, m, timeDfs = 0;
stack<int> st;
vector<bool> deleted(MAXN + 5, false);
vector<int> deg_in(MAXN + 5, 0), deg_out(MAXN + 5, 0);
vector<int> num(MAXN + 5, 0), low(MAXN + 5, 0);
vector<int> comp(MAXN + 5, 0);
int scc = 0;

void dfs(int u) {
    num[u] = low[u] = ++timeDfs;
    st.push(u);
    for (auto v : adj[u]) {
        if (deleted[v] == true) continue;
        if (num[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], num[v]);
        }
    }

    if (low[u] == num[u]) {
        int v;
        do {
            v = st.top(); st.pop();
            deleted[v] = true;
            comp[v] = scc;
        } while (v != u);
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
    for (int u = 1; u <= n; u++) {
        for (auto v : adj[u]) {
            if (comp[u] != comp[v]) {
                deg_out[comp[u]]++;
                deg_in[comp[v]]++;
            }
        }
    }

    int u = -1, v = -1;
    for (int i = 0; i < scc; i++) {
        if (deg_out[i] == 0 && deg_in[i] > 0) {
            if (u != -1) {
                cout << "NO";
                return 0;
            }
            u = i;
        }
        if (deg_in[i] == 0 && deg_out[i] > 0) {
            if (v != -1) {
                cout << "NO";
                return 0;
            }
            v = i;
        }
    }
    bool ok1 = false, ok2 = false;
    for (int i = 1; i <= n; i++) {
        if (comp[i] == u && ok1 == false) {
            u = i;
            ok1 = true;
        }
        if (comp[i] == v && ok2 == false) {
            v = i;
            ok2 = true;
        }
    }
    cout << "YES\n" << u << " " << v;
}