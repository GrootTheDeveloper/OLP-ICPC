#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt[1200000][2];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    cnt[0][0] = 1;
    int cur = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int ai; cin >> ai;
        cur = cur ^ ai;
        ans += cnt[cur][i % 2];
        cnt[cur][i % 2]++;
    }
    cout << ans;
}
