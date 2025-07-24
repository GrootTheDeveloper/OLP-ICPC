#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const int N = 1e5 + 5;
struct node
{
    int l, r, val, id;
    bool operator < (const node &other) const
    {
        return val > other.val;
    }
}Q[100005];
int a[N], b[N], ans[N];
int seg[N * 4];

bool cmp(int x, int y)
{
    return a[x] > a[y];
}



void update(int id, int l, int r, int pos)
{
    if (pos > r || pos < l) return;
    if (l == r && pos == l)
        return seg[id] = a[pos], void();
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos);
    update(id * 2 + 1, mid + 1, r, pos);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return inf;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    iota(b + 1, b + n + 1, 1);
    sort(b + 1, b + n + 1, cmp);

    for (int i = 1; i <= q; i++)
    {
        cin >> Q[i].l >> Q[i].r >> Q[i].val;
        Q[i].id = i;
    }
    sort(Q + 1, Q + q + 1);

    int id = 1;
    fill(seg + 1, seg + n * 4 + 1, inf);
    for (int i = 1; i <= q; i++)
    {
        while (id <= n && a[b[id]] >= Q[i].val)
            update(1, 1, n, b[id]), id++;
        ans[Q[i].id] = get(1, 1, n, Q[i].l, Q[i].r);
    }
    for (int i = 1; i <= q; i++)
        cout << (ans[i] == inf? -1 : ans[i]) << '\n';
}
