#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
bool prime[101];
int lim;
vector<int> p;
void init()
{
    for (int i = 2; i <= 100; i++)
        if (!prime[i])
        {
            p.push_back(i);
            for (int j = i * i; j <= 100; j += i)
                prime[j] = true;
        }
    lim = p.size();
}
int seg[N * 4][26];
int a[N];
void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r) return;
    if (l == r && pos == l)
    {
        for (int i = 0; i < lim; i++)
            while (val % p[i] == 0) seg[id][i]++, val /= p[i];
        return;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    for (int i = 0; i < lim; i++)
        seg[id][i] = seg[id * 2][i] + seg[id * 2 + 1][i];
}
int ans[26];
void get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return;
    if (u <= l && r <= v)
    {
        for (int i = 0; i < lim; i++)
            ans[i] += seg[id][i];
        return;
    }
    int mid = (l + r) >> 1;
    get(id * 2, l, mid, u, v);
    get(id * 2 + 1, mid + 1, r, u, v);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], update(1, 1, n, i, a[i]);
    int q; cin >> q;
    while (q--)
    {
        int kind, u, v; cin >> kind >> u >> v;
        if (kind == 1)
        {
            memset(ans, 0, sizeof(ans));
            get(1, 1, n, u, v);
            bool ok = true;
            for (int i = 0; i < lim; i++)
                if (ans[i]&1) ok = false;
            cout << (ok? "YES" : "NO") << '\n';
        } else update(1, 1, n, u, v);
    }
}
