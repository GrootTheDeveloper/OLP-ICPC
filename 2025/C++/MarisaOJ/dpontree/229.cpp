#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;

vector<int> adj[100005];
vector<int> a, dp1, dp2;
/*
dp1[u] : Tổng lớn nhất của đường đi từ u xuống dưới (dùng để nối lên cha)
dp2[u] : Tổng lớn nhất của đường đi trong cây con gốc u
*/
void dfs(int u, int parent) {
    dp1[u] = a[u];
    for (auto v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        dp1[u] = max(dp1[u], dp1[v] + a[u]);
        dp2[u] = max(dp2[u], a[v] + dp1[u]);
    }
}

signed main() {
    int n; cin >> n;
    a.resize(n + 1), dp1.resize(n + 1, 0), dp2.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    

    dfs(1,1);
    cout << *max_element(dp.begin() + 1, dp.end());

}