#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e4 + 5;
struct node{
    int x,y,w;
}eg[maxn];
bool cmp(node a, node b) {return a.w < b.w;}

int par[maxn], sz[maxn], n, m;

void make_set()
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i]  = 1;
    }
}
int find(int v)
{
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}
bool Union(int a, int b)
{
    a = find(a); b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a,b);
    par[b] = a;
    sz[a] += sz[b];
    return true;
}
void inp()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> eg[i].x >> eg[i].y >> eg[i].w;
}
void solve()
{
    sort(eg + 1, eg + m + 1, cmp);
    make_set();
    int res = 0;
    for (int i = 1; i <= m; i++)
        if (Union(eg[i].x, eg[i].y)) res = eg[i].w;
    cout << res;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    inp();
    solve();
}


