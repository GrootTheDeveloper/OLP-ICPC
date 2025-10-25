#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> adj[100005];
vector<int> parent(100005, -1);
signed main() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    vector<int> f(n + 1, 0);
    while (q.empty() == false) {
        int u = q.front(); q.pop();
        for (auto [v, w] : adj[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            f[v] = f[u] ^ w;
            q.push(v);
        }
    }
    int ans = 0;
    vector<int> cntOne(26, 0);
    for (int i = 1; i <= n; i++) {
        vector<int> bit;
        for (; f[i] > 0; bit.push_back(f[i] % 2), f[i] /= 2);
        while (bit.size() < 26) bit.push_back(0);
        //reverse(bit.begin(), bit.end());
        for (int j = 0; j < 26; j++) {
            cntOne[j] += bit[j];
        }
    }
    for (int i = 0; i < 26; i++) {
        ans += cntOne[i] * (n - cntOne[i]) * (1LL << i);
    }
    cout << ans;
}
