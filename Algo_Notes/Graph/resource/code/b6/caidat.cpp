#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n; 
const int MAXN = 100005;
vector<int> dist(MAXN, 0), parent(MAXN, -1);
vector<bool> visited(MAXN, false);
vector <int> adj[MAXN];

void bfs(int s) { 
    queue <int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (!visited[v]) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

signed main() {

}