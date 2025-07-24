#include <bits/stdc++.h>
using namespace std;
#define sz(s) (int)s.size()
const int N = 1e5 + 5;
int n, Time;
int tin[N], up[N][18], face[N], d[N], c[N], val[N];
vector<int> g[100005];
set<int> s[100005];
set<int> ::iterator it, pre, suf;
int Log2(int n)
{
    return 31 - __builtin_clz(n);
}
void dfs(int u, int p = 0)
{
    tin[u] = ++Time;
    face[Time] = u;
    up[u][0] = p;
    int lim = Log2(d[u]);
    for (int i = 1; i <= lim; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : g[u]) if (v != p)
    {
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}
int lift(int k, int v)
{
    for (int i = Log2(k); i >= 0; i--)
    if (k >> i & 1) v = up[v][i];
    return v;
}
int lca(int u, int v)
{
    if (d[u] > d[v]) swap(u, v);
    v = lift(d[v] - d[u], v);
    if (u == v) return u;
    for (int i = Log2(d[u]); i >= 0; i--)
    if (up[u][i] != up[v][i])
        u = up[u][i], v = up[v][i];
    return up[u][0];
}
int dis(int u, int v)
{
    int x = lca(u, v);
    return d[u] + d[v] - 2 * d[x];
}
void add(int u, int x)
{
    c[u] = x;
    s[x].insert(tin[u]);
    pre = suf = it = s[x].find(tin[u]);
    if (pre != s[x].begin()) pre--;
    suf++; if (suf == s[x].end()) suf--;
    if (it != pre)
    {
        int v = face[*pre];
        val[x] += dis(u, v);
    }
    if (it != suf)
    {
        int v = face[*suf];
        val[x] += dis(u, v);
    }
    if (pre != it && suf != it)
    {
        int lef = face[*pre], rig = face[*suf];
        val[x] -= dis(lef, rig);
    }
    if (pre == it)
    {
        int v = face[*s[x].rbegin()];
        val[x] += dis(u, v);
        val[x] -= dis(face[*suf], v);
    }
    if (suf == it)
    {
        int v = face[*s[x].begin()];
        val[x] += dis(u, v);
        val[x] -= dis(face[*pre],  v);
    }
}
void del(int u, int x)
{
    pre = suf = it = s[x].find(tin[u]);
    if (pre != s[x].begin()) pre--;
    suf++; if (suf == s[x].end()) suf--;
    if (it != pre)
    {
        int v = face[*pre];
        val[x] -= dis(u, v);
    }
    if (it != suf)
    {
        int v = face[*suf];
        val[x] -= dis(u, v);
    }
    if (pre != it && suf != it)
    {
        int lef = face[*pre], rig = face[*suf];
        val[x] += dis(lef, rig);
    }
    if (pre == it)
    {
        int v = face[*s[x].rbegin()];
        val[x] -= dis(u, v);
        val[x] += dis(face[*suf], v);
    }
    if (suf == it)
    {
        int v = face[*s[x].begin()];
        val[x] -= dis(u, v);
        val[x] += dis(face[*pre],  v);
    }
    s[x].erase(tin[u]);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen("input.inp","r",stdin);
//    freopen("output.out","w",stdout);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        int ci; cin >> ci;
        add(i, ci);
        c[i] = ci;
    }
    int q; cin >> q;
    while (q--)
    {
        char kind; cin >> kind;
        if (kind == 'Q')
        {
            int x; cin >> x;
            if (sz(s[x])) cout << (val[x] >> 1) << '\n';
            else cout << -1 << '\n';
        } else
        {
            int u, x; cin >> u >> x;
            del(u, c[u]);
            add(u, x);
        }
    }
}
