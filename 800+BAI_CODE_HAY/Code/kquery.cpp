#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e4 + 5;
struct node
{
    int l, r, k, idx;
    bool operator < (const node &other)
    {
        return k > other.k;
    }
}Q[200005];
int ans[200005], a[N], b[N];
int seg[N * 4];
void update(int id, int l, int r, int pos)
{
    if (pos > r || pos < l) return;
    if (l == r && pos == l) return seg[id] = 1, void();
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos);
    update(id * 2 + 1, mid + 1, r, pos);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
int get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    iota(b + 1, b + n + 1, 1);
    sort(b + 1, b + n + 1, [](int x, int y)
        {
            return a[x] > a[y];
        });
    int q; cin >> q;
    for (int i = 1; i <= q; i++)
        cin >> Q[i].l >> Q[i].r >> Q[i].k, Q[i].idx = i;
    sort(Q + 1, Q + q + 1);
    int l = 1;
    for (int i = 1; i <= q; i++)
    {
        while (a[b[l]] > Q[i].k && l <= n)
            update(1, 1, n, b[l++]);
        ans[Q[i].idx] = get(1, 1, n, Q[i].l, Q[i].r);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}
