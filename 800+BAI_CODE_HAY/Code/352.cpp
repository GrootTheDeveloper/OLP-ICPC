#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> g[100005];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    if (n == 1) return cout << 1, 0;
    for (int i = 1; i < n; i++)
    {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res += (g[i].size() == 1);
    cout << res;
}
