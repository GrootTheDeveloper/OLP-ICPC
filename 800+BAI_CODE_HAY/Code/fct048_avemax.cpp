#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int ans = -1e9;
    for (int i = 1; i <= n; i++)
    {
        int ai; cin >> ai;
        ans = max(ai, ans);
    }
    cout << ans;
}
