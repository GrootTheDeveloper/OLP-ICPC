#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int cnt1=0,cnt2=0;
		for (int i=1,val;i <= n; i++)
		{
			cin >> val;
			if (val&1) cnt1++;else cnt2++;
		}
		if (cnt1&1 || (cnt2&1 && cnt1==0)) cout << "no" << '\n';
		else cout << "yes" << '\n';
	}

}