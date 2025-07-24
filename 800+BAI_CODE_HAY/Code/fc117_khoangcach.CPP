#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

const int N = 1e5;
int sum[100005], cnt[100005];
ii a[100005];
void update(int idx, int val, int x)
{
    for (; idx <= N; idx += idx & -idx)
        sum[idx] += val, cnt[idx] += x;
}
ii get(int idx)
{
    ii ans = {0, 0};
    for(; idx; idx -= idx & -idx)
        ans.fi += sum[idx], ans.se += cnt[idx];
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi;
    vector<int> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i].se, b.push_back(a[i].se);

    sort(a + 1, a + n + 1);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int l = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (a[l].fi != a[i].fi)
        {
            int pos = lower_bound(b.begin(), b.end(), a[l].se) - b.begin() + 1;
            update(pos, -a[l].fi, 1);
            l++;
        }

        int pos = lower_bound(b.begin(), b.end(), a[i].se) - b.begin() + 1;
        ii tmp = get(pos);
        ans += a[i].fi * tmp.se + tmp.fi;
    }
    cout << ans;


}
