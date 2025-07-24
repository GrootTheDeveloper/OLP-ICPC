#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector <int> g[1000006];
int ans[1000006];
struct node
{
    vector <int> a;
    int mx = 0;
    int sz()
    {
        return a.size();
    }
    void add(int pos, int val)
    {
        a[pos] += val;
        if (make_pair(a[pos], pos) > make_pair(a[mx], mx))
            mx = pos;
    }

    void pull()
    {
        a.push_back(0);
        add(a.size() - 1, 1);
    }

};
node vertex[1000006];

void mer(node &u, node &v)
{
    if (u.sz() < v.sz()) swap(u, v);

    int szu = u.sz(), szv = v.sz();
    for (int id = 1; id <= szv; id++)
        u.add(szu - id, v.a[szv - id]);
}

void dfs(int u, int p = 0)
{
    for (int v : g[u])
    {
        if (v == p) continue;
        dfs(v, u);
        mer(vertex[u], vertex[v]);
    }
    vertex[u].pull();
    ans[u] = vertex[u].sz() - vertex[u].mx - 1;
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}


