#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[100005];
vector <int> g[100005];

void dfs(int u, int p = 0)
{
    vector <int> vec;
    for (int v : g[u]) if (v != p)
    {
        dfs(v, u);
        vec.push_back(dp[v]);
    }
    sort(vec.begin(), vec.end(), greater <int>());
    for (int i = 0; i < vec.size(); i++) dp[u] = max(dp[u], vec[i] + i + 1);


}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(x);
    cout << dp[x];
}
