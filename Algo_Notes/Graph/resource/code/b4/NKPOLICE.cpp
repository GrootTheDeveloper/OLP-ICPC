#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MAXN = 1e5;
vector<int> adj[100005];
int n, m, q;

signed main() {
    
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int A, B, G1, G2;
            cin >> A >> B >> G1 >> G2;
        }
        else {
            int A, B, C; 
            cin >> A >> B >> C;
        }
    }

    return 0;
}
