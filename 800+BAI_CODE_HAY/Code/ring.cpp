    #include <bits/stdc++.h>
    using namespace std;
    #define ii pair<int,int>
    #define l first
    #define r second
    const int inf = 1e9;
    const int N = 3e5 + 5;
    int seg[N * 4], up[N][20];
    ii a[N];
    void update(int id, int l, int r, int pos, int x)
    {
        if (pos > r || pos < l) return;
        if (l == r && pos == l)
        {
            if (a[seg[id]].r > a[x].r) seg[id] = x;
            return;
        }
        int mid = (l + r) >> 1;
        update(id * 2, l, mid, pos, x);
        update(id * 2 + 1, mid + 1, r, pos, x);
        seg[id] = (a[seg[id * 2]].r < a[seg[id * 2 + 1]].r? seg[id * 2] : seg[id * 2 + 1]);
    }
    int get(int id, int l, int r, int u, int v)
    {
        if (u > r || v < l) return 0;
        if (u <= l && r <= v) return seg[id];
        int mid = (l + r) >> 1;
        int t1 = get(id * 2, l, mid, u, v);
        int t2 = get(id * 2 + 1, mid + 1, r, u, v);
        return (a[t1].r < a[t2].r? t1 : t2);
    }
    int lift(int k, int v)
    {
        for (int i = 18; i >= 0; i--)
            if (k >> i & 1) v = up[v][i];
        return v;
    }
    signed main()
    {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int n, m; cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> a[i].l >> a[i].r;
            if (a[i].l > a[i].r) a[i].r += n;
        }
        sort(a + 1, a + m + 1, [](ii a, ii b)
        {
            return a.l < b.l;
        });
        a[0].r = inf;
        for (int i = 1; i <= m; i++)
            update(1, 1, n, a[i].l, i);
        for (int i = m; i >= 1; i--)
        {
            int p = get(1, 1, n, a[i].r + 1, n);
            up[i][0] = p;
            for (int j = 1; j <= 18; j++)
                up[i][j] = up[up[i][j - 1]][j - 1];
        }
        int ans = 1;
        for (int i = 1; i <= m; i++)
        {
            int res = 0;
            int l = 1, r = m;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                int x = lift(mid, i);
                if (a[x].r - a[i].l + 1 <= n) res = mid + 1, l = mid + 1;
                else r = mid - 1;
            }
            ans = max(ans, res);
        }
        cout << ans;
    }
