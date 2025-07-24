#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define val first
#define node second

int d[100005], a[100005];
vector <int> g[100005];
ii low[100005], high[100005];
struct DSU
{
    vector <int> par, sz;
    DSU (int n)
    {
        par.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int v)
    {
        return ((par[v] == v)? v : par[v] = find(par[v]));
    }
    void Union(int a, int b)
    {
        a = find(a); b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
    }
    int calc(int v)
    {
        v = find(v);
        return sz[v];
    }
};

void dfs(int u, int p = 0)
{
    for (int v : g[u]) if (v != p)
    {
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}
bool cmp1(ii a, ii b)
{
    if (a.val != b.val) return a.val > b.val;
    return d[a.node] > d[b.node];
}
bool cmp2(ii a, ii b)
{
    if (a.val != b.val) return a.val < b.val;
    return d[a.node] > d[b.node];
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int ai; cin >> a[i];
        low[i].val = a[i];
        low[i].node = i;
        high[i] = low[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    sort(low + 1, low + n + 1, cmp1);
    sort(high + 1, high +  n + 1, cmp2);
    DSU mi(n);
    DSU mx(n);
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = low[i].node, cnt = 0;
        for (int v : g[u])
        {
            if ((a[v] == a[u] && d[v] < d[u]) || a[v] < a[u]) continue;
            res -= a[u] * mi.calc(v) * (cnt + 1);
            cnt += mi.calc(v);
            mi.Union(u, v);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int u = high[i].node, cnt = 0;
        for (int v : g[u])
        {
            if ((a[v] == a[u] && d[v] < d[u]) || a[v] > a[u]) continue;
            res += a[u] * mx.calc(v) * (cnt + 1);
            cnt += mx.calc(v);
            mx.Union(u,v);
        }
    }
    cout << res;

}
