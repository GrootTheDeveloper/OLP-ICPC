#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MAXN = 1e5;
vector<int> adj[100005];
int n, m; 
vector<int> low(MAXN + 1, 0), num(MAXN + 1, 0);
int timeDfs = 1;
vector<pair<int,int>> br;
set<int> jo;

void dfs(int u, int parent) {
    int child = 0;
    low[u] = num[u] = timeDfs++;
    for (auto v : adj[u]) {
        if (v == parent) continue;
        if (num[v] == 0) { // (forward edge)
            dfs(v, u); 
            child++;
            low[u] = min(low[u], low[v]);
            // bridge
            if (low[v] == num[v]) {
                br.push_back({u, v});
            }
            // joint (u is root)
            if (parent != 0) { // joint (u isnt root)
                if (low[v] >= num[u]) {
                    jo.insert(u);
                }
            }
        }
        else { // (back edge)
            low[u] = min(low[u], num[v]);
        }
    }
    if (parent == 0) {
        if (child > 1) {
            jo.insert(u);
        }
    }
}
signed main() {
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            dfs(i, 0);
        }
    }
    cout << jo.size() << " " << br.size();
    return 0;
}
