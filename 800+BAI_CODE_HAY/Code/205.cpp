#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
const int inf = 1e15;
int seg[N * 4], lazy[N * 4], n, q;

void down(int id)
{
    if (lazy[id] != inf)
    {
        seg[id * 2] = min(seg[id * 2], lazy[id]);
        seg[id * 2 + 1] = min(seg[id * 2 + 1], lazy[id]);
        lazy[id * 2] = min(lazy[id], lazy[id * 2]);
        lazy[id * 2 + 1] = min(lazy[id * 2 + 1], lazy[id]);
        lazy[id] = inf;
    }
}
void update(int id, int l, int r, int u, int v, int val)
{
    if (u > r || v < l) return;
    if (u <= l && r <= v)
    {
        seg[id] = min(seg[id], val);
        lazy[id] = min(lazy[id],val);
        return;
    }
    down(id);
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
void Up(int l, int r, int val)
{
    update(1, 1, n, l, r, val);
}
int get(int id, int l, int r, int pos)
{
    if (pos > r || pos < l) return inf;
    if (l == r && pos == l) return seg[id];
    int mid = (l + r) >> 1;
    down(id);
    return min(get(id * 2, l, mid, pos), get(id * 2 + 1, mid + 1, r, pos));
}
int Get(int pos)
{
    if (pos == 0) return 0;
    return get(1, 1, n, pos);
}
struct node
{
    int l, r, c;
    bool operator < (const node &other)
    {
        return (r == other.r? l < other.l : r < other.r);
    }
}op[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
        cin >> op[i].l >> op[i].r >> op[i].c;
    sort(op + 1, op + q + 1);
    fill(seg + 1, seg + n * 4 + 1, inf);
    fill(lazy + 1, lazy + n * 4 + 1, inf);
    for (int i = 1; i <= q; i++)
    {
        int val = Get(op[i].l - 1) + op[i].c;
        Up(op[i].l, op[i].r, val);
    }
    int ans = Get(n);
    cout << (ans == inf? -1 : ans);
}