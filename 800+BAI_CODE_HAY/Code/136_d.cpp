#include <bits/stdc++.h>
using namespace std;
//#define int long long
int a[100005];
vector <vector<int>> d;
vector <int> vec, pre;
int cnt[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] <= n) cnt[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] >= i)
        {
            pre.assign(n + 1, 0);
            for (int j = 1; j <= n; j++)
                pre[j] = pre[j - 1] + (a[j] == i);
            d.push_back(pre);
            vec.push_back(i);
        }
    }
    while (q--)
    {
        int l, r; cin >> l >> r;
        int ans = 0;
        for (int i = 0; i < vec.size(); i++)
            ans += (d[i][r] - d[i][l - 1] == vec[i]);
        cout << ans << '\n';
    }

}
