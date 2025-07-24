#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 2e6 + 5;
int seg[3][N * 4], L[3][N], prmin[N], prmax[N], sufmax[N], sufmin[N], c[N], s[N];
int n;
int pin_max(int l, int r, int val)
{
    int ans = 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (prmax[mid] > val) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}
int pin_min(int l, int r, int val)
{
    int ans = 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (prmin[mid] < val) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}
void build(int kind, int id, int l, int r)
{
    if (l == r) return seg[kind][id] = L[kind][l], void();
    int mid = (l + r) >> 1;
    build(kind, id * 2, l, mid);
    build(kind, id * 2 + 1, mid + 1, r);
    seg[kind][id] = min(seg[kind][id * 2], seg[kind][id * 2 + 1]);
}
int get(int kind, int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return INT_MAX;
    if (u <= l && r <= v) return seg[kind][id];
    int mid = (l + r) >> 1;
    return min(get(kind, id * 2, l, mid, u, v), get(kind, id * 2 + 1, mid + 1, r, u, v));
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   // freopen("test.INP","r",stdin);
   // freopen("TEST.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i] >> s[i];
    prmin[1] = prmax[1] = s[1];
    for (int i = 2; i <= n; i++)
    {
        prmin[i] = min(prmin[i - 1], s[i]);
        prmax[i] = max(prmax[i - 1], s[i]);
        L[0][i] = -c[i] + prmax[i] - prmin[i];
        L[1][i] = -c[i] - prmin[i];
        L[2][i] = -c[i] + prmax[i];

    }
    build(0, 1, 1, n);
    build(1, 1, 1, n);
    build(2, 1, 1, n);
    sufmin[n] = sufmax[n] = s[n];
    for (int i = n - 1; i >= 1; i--)
    {
        sufmax[i] = max(sufmax[i + 1], s[i]);
        sufmin[i] = min(sufmin[i + 1], s[i]);
    }
    int ans = INT_MAX;
    for (int i = 2; i <= n; i++)
    {
        int p1 = pin_min(1, i - 1,s[i]);
        int p2 = pin_max(1, i - 1,s[i]);
        ans = min(ans, c[i] - c[min(p1,p2)] + sufmax[i] - sufmin[i]);
        ans = min(ans, c[i] + get(0, 1, 1, n, max(p1, p2), i - 1));
        if (p2 <= p1)  ans = min(ans, c[i] + sufmax[i] + get(1, 1, 1, n, p2, p1));
        if (p1 <= p2)  ans = min(ans, c[i] + sufmin[i] + get(2, 1, 1, n, p1, p2));
    }
    cout << ans;
}
