#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n, m, q; 
const int MAXN = 500005;
vector<bool> visited(MAXN, false);
vector <int> adj[MAXN];
vector<int> color(MAXN, 1);
/*
Ban đầu, tất cả đỉnh đều màu xanh
Nếu c = u, d = dist, các đỉnh kề cách dist -1 chuyển thành trắng
*/

signed main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < q; i++) {
        int c, d; cin >> c >> d;
        if (d == 0) {
            color[c] = 1;
            continue;
        }
        int mustBeWhite = d - 1;

        queue<pair<int,int>> q; q.push({c, mustBeWhite});
        color[c] = 0;
        while (q.empty() == false) {
            auto [u, mbw] = q.front(); q.pop();
            if (mbw <= 0) continue;
            for (auto v : adj[u]) {
                if (color[v] == 1) {
                    color[v] = 0;
                    q.push({v, mbw-1});
                }
            }
        }
    }
    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (color[i] == 1) {
            ans.push_back(i);
        }
    }
    if (ans.size() <= 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl << ans.size() << endl;
    for (auto i : ans) cout << i << " ";
}  