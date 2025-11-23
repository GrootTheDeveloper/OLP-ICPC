#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> adj[100005];
vector<bool> check(1e5 + 5, false);

void dfs(int u) {
    check[u] = true;
    for (auto v : adj[u]) {
        if (check[v] == false) {
            dfs(v);
        }
    }
}
signed main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (check[i] == false) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;

}