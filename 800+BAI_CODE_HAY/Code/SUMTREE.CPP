#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second 
const int N = 1e5 + 5;

vector<ii> g[N];
long long sum[N], res[N], sz[N];
int n;
void input(){
    cin >> n;
    for (int i = 1; i < n; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
}
void calc(int u, int p = 0){
    sz[u] = 1;
    for (ii &x : g[u]){
        int v = x.fi, w = x.se;
        if (v == p) continue;
        calc(v, u);
        sz[u] += sz[v];
        sum[u] += sum[v] + 1ll * sz[v] * w;
    }
}
void down(int u, int p = 0){
    for (ii &x : g[u]){
        int v = x.fi, w = x.se;
        if (v == p) continue;
        res[v] = res[u] + w * (n - 2 * sz[v]);
        down(v, u);
    }
}
void solve(){
    calc(1);
    res[1] = sum[1];
    down(1);
    for (int i = 1; i <= n; i++)
        cout << res[i] << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    solve();
}