#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define val first
#define idx second

priority_queue <ii> qmax;
priority_queue <ii, vector<ii>, greater<ii>> qmin;
int n, k, a[300005];
int dp[300005];
int pre[300005];
int getmin(int x)
{
    while (qmin.top().idx < x) qmin.pop();
    return qmin.top().val;
}
int getmax(int x)
{
    while (qmax.top().idx < x) qmax.pop();
    return qmax.top().val;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    int res = 0;
    int l = 1;
    for (int i = 1; i <= n; i++)
    {
        qmax.push({a[i],i});
        qmin.push({a[i],i});
        int mx = getmax(l), mi = getmin(l);
        while (mx - mi > k)
        {
            l++;
            mx = getmax(l);
            mi = getmin(l);
        }
        res = max(res, pre[i] - pre[l - 1] + dp[l - 1]);
        dp[i] = max(dp[i - 1], pre[i] - pre[l - 1]);
    }
    cout << res;
}
