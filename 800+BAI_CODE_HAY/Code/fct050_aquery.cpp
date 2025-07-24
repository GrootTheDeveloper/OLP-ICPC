#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long seg[N * 4], lz1[N * 4], lz2[N * 4];
int n, q;
void down(int id, int l, int r)
{
    if (lz2[id])
    {
        int mid = (l + r) >> 1;
        long long tmp = lz2[id];
        seg[id * 2] = 1ll * (mid - l + 1) * tmp;
        seg[id * 2 + 1] = 1ll * (r - mid) * tmp;
        lz2[id * 2] = lz2[id * 2 + 1] = tmp;
        lz1[id * 2] = lz1[id * 2 + 1] = 0;
        lz2[id] = 0;
    }

    if (lz1[id])
    {
        int mid = (l + r) >> 1;
        long long tmp = lz1[id];
        seg[id * 2] += 1ll * (mid - l + 1) * tmp;
        seg[id * 2 + 1] += 1ll * (r - mid) * tmp;
        lz1[id * 2] += tmp;
        lz1[id * 2 + 1] += tmp;
        lz1[id] = 0;
    }


}
void update(int id, int l, int r, int u, int v, int val)
{
    if (u > r || v < l) return;
    if (u <= l && r <= v)
    {
        seg[id] += 1ll * (r - l + 1) * val;
        lz1[id] += val;
        return;
    }
    int mid = (l + r) >> 1;
    down(id, l, r);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void update_set(int id, int l, int r, int u, int v, int val)
{
    if (u > r || v < l) return;
    if (u <= l && r <= v)
    {
        seg[id] = 1ll * val * (r - l + 1);
        lz2[id] = val;
        lz1[id] = 0;
        return;
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    update_set(id * 2, l, mid, u, v, val);
    update_set(id * 2 + 1, mid + 1, r, u, v, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
long long get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    down(id, l, r);
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
void solve(int pos, int k)
{
    int l = 1, r = pos;
    int ans = pos;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        long long  val = get(1, 1, n, mid, mid);
        if (val * (pos - mid + 1) - get(1, 1, n, mid, pos) <= k)
            ans = mid, r = mid - 1;
        else l = mid + 1;
    }

    long long tmp = get(1, 1, n, ans, ans);
    k -= (pos - ans + 1) * tmp - get(1, 1, n, ans, pos);
    update_set(1, 1, n, ans, pos, tmp);

    int inc = k / (pos - ans + 1);
    update(1, 1, n, ans, pos, inc);
    k -= inc * (pos - ans + 1);
    update(1, 1, n, ans, ans + k - 1, 1);
}
int b[1000];
void brute(int pos, int k)
{
    while(k--)
    {
        int id = 1;
        for (int i = 1; i <= pos; i++)
        if (b[i] < b[id]) id = i;
        b[id]++;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    while (q--)
    {
        int pos, k; cin >> pos >> k;
        solve(pos, k);
    }
    for (int i = 1; i <= n; i++)
        cout << get(1, 1, n, i, i) << ' ';
//    cout << '\n';
//    for (int i = 1; i <= n; i++)
//        cout << b[i] << ' ';

}
