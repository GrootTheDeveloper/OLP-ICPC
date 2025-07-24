
#include <bits/stdc++.h>
using namespace std;
#define int long long
int mid, a[50];
int mark[50];
const int maxn = 1e6 + 5e4, mode = 1e9;
int v1[maxn], v2[maxn], len1, len2;

void check(int lim)
{
    int bg = ((lim == mid)? 1 : mid + 1);
    int s = 0;
    for (int i = bg; i <= lim; i++) s += mark[i] * a[i];
    if (lim == mid) v1[++len1] = s % mode;
    else v2[++len2] = s % mode;
}

void Try(int i, int lim)
{
    if (i > lim) return check(lim), void();
    mark[i] = 1;
    Try(i + 1, lim);
    mark[i] = 0;
    Try(i + 1, lim);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    mid = n / 2;
    Try(1, mid);
    Try(mid + 1, n);
    sort(v1 + 1, v1 + len1 + 1);
    sort(v2 + 1, v2 + len2 + 1);
    int res = 0;
    for (int i = 1; i <= len1; i++)
    {
        int pos = lower_bound(v2 + 1, v2 + len2 + 1, mode - v1[i]) - v2;
        res = max({res, (v1[i] + v2[pos]) % mode, (v1[i] + v2[pos - 1]) % mode});
    }
    cout << res;
}
