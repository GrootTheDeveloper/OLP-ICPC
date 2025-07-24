#include <bits/stdc++.h>
using namespace std;
#define int long long

bool mark[100005][11];
int tus[100005];
int n, m;
struct node
{
    int u, d, c;
}op[100005];
vector <int> g[100005];
void fill_col(int u, int d, int c)
{
    if (mark[u][d] || d < 0) return;
    mark[u][d] = true;
    if (!tus[u]) tus[u] = c;
    for (int v : g[u])
        fill_col(v, d - 1, c);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   // freopen("t.inp","r",stdin);
   // freopen("t.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int q; cin >> q;
    for (int i = 1; i <= q; i++)
        cin >> op[i].u >> op[i].d >> op[i].c;
    for (int i = q; i >= 1; i--)
        fill_col(op[i].u, op[i].d, op[i].c);
    for (int i = 1; i <= n; i++) cout << tus[i] << '\n';
}
