#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> adj[150005];
const int MAXN = 150005;
signed main() {
    int n, m; cin>> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    int q; cin >> q;
    int curN = n;
    vector<int> vis(MAXN, 0);
    int vers = 1;

    for (int i = 1; i <= q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int x, d; cin >> x >> d;
            curN++; 
            if (d == 0) {
                adj[x].push_back(curN);
            } else {
                adj[curN].push_back(x);
            }
        } else {
            int x, y; cin >> x >> y;
            deque<int> dq;
            vers++;
            dq.push_back(x);
            vis[x] = vers;
            bool flag = (x == y);
            while (!dq.empty() && !flag) {
                int u = dq.front(); dq.pop_front();
                for (int v : adj[u]) {
                    if (vis[v] != vers) {
                        vis[v] = vers;
                        if (v == y) { flag = true; break; }
                        dq.push_back(v);
                    }
                }
            }
            cout << (flag ? "Yes" : "No") << endl;
        }
    }
    return 0;
}