#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[10004];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	for (int n; t > 0; t--)
	{
		cin >> n;
		int res=0,cur=0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			cur = ((a[i] > a[i-1])? cur + 1 : 1);
			res = max(res,cur);
		}
		cout << res << '\n';
	}
}