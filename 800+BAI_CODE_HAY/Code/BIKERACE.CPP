#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> g[100005];
bool mark[100005];
int sz[100005], in[100005];
int n, m;

void calc_size(int u, bool &has)
{
    if (in[u] == 1) has = false;
    sz[u] = 1;
    mark[u] = true;
    for (int v : g[u])
    {
        if (!mark[v])
        {
            calc_size(v, has);
            sz[u] += sz[v];
        }
    }
}
void sub1()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    if (!mark[i])
    {
        bool has = true;
        calc_size(i, has);
        int x = sz[i];
        if (has) ans += x * (x - 1) * (x - 2);
        else ans += x * (x - 1) * (x - 2) / 6 * 2;
    }
    cout << ans;
}


namespace Sub2
{
    #define tp tuple<int,int,int>
    bool us[55];
    int ans = 0;
    map<tp, bool> mp;
    void dfs(int u, vector<int> &vec)
    {
        us[u] = true;
        for (int i = 1; i < vec.size(); i++)
        if (mp.find({vec[0], vec[i], u}) == mp.end())
        {
            ans++;
            mp[{vec[0], vec[i], u}] = true;
        }
        vec.push_back(u);
        for (int v : g[u])
        if (!us[v])
            dfs(v, vec);
        us[u] = false;
        vec.pop_back();
    }

    void work()
    {
        for (int i = 1; i <= n; i++)
        {
            vector <int> vec;
            dfs(i, vec);
        }
        cout << ans;
    }
}

namespace Sub3
{
    bool mark[100005];
    bool us[100005];
    int sz[100005], dp[100005];
    int ans = 0;
    void dfs(int u)
    {
        dp[u] = 1;
        sz[u] = 1;
        mark[u] = true;
        for (int v : g[u])
        if (!mark[v])
        {
            dfs(v);
            ans += dp[v] * (dp[u] - 1);
            dp[u] += dp[v];
            sz[u] += sz[v];
        }
    }
    void calc(int u, int x)
    {
        us[u] = true;
        ans += (x - sz[u]) * (sz[u] - 1);
        for (int v : g[u])
            if (!us[v]) calc(v, n);
    }
    void work()
    {
        for (int i = 1; i <= n; i++)
        if (!mark[i])
        {
            dfs(i);
            calc(i, sz[i]);
        }
        cout << ans * 2;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("BIKERACE.INP","r",stdin);
    freopen("BIKERACE.OUT","w",stdout);
    cin >> n >> m;
    int c = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        c = max({c, ++in[v], ++in[u]});
    }
    if (c <= 2) sub1();
    else if (n <= 10 && m <= 100) Sub2::work();
    else Sub3::work();
}
