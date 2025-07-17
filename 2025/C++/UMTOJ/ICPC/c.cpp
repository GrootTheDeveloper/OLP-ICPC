#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<int> adj[100005];
int depthTrack[100005];
int cost[100005];
int parent[100005];

signed main() {

    int n, m; cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        depthTrack[i] = -1;
        cost[i] = 0;
    }

    vector<vector<int>> depth(n + 1);
    queue<int> q;

    q.push(1);
    depthTrack[1] = 0;
    depth[0].push_back(1);
    parent[1] = 1;

    while(q.empty() == false) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (depthTrack[v] == -1) {
                depthTrack[v] = depthTrack[u] + 1;
                depth[depthTrack[v]].push_back(v);
                parent[v] = u;
                q.push(v);
            }
        }
    }


    for (int M = 1; M <= m; M++) {
        int type; cin >> type;
        if (type == 1) {
            int deep, coin;
            cin >> deep >> coin;
            for (auto v : depth[deep]) {
                cost[v] += coin;
            }
        }
        else {
            int node; cin >> node;
            q.push(node);
            int ans = cost[node];
            while (q.empty() == false) {
                int u = q.front(); q.pop();
                for (auto v : adj[u]) {
                    if (v != parent[u]) {
                        ans += cost[v];
                        q.push(v);
                    }
                }
            }
            cout << ans << endl;
        }
    }
}