#include <bits/stdc++.h>
#define int long long

using namespace std;
vector<int>adj[100005];
signed main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while (q.empty() == false) {
                int u = q.front();
                q.pop();
                for (auto v : adj[u]) {
                    if (color[v] == -1) {
                        q.push(v);
                        color[v] = (color[u] == 1 ? 0 : 1);
                    }
                }
            }
        }
    }

    bool check = true;

    for (int i = 1; i <= n && check == true; i++) {
        for (auto v : adj[i]) {
            if (color[v] == color[i]) {
                check = false;
                break;
            }
        }
    }
    cout << (check ? "YES" : "NO");

}