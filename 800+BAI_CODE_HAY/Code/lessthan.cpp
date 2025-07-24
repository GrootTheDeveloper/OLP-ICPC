#include <bits/stdc++.h>
using namespace std;
#define int long long

struct dta{
	int val,idx;
}a[100005];
bool cmp(dta a, dta b)
{
	return a.val < b.val;
}
int dp[100005];

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i].val;
		a[i].idx=i;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
		dp[a[i].idx]=((a[i].val==a[i-1].val)? dp[a[i-1].idx]:i-1);
	for (int i=1;i<=n;i++) cout << dp[i] << ' ';
}