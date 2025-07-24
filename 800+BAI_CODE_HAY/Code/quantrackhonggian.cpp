#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define iii pair<ii, int>
#define fi first
#define se second

bool cmp(iii a, iii b)
{
    return (a.fi.fi == b.fi.fi? a.fi.se < b.fi.se : a.fi.fi < b.fi.fi);
}
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
ii frac(int a, int b)
{
    int x = gcd(a, b);
    return {a/x, b/x};
}
iii v[1000006];
int va[1003], vb[1003];
int a[1003], b[1003];
int da[1003], db[1003];
void solve()
{
    int m, n; cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    sort(a + 1, a + m + 1);
    sort(b + 1, b + n + 1);

    int la = 0, lb = 0;
    for (int i = 1; i <= m; i++)
    if (a[i] != a[i - 1])
    {
        int pos = upper_bound(a + i, a + m + 1, a[i]) - a;
        va[++la] = a[i];
        da[la] = pos - i;
    }

    for (int i = 1; i <= n; i++)
    if (b[i] != b[i - 1])
    {
        int pos = upper_bound(b + i, b + n + 1, b[i]) - b;
        vb[++lb] = b[i];
        db[lb] = pos - i;
    }

    int lim = 0;
    for (int i = 1; i <= la; i++)
    for (int j = 1; j <= lb; j++)
        v[++lim] = {frac(va[i], vb[j]), min(da[i], db[j])};
    sort(v + 1, v + lim + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= lim; i++)
    {
        int j = i;
        int cnt = v[i].se;
        while (v[j + 1].fi.fi == v[i].fi.fi && v[j + 1].fi.se == v[i].fi.se && j < lim) j++, cnt += v[j].se;
        ans = max(ans, cnt);
        i = j;
    }
    cout << m + n - ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}
