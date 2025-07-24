#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int a[100005], b[100005], pos[100005];
struct node
    {
        int len, cnt;
        node friend operator + (node &a, node &b)
        {
            if (a.len < b.len) return b;
            if (b.len < a.len) return a;
            return (node){a.len, (a.cnt + b.cnt) % mode};
        }
    };
struct Segmentree
{
    vector <node> seg;
    int n;
    Segmentree (int _n)
    {
        n = _n;
        seg.assign(n * 4 + 5, (node){0, 0});
    }
    void update(int id, int l, int r, int pos, node val)
    {
        if (pos > r || pos < l) return;
        if (l == r && pos == l)
        {
            seg[id] = seg[id] + val;
            return;
        }
        int mid = (l + r) >> 1;
        update(id * 2, l, mid, pos, val);
        update(id * 2 + 1, mid + 1, r, pos, val);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }
    node get(int id, int l, int r, int u, int v)
    {
        if (u > r || v < l) return (node){0, 0};
        if (u <= l && r <= v) return seg[id];
        int mid = (l + r) >> 1;
        node t1 = get(id * 2 + 1, mid + 1, r, u, v);
        node t2 = get(id * 2, l, mid, u, v);
        return (node){t1 + t2};
    }
    void update(int pos, node val)
    {
        update(1, 1, n, pos, val);
    }
    node get(int l, int r)
    {
        return get(1, 1, n, l, r);
    }
};
vector <int> g[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        for (int k = max(1ll, b[i] - x); k <= min(b[i] + x, n); k++)
            g[i].push_back(pos[k]);
        sort(g[i].begin(), g[i].end(), greater<int>());
    }
    Segmentree st(n);
    for (int i = 1; i <= n; i++)
    {
        for (int p : g[i])
        {
            node tmp = st.get(1, p - 1);
            if (tmp.len == 0) tmp = (node){1, 1};
            else tmp.len++;
            st.update(p, tmp);
        }
    }
    cout << st.seg[1].len << ' ' << st.seg[1].cnt;
}
