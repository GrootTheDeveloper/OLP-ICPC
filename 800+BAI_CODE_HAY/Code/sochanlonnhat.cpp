#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[1000005];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	int c1=0,c2=0,cnt1=0,cnt2=0;
	int res=-1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]&1) 
		{
			if (cnt1) res=max(res,a[i]+c1),c1=max(c1,a[i]);
			else cnt1=1,c1=max(c1,a[i]);
		}
		else
		{
			if (cnt2) res=max(res,a[i]+c2),c2=max(c2,a[i]);
			else cnt2=1,c2=max(c2,a[i]);
		}
	}
	cout << res;

}