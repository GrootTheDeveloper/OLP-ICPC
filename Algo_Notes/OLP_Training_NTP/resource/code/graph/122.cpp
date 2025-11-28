#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> adj[1000005];
const int oo = 1e18 + 7;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    int k; cin >> k;
    int n = k + 2;
    vector<int>p(k + 1);
    for (int i = 1; i <= k; i++) cin >> p[i];
    vector<int> deg(n + 1, 1);
    for (int i = 1; i   <= k ;i++) {
        // p[i] : là cha của 1 thằng node lá nào đó có mã nhỏ nhất
        deg[p[i]]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            pq.push(i);
        }
    }

    for (int i = 1; i <= k; i++) {
        int leaf = pq.top();
        pq.pop();
        adj[leaf].push_back(p[i]);
        adj[p[i]].push_back(leaf);
        deg[leaf]--;
        deg[p[i]]--;
        if (deg[p[i]] == 1) {
            pq.push(p[i]);
        }
    }

    int u = pq.top(); pq.pop();
    int v = pq.top(); pq.pop();

    adj[u].push_back(v);
    adj[v].push_back(u);

    queue<int> q;
    q.push(1);
    vector<int> dist(n + 1, oo);
    dist[1] = 0;
    while (q.empty() == false) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dist[v] == oo) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
//    for (int i = 1; i <= n; i++) {cout << dist[i] << " ";} 
    int xa = -1;
    int maxDist = 0;
    for (int i = 2; i <= n; i++) {
        if (maxDist < dist[i]) {
            maxDist = dist[i];
            xa = i;
        }
    }
    while (q.empty() == false) q.pop();
    q.push(xa);
    for (int i = 1; i <= n; i++) {
        dist[i] = oo;
    }
    dist[xa] = 0;
    while (q.empty() == false) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
//            cout << "(" << u<<", " << v << "), ";
            if (dist[v] == oo) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }    
    
//    cout << endl; for (int i = 1; i <= n; i++) {cout << dist[i] << " ";}  cout << endl; 

    int ans = *max_element(dist.begin() + 1, dist.end());
    cout << ans;
}