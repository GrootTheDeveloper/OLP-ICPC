#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;

int seg[maxn * 4], a[maxn], lazy[maxn * 4];

void push(int id, int l, int r)
{
    if (lazy[id])
    {
        seg[id * 2] += lazy[id];
        seg[id * 2 + 1] += lazy[id];
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
        lazy[id] = 0;
    }
}
void update(int id , int l, int r, int u, int v, int val)
{
    if (u > r || v < l) return;
    if (u <= l && r <= v)
    {
        seg[id] += val;
        lazy[id] += val;
        return;
    }
    push(id, l, r);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) / 2;
    push(id, l, r);
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("kgss.inp","r",stdin);
    //freopen("kgss.out","w",stdout);
    int n,m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int l,r,val; cin >> l >> r >> val;
        update(1,1,n,l,r,val);
    }
    int q; cin >> q;
    while (q --)
    {
       int u,v; cin >> u >> v;
       cout << get(1,1,n,u,v) << '\n';
    }
}
