#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> par, sz;
    int MAX = 0;
    DSU (int n)
    {
        par.resize(n + 1, 0);
        sz.resize(n + 1, 0);
    }
    void add(int id)
    {
        par[id] = id;
        sz[id] = 1;
        if (!MAX) MAX = 1;
    }
    int Find(int v) {return (v == par[v]? v : par[v] = Find(par[v]));}
    void Union(int a, int b)
    {
        a = Find(a), b = Find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        MAX = max(MAX, sz[a]);
    }
};
struct node
{
    int val, id;
    bool operator < (const node &other) const{
        return val < other.val;
    }
}a[100005], Q[100005];
int ans[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].val;
        a[i].id = i;
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> Q[i].val;
        Q[i].id = i;
    }
    sort(a + 1, a + n + 1);
    sort(Q + 1, Q + q + 1);
    int l = 1;
    DSU d(n + 5);
    for (int i = 1; i <= q; i++)
    {
        while (a[l].val <= Q[i].val && l <= n)
        {
            d.add(a[l].id);
            if (d.Find(a[l].id - 1) != 0) d.Union(a[l].id, a[l].id - 1);
            if (d.Find(a[l].id + 1) != 0) d.Union(a[l].id, a[l].id + 1);
            ++l;
        }
        ans[Q[i].id] = d.MAX;
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';

}
