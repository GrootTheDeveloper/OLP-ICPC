#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>

map <ii, int> mp;
int ans, x[50], y[50], mid, n, a, b;
bool mark[50];

void check(int lim)
{
    int bg = ((lim == mid) ? 1 : mid + 1);
    int idx = 0, idy = 0;
    for (int i = bg; i <= lim; i++)
    {
        idx += mark[i] * x[i];
        idy += mark[i] * y[i];
    }
    if (lim == mid) ++mp[{idx,idy}];
    else if (mp.find({a - idx, b - idy}) != mp.end()) ans += mp[{a - idx, b - idy}];
}
void Try(int i, int lim)
{
    if (i == lim + 1) return check(lim), void();
    mark[i] = 1;
    Try(i + 1, lim);
    mark[i] = 0;
    Try(i + 1, lim);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)  cin >> x[i] >> y[i];
    mid = n / 2;
    Try(1, mid);
    Try(mid + 1, n);
    cout << ans;
}
