#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
ii a[100005];
int n;
long long calc()
{
    long long ans = 0, sum = 0;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        ans += 1ll * a[i].fi * (i - 1) - sum;
        sum += a[i].fi;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    long long ans = 0;
    ans += calc();
    for (int i = 1; i <= n; i++)
        swap(a[i].fi, a[i].se);
    ans += calc();
    cout << ans;
}
