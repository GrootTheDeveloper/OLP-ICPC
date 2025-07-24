#include <bits/stdc++.h>
using namespace std;

int cnt[1000006], suf[1000006], pre[1000006], a[1000006];
int l[1000006], r[1000006];
int n;

void solve()
{
    int n; cin >> n;
    vector<int> b;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i], b.push_back(l[i]), b.push_back(r[i]);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    fill(cnt, cnt + b.size() + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int L = lower_bound(b.begin(), b.end(), l[i]) - b.begin() + 1;
        int R = lower_bound(b.begin(), b.end(), r[i]) - b.begin() + 1;
        cnt[L]++, cnt[R + 1]--;
        l[i] = L;
        r[i] = R;
    }
    int lim = b.size();
    for (int i = 1; i <= lim; i++)
        cnt[i] += cnt[i - 1], pre[i] = max(pre[i - 1], cnt[i]);
    suf[lim + 1] = 0;
    for (int i = lim; i >= 1; i--)
        suf[i] = max(suf[i + 1], cnt[i]);

    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
        ans = min(ans, max({pre[l[i] - 1], pre[r[i]] - 1, suf[r[i] + 1]}));

    cout << ans << '\n';

}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
}
