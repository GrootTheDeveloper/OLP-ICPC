#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;
struct node
{
    int x, y;
    bool operator < (const node &other)
    {
        return (x == other.x? y > other.y : x > other.x);
    }
}a[2003];
struct Segmetree
{
    vector<int> seg;
    int n;
    void init(int _n)
    {
        n = _n;
        seg.resize(n * 4 + 1, 0);
    }
    void update(int id, int l, int r, int pos, int val)
    {
        if (pos > r || pos < l) return;
        if (l == r && pos == l)
            return seg[id] += val, void();
        int mid = (l + r) >> 1;
        update(id * 2, l, mid, pos, val);
        update(id * 2 + 1, mid + 1, r, pos, val);
        seg[id] = (seg[id * 2] + seg[id * 2 + 1]) % mode;
    }
    int get(int id, int l, int r, int u, int v)
    {
        if (u > r || v < l) return 0;
        if (u <= l && r <= v) return seg[id];
        int mid = (l + r) >> 1;
        return (get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v)) % mode;
    }
}tree[2003];
int dp[2003], b[2003];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x;
    for (int i = 1; i <= n; i++)
        cin >> a[i].y;
    sort(a + 1, a + n + 1);
    iota(b + 1, b + n + 1, 1);
    sort(b + 1, b + n + 1, [](int x, int y)
    {
        return (a[x].y == a[y].y? x > y : a[x].y < a[y].y);
    });
    for (int i = 1; i <= n; i++)
        tree[i].init(n);
    for (int i = 1; i <= n; i++)
    {
        int pos = b[i];
        tree[1].update(1, 1, n, pos, 1);

        for (int l = 2; l <= i; l++)
        {
            int ans = tree[l - 1].get(1, 1, n, 1, pos - 1);
            dp[l] += ans, dp[l] %= mode;
            tree[l].update(1, 1, n, pos, ans);
        }
    }
    cout << n << ' ';
    for (int i = 2; i <= n; i++)
        cout << dp[i] << ' ';
}
