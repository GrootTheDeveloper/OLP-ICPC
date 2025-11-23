#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {

    int n, m; cin >> n >> m;
    queue<int> q;
    q.push(n);

    map<int,int> dist;
    dist[n] = 0;
    while(q.empty() == false) {
        int u = q.front(); q.pop();
        if (u == m) {
            break;
        }
        int nhan = u * 2;
        int tru = u - 1;
        if (abs(u - m) > abs(nhan - m)) {
            if (dist.find(nhan) == dist.end()) {
                dist[nhan] = dist[u] + 1;
                q.push(nhan);
            }
        }
        if (dist.find(tru) == dist.end()) {
            dist[tru] = dist[u] + 1;
            q.push(tru);
        }
    }
    cout << dist[m];
}