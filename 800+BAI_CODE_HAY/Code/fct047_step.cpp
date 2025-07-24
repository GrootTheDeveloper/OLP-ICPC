#include <bits/stdc++.h>
#define sz(s) (int)s.size()
using namespace std;
const int N = 2e5 + 5;
const long long inf = -1e14;
int a[N], S[N], pos[N], Q[100005];

struct node
{
    long long ans, sum, pre, suf;
    node() : ans(0), sum(0), pre(0), suf(0) {}
    node (long long a, long long b, long long c, long long d): ans(a), sum(b), pre(c), suf(d){}
    node operator+(const node &other)
    {
        return node(max({ans, other.ans, suf + other.pre}), sum + other.sum, max(pre, sum + other.pre), max(other.suf, suf + other.sum));
    }
};
node seg[2][N * 4];
void Assign(int id, int l, int r)
{
    if (l == r)
    {
        seg[0][id] = node(inf, inf, inf, inf);
        seg[1][id] = node(S[l], S[l], S[l], S[l]);
        return;
    }
    int mid = (l + r) >> 1;
    Assign(id * 2, l, mid);
    Assign(id * 2 + 1, mid + 1, r);
    seg[0][id] = seg[0][id * 2] + seg[0][id * 2 + 1];
    seg[1][id] = seg[1][id * 2] + seg[1][id * 2 + 1];
}
void update(int k, int id, int l, int r, int pos, long long val)
{
    if (pos > r || pos < l) return;
    if (l == r && pos == l)
    {
        seg[k][id] = node(val, val, val, val);
        return;
    }
    int mid = (l + r) >> 1;
    update(k, id * 2, l, mid, pos, val);
    update(k, id * 2 + 1, mid + 1, r, pos, val);
    seg[k][id] = seg[k][id * 2] + seg[k][id * 2 + 1];
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> b;
    for (int i = 1; i <= q; i++)
    {
        cin >> Q[i];
        b.push_back(Q[i]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int lim = 0;
    if (b[0] != 1)
        S[++lim] = b[0] - 1;
    for (int i = 1; i <= sz(b); i++)
    {
        pos[i] = ++lim;
        S[lim] = 1;
        if (i < sz(b))
        {
            if (b[i] - b[i - 1] > 1)
            {
                ++lim;
                S[lim] = b[i] - b[i - 1] - 1;
            }
        }
    }
    if (b.back() != n)
        S[++lim] = n - b.back();
    Assign(1, 1, lim);
    fill(a + 1, a + lim + 1, 1);
    for (int i = 1; i <= q; i++)
    {
        int p = Q[i];
        p = lower_bound(b.begin(), b.end(), p) - b.begin() + 1;
        p = pos[p];
        if (a[p])
        {
            update(1, 1, 1, lim, p, inf);
            update(0, 1, 1, lim, p, 1);
            a[p] = 0;
        }else{
            update(1, 1, 1, lim, p, 1);
            update(0, 1, 1, lim, p, inf);
            a[p] = 1;
        }
        cout << max(seg[0][1].ans, seg[1][1].ans) << '\n';
    }

}
