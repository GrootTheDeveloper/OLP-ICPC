#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define val first
#define id second
priority_queue <ii> qmax;
priority_queue <ii, vector<ii>, greater<ii>> qmin; 
int n,k;
int a[300005], dp[300005], pre[300005];

int getmin(int l)
{
	while (qmin.top().id < l) qmin.pop();
	return qmin.top().val;
}
int getmax(int l)
{
	while (qmax.top().id < l) qmax.pop();
	return qmax.top().val;
}
void solve()
{
	int l = 1;
	int res = 0;
	for (int r = 1, mx,mi; r <= n; r++)
	{
		qmax.push({a[r], r});
		qmin.push({a[r], r});
		mx = getmax(l);
		mi = getmin(l);
		while (mx - mi > k)
		{
			l++;
			mx = getmax(l);
			mi = getmin(l);
		}
		res = max(res, pre[r] - pre[l - 1] + dp[l - 1]);
		dp[r] = max(pre[r] - pre[l - 1], dp[r - 1]);
	}
	cout << res;
}
void inp()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	inp();
	solve();
}