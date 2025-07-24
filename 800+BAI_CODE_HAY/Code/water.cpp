#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define l first
#define r second
const int N = 2e5 + 5;
int up[100005][18], f[100005][18];
int seg[N * 4];
ii a[100005];
void update(int id, int l, int r, int pos, int val)
{
    if (pos > r || pos < l) return;
    if (l == r && pos == l)
    {
        seg[id] = (a[seg[id]].r < a[val].r? val : seg[id]);
        return;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    seg[id] = (a[seg[id * 2]].r > a[seg[id * 2 + 1]].r? seg[id * 2] : seg[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    int id1 = get(id * 2, l, mid, u, v), id2 = get(id * 2 + 1, mid + 1, r, u, v);
    return (a[id1].r > a[id2].r? id1 : id2);
}

int lift(int k, int v)
{
    int res = 0;
    for (int i = 17; i >= 0; i--)
        if (k >> i & 1)
        {
            res = max(res, f[v][i]);
            v = up[v][i];
        }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].l >> a[i].r;
        if (a[i].r < a[i].l) a[i].r += n;
    }
    sort(a + 1, a + m + 1, [](ii a, ii b)
        {
            return (a.r == b.r? a.l < b.l : a.r < b.r);
        });
    for (int x = m; x >= 1; x--)
    {
        int pos = get(1, 1, 2 * n, a[x].l, a[x].r + 1);
        up[x][0] = pos;
        f[x][0] = a[pos].r;
        for (int i = 1; i <= 17; i++)
        {
            f[x][i] = max(f[x][i - 1], f[up[x][i - 1]][i - 1]);
            up[x][i] = up[up[x][i - 1]][i - 1];
        }
        update(1, 1, 2 * n, a[x].l, x);
    }
    int ans = m + 1;
    for (int i = 1; i <= m; i++)
    {
        if (a[i].r - a[i].l + 1 >= n) ans = 1;
        int l = 1, r = m;
        int res = m + 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            int k = lift(mid, i);
            if (k - a[i].l + 1 >= n) res = mid + 1, r = mid - 1;
            else l = mid + 1;
        }
        ans = min(ans, res);
    }
    cout << m - ans;

}
