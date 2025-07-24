#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
int trace[200005];
ii a[100005];
vector<int> b;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].se >> a[i].fi, b.push_back(a[i].se - a[i].fi), b.push_back(a[i].se + a[i].fi);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int left = lower_bound(b.begin(), b.end(), a[i].se - a[i].fi) - b.begin() + 1;
        int rig  = lower_bound(b.begin(), b.end(), a[i].se + a[i].fi) - b.begin() + 1;
        int x = rig;
        while (trace[x] && trace[x] >= left) x = trace[x];
        if (x == left) ans += 2;
        else ans += 1;
        trace[rig] = left;
    }
    cout << ans + 1;
}
