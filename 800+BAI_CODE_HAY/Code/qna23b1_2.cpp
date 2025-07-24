#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int seg[N * 4], sl[N * 4], a[N], lazy[N * 4];
int n,q;
void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = a[l];
        sl[id] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
    sl[id]  = sl[id * 2] + sl[id * 2 + 1];
}
void push(int id, int l, int r)
{
    if (lazy[id])
    {
        seg[id * 2] += sl[id * 2] * lazy[id];
        seg[id * 2 + 1] += sl[id * 2 + 1] * lazy[id];
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
        lazy[id] = 0;
    }
}
void update(int id, int l, int r, int u, int v, int val)
{
    if (l > v || r < u) return;
    if (u <= l && r <= v)
    {
        seg[id] += val * sl[id];
        lazy[id] += val;
        return;
    }
    push(id, l, r);
    int mid = (l + r) /2;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
int get(int id, int l, int r, int u, int v)
{
    if (l > v || r < r) return 0;
    if (u <= l && r <= v) return sl[id];
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u,v) + get(id * 2 + 1, mid + 1, r, u,v);
}
int find(int pos)
{
    int l = 1, r = n;
    int ans = 0;
    while (l < r)
    {
        int mid = (l + r) / 2;
        int s = get(1,1,n,1,mid);
        if (s >= pos) r = mid - 1;
        else l = mid + 1;
    }
    while (get(1,1,n,1, l - 1) == pos) l--;
    while (get(1,1,n,1,l) < pos) l++;
    return l;
}
void update_move(int id, int l, int r, int pos)
{
    if (l > pos || r < pos) return;
    if (l == r && pos == l)
    {
        sl[id] = seg[id] = 0;
        return;
    }
    push(id, l, r);
    int mid = (l + r) / 2;
    update_move(id * 2, l, mid, pos);
    update_move(id * 2 + 1, mid + 1, r, pos);
    sl[id] = sl[id * 2] + sl[id * 2 + 1];
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
int get_sum(int id, int l, int r, int u, int v)
{
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) / 2;
    push(id, l, r);
    return get_sum(id * 2, l, mid, u, v) + get_sum(id * 2 + 1, mid + 1, r, u, v);
}
int query(int l, int r)
{
    l = find(l); r = find(r);
    return get_sum(1, 1, n, l, r);
}
void up(int l, int r, int val)
{
    l = find(l); r = find(r);
    update(1, 1, n, l, r, val);
}
void rmove(int pos)
{
    pos = find(pos);
    update_move(1, 1, n, pos);
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    while (q--)
    {
        int type,u,v,x;
        cin >> type;
        if (type == 1)
        {
            cin >> u;
            rmove(u);
        }
        if (type == 2)
        {
            cin >> u >> v >> x;
            up(u,v,x);
        }
        if (type == 3)
        {
            cin >> u >> v;
            cout << query(u , v) << '\n';
        }
    }
}
