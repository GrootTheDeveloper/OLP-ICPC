#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int> 
#define val first 
#define pos second 
int pre[200005];
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,l,r; cin >> n >> l >> r;

	priority_queue <ii,vector<ii>,greater<ii>> q;
	
	int res = -1e18*1LL;
	q.push({0,0});
	for (int i = 1,x; i <= n; ++i)
	{
		cin >> x;
		pre[i] = pre[i-1] + x;
		if (i >= l)
		{
			q.push({pre[i-l],i-l});
			while (i - q.top().pos > r) q.pop();
			res = max(res, pre[i] - q.top().val);
		}
	}
	cout << res;
}