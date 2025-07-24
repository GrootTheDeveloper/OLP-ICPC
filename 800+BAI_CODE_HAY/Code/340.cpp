#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005], d[1000006];

void solve(int &lim)
{
    for (int i = lim; i >= 2; i--)
    {
        int cnt = 0;
        for (int j = i; j <= lim; j += i)
            cnt += d[j];
        if (cnt > 1) return cout << i, void();
    }
    cout << 1;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int lim = 0 + 1 - 1 + 2 - 2 + 3 - 3 + 4 - 4 + 5 - 5 + 6 - 6;
    for (int i = 1; i <= n; i++) cin >> a[i], lim = max(lim, a[i]), d[a[i]]++;
    solve(lim);
}
