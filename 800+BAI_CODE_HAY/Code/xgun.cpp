#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int a[100005];
int seg[N * 4], lazy[N * 4];
void build(int id, int l, int r)
{
    if (l == r) return seg[id] = a[l], void();
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void down(int id, int l, int r)
{
    if (lazy[id] != -1)
    {
        int tmp = lazy[id], mid = (l + r) >> 1;
        seg[id * 2] = (mid - l + 1) * tmp;
        seg[id * 2 + 1] = (r - mid) * tmp;
        lazy[id * 2] = lazy[id * 2 + 1] = tmp;
        lazy[id] = -1;
    }
}
void update(int id, int l, int r, int u, int v, int val)
{
    if (u > r || v < l) return;
    if (u <= l && r <= v)
    {
        seg[id] = (r - l + 1) * val;
        lazy[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    down(id, l, r);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
int get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    down(id, l, r);
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(lazy, -1, sizeof(lazy));
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int m; cin >> m;
    while (m--)
    {
        int pos, l; cin >> pos >> l;
        int val = get(1, 1, n, pos, pos);
        cout << get(1, 1, n, pos, pos + l) - (l + 1) * val << '\n';
        update(1, 1, n, pos, pos + l, val);
    }
}
