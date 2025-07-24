#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int mode = 1e9 + 7;
const int N = 2e5 + 5;
ii seg[N * 4];
ii a[N];
int pin(int l, int r, int x)
{
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (a[mid].fi >= x) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}
ii orz(ii a, ii b)
{
    if (a.fi < b.fi) return a;
    if (b.fi < a.fi) return b;
    return {a.fi, (a.se + b.se) % mode};
}

void update(int id, int l, int r, int pos, ii x)
{
    if (pos > r || pos < l) return;
    if (l == r && pos == l) return seg[id] = x, void();
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, x);
    update(id * 2 + 1, mid + 1, r, pos, x);
    seg[id] = orz(seg[id * 2], seg[id * 2 + 1]);
}

ii get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return {INT_MAX, 0};
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    return orz(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + n + 1, greater<ii>());

    for (int i = 1; i <= n; i++)
    {
        int pos = pin(1, i - 1, a[i].se);
        if (pos == 0) update(1, 1, n, i, {a[i].fi, 1});
        else
        {
            ii top = get(1, 1, n, 1, pos);
            update(1, 1, n, i, {top.fi - a[i].se + a[i].fi, top.se});
        }
    }
    cout << seg[1].fi << ' ' << seg[1].se;
}
