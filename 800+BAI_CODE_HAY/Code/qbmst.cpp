#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e4;
struct node
{
    int x,y,w;
}g[maxn];
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
    if (par[v] == v) return v;
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
        cin >> g[i].x >> g[i].y >> g[i].w;
    sort(g + 1, g + m + 1, cmp);
    make_set();
    int res = 0;
    for (int i = 1; i <= m; i++)
        if (Union(g[i].x, g[i].y)) res += g[i].w;
    cout << res;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    inp();
}
