#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;
int dp1[40004], dp2[40004];
void add(int &a, int b)
{
    a += b;
    if (a >= mode) a -= mode;
}
void solve()
{
    int n, A; cin >> n >> A;
    fill(dp1, dp1 + n * 200 + 1, 0);
    fill(dp2, dp2 + n * 200 + 1, 0);
    int sum1 = 0, sum2 = 0;
    dp1[0] = dp2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int ai; cin >> ai;
        ai -= A;
        if (ai >= 0)
        {
            sum1 += ai;
            for (int j = sum1; j >= ai; j--)
                add(dp1[j], dp1[j - ai]);
        }else{
            ai = -ai;
            sum2 += ai;
            for (int j = sum2; j >= ai; j--)
                add(dp2[j], dp2[j - ai]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= sum1; i++)
        add(ans, 1ll * dp1[i] * dp2[i] % mode);
    add(ans, dp1[0] - 1);
    cout << ans << '\n';

}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}
