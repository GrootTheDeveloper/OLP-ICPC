#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
vector<bool> check(100005, false);
int n, m; 

int main() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    
    bool possible = true;

    queue<pair<int,int>> q;
    vector<int> teams(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        if (check[i]) continue;
        q.push({i, 1});
    
        while(q.empty() == false) {
            auto [u, team] = q.front();
            q.pop();
            check[u] = true;
            teams[u] = team;
            for (auto v : adj[u]) {
                if (check[v]) {
                    if (teams[v] == teams[u]) {
                        possible = false;
                        break;
                    }
                    continue;
                }
                q.push({v, ((team == 1 ? 2 : 1))});
            }
        }
    }
    if (!possible){ cout << "IMPOSSIBLE"; return 0; }
    for (int i = 1; i <= n; i++) {
        cout << teams[i] << " ";
    }
}
