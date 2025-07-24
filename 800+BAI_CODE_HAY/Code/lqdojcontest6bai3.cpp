#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int,int>
#define val first
#define id second
const int maxn = 3e5 + 5, maxm = 5e5 + 5;
int par[maxn], sz[maxn];
ii q[maxn];
int res = 0, ans[maxn];
int n,m,k;
struct node
{
    int x,y,w;
    bool operator<(const node &other) const{
        return w < other.w;
    }
}g[maxm];
int calc(int n) {return n*(n-1)/2;}
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
    return (par[v] == v ? v : par[v] = find(par[v]));
}
void Union(int a, int b)
{
    a = find(a); b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a,b);
    res -= ( calc(sz[a]) + calc(sz[b]));
    sz[a] += sz[b];
    res += calc(sz[a]);
    par[b] = a;
}
void solve()
{
    sort(g + 1, g + m + 1);
    sort(q + 1, q + k + 1, less<ii>());
    int l = 1;
    for (int i = 1; i <= k; i++)
    {
        while (l <= m && g[l].w <= q[i].val) Union(g[l].x, g[l].y), l++;
        ans[q[i].id] = res;
    }
    for (int i = 1; i <= k; i++) cout << ans[i] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("TRAVEL.INP","r",stdin);
    freopen("TRAVEL.OUT","w",stdout);
    int oo; cin >> oo;
    cin >> n >> m;
    make_set();
    for (int i = 1; i <= m; i++)
        cin >> g[i].x >> g[i].y >> g[i].w;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> q[i].val;
        q[i].id = i;
    }
    solve();

}
