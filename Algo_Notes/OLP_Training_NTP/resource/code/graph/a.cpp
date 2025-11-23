#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> adj[100005];
vector<bool> check(1e5 + 5, false);
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
            queue<int> q;
            q.push(i);
            check[i] = true;
            cnt++;
            while (q.empty() == false) {
                int u = q.front();
                q.pop();
                for (auto v : adj[u]) {
                    if (check[v] == false) {
                        check[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    cout << cnt;

}