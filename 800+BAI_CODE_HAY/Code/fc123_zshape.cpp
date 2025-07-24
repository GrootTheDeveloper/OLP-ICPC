#include <bits/stdc++.h>
using namespace std;
const int N = 1004;
struct Segmentree
{
    vector<long long> seg;
    vector<int> lazy;
    int n;
    void init(int _n)
    {
        n = _n;
        seg.resize(n * 4 + 5, 0);
        lazy.resize(n * 4 + 5, 0);
    }
    void reset()
    {
        fill(seg.begin(), seg.end(), 0);
        fill(lazy.begin(), lazy.end(), 0);
    }
    void down(int id, int l, int r)
    {
        if (lazy[id])
        {
            int mid = (l + r) >> 1, tmp = lazy[id];
            seg[id * 2] += tmp * (mid - l + 1);
            seg[id * 2 + 1] += tmp * (r - mid);
            lazy[id * 2] += tmp;
            lazy[id * 2 + 1] += tmp;
            lazy[id] = 0;
        }
    }
    void update(int id, int l, int r, int u, int v, int val)
    {
        if (u > r || v < l) return;
        if (u <= l && r <= v)
        {
            seg[id] += val * (r - l + 1);
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }
    long long get(int id, int l, int r, int u, int v)
    {
        if (u > r || v < l) return 0;
        if (u <= l && r <= v) return seg[id];
        down(id, l, r);
        int mid = (l + r) >> 1;
        return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
    }
    void update(int l, int r, int val)
    {
        update(1, 1, n, l, r, val);
    }
    long long get(int l, int r)
    {
        return get(1, 1, n, l, r);
    }
};
Segmentree tree[3003];
int l[N][N], r[N][N], a[N][N], type[N][N];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m, n; cin >> m >> n;
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    {
        char c; cin >> c;
        a[i][j] = c - '0';
    }
    int k = 0;
    for (int i = 1; i <= n; i++) type[1][i] = ++k, tree[k].init(i + 1);
    for (int i = 2; i <= m; i++) type[i][n] = ++k, tree[k].init(n);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if (!type[i][j]) type[i][j] = type[i - 1][j + 1];
            if(a[i][j]) l[i][j] = l[i][j - 1] + 1;
        }
        for (int j = n; j >= 1; j--)
            if(a[i][j]) r[i][j] = r[i][j + 1] + 1;
    }
    long long ans = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int id = type[i][j];
            if (a[i][j] == 0 && a[i - 1][j + 1] != 0) tree[id].reset();

            if (a[i][j])
            {
                int rig = r[i][j] - 1;
                if(rig) ans += tree[id].get(1, rig);
                int lef = l[i][j] - 1;
                if (lef) tree[id].update(1, lef, 1);
            }
        }
    }
    cout << ans;
}
