#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[100005][30], ans;
bool us[100005];
int in[100005];
vector <int> g[100005];
string s;
void dfs(int u)
{
    us[u] = true;
    for (int v : g[u])
    {
        if (!us[v]) dfs(v);
        for (char x = 'a'; x <= 'z'; x++)
            ans = max(ans, dp[u][x - 'a'] = max(dp[u][x - 'a'], dp[v][x - 'a'] + (s[u - 1] == x)));
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        in[v]++;
        g[u].push_back(v);
    }
    queue <int> q;
    for (int i = 1; i <= n; i++)
    {
        dp[i][s[i - 1] - 'a']++;
        if (in[i] == 0) q.push(i);
    }
    vector <int> vec;
    while (q.size())
    {
        int u = q.front(); q.pop();
        vec.push_back(u);
        for (int v : g[u])
        {
            if (--in[v] == 0) q.push(v);
        }
    }
    reverse(begin(vec), end(vec));
    for (int x : vec)
        if (!us[x]) dfs(x);
    cout << ans;

}
