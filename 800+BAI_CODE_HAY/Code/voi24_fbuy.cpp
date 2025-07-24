#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 998244353;
int n, q, k;
int a[200005], b[22];
int cnt[22];
int d[200005], par[200005], sz[200005], Arr[2002];
vector <int> g[200005];
void dfs(int u, int p = 0)
{
    sz[u] = 1;
    for (int v : g[u])
    {
        if (v == p) continue;
        d[v] = d[u] + 1;
        par[v] = u;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
int calc(int u, int v)
{
    memset(cnt, 0, sizeof(cnt));
    while (u != v)
    {
        if (d[u] > d[v]) swap(u, v);
        cnt[a[v]]++;
        v = par[v];
    }
    cnt[a[v]]++;
    int ans = 0;
    for (int i = 1; i <= k; i++) ans = (ans + b[i] * cnt[i] * cnt[i]) % mode;
    return ans;
}
void sub1()
{
    dfs(1);
    int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) ans = (ans + calc(i, j)) % mode;
        cout << ans << '\n';
    while (q--)
    {
        int pos, kind ; cin >> pos >> kind;
        a[pos] = kind;
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) ans = (ans + calc(i, j)) % mode;
        cout << ans << '\n';
    }
}
const int N = 2e3 + 5;
int seg[N * 4 + 5][22];
int face[N], chain[N], pos[N], tout[N];
int cur_chain, cur_pos;
void add(int id, int l, int r, int pos, int val)
{
    if (pos > r || pos < l) return;
    if (l == r && pos == l)
    {
        memset(seg[id], 0, sizeof(seg[id]));
        seg[id][val] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    add(id * 2, l, mid, pos, val);
    add(id * 2 + 1, mid + 1, r, pos, val);
    for (int i = 1; i <= k; i++)
        seg[id][i] = seg[id * 2][i] + seg[id * 2 + 1][i];
}
void update(int pos, int val)
{
    add(1, 1, n, pos, val);
}

void hld(int s, int p = 0)
{
    if (!face[cur_chain])
        face[cur_chain] = s;
    pos[s] = ++cur_pos;
    Arr[cur_pos] = s;
    update(cur_pos, a[s]);
    chain[s] = cur_chain;
    int nxt = 0;
    for (int v : g[s])
        if (v != p && sz[v] > sz[nxt]) nxt = v;
    if (nxt) hld(nxt, s);
    for (int v : g[s])
        if (v != nxt && v != p) hld(v, s);
    tout[s] = cur_pos;
}
int result[21];

void Get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return;
    if (u <= l && r <= v)
    {
        for (int i = 1; i <= k; i++) result[i] += seg[id][i];
        return;
    }
    int mid = (l + r) >> 1;
    Get(id * 2, l, mid, u, v);
    Get(id * 2 + 1, mid + 1, r, u, v);

}
void get(int l, int r)
{
    Get(1, 1, n, l, r);
}
int query(int u, int v)
{
    memset(result, 0, sizeof(result));
    while (chain[u] != chain[v])
    {
        if (chain[u] > chain[v]) swap(u, v);
        get(pos[face[chain[v]]], pos[v]);
        v = par[face[chain[v]]];
    }
    if (pos[u] > pos[v]) swap(u, v);
    get(pos[u], pos[v]);
    int ans = 0;
    for (int i = 1; i <= k; i++) ans = (ans +  result[i] * result[i] * b[i]) % mode ;
    return ans;
}
void sub2()
{
    dfs(1); hld(1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            ans += query(i, j);
    cout << ans << '\n';
    while (q--)
    {
        int u, val; cin >> u >> val;
        for (int i = pos[u] + 1; i <= tout[u]; i++)
            ans -= query(u, Arr[i]);
        for (int i = 1; i < pos[u]; i++)
            for (int j = pos[u]; j <= tout[u]; j++)
                ans -= query(Arr[i], Arr[j]);
        for (int i = pos[u] + 1; i <= n; i++)
            for (int j = pos[u]; j <= tout[u]; j++)
                ans -= query(Arr[i], Arr[j]);

        update(pos[u], val);
        for (int i = pos[u] + 1; i <= tout[u]; i++)
            ans += query(u, Arr[i]);
        for (int i = 1; i < pos[u]; i++)
            for (int j = pos[u]; j <= tout[u]; j++)
                ans += query(Arr[i], Arr[j]);
        for (int i = tout[u] + 1; i <= n; i++)
            for (int j = pos[u]; j <= tout[u]; j++)
                ans += query(Arr[i], Arr[j]);
        cout << ans << '\n';
    }
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("FBUY.INP","r",stdin);
    freopen("FBUY.OUT","w",stdout);
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];

    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n <= 100 && q <= 800) sub1();
    //else if (n <= 2000 && q <= 800) sub2();
   // sub2();
}
