#include <bits/stdc++.h>
    using namespace std;
    #define int long long
    int a[100005], p[18];
    int len(int n)
    {
        int res = 0;
        while (n) res++, n/=10;
        return res;
    }

    signed main()
    {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int t; cin >> t;
        p[0] = 1;
        for (int i = 1; i <= 17; i++) p[i] = p[i - 1] * 10;
        while (t--)
        {
            int n, L, R; cin >> n >> L >> R;
            for (int i = 1; i <= n; i++) cin >> a[i];
            sort(a + 1, a + n + 1);
            //cout << calc(n, L, R) << ' ';
            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                int k = len(a[i]);
                int l = (L - a[i] + p[k] - 1) / p[k];
                int r = (R - a[i]) / p[k];
                if (l <= r) ans += upper_bound(a + 1, a + n + 1, r) - lower_bound(a + 1, a + n + 1, l);
            }
            cout << ans << '\n';
        }

    }
