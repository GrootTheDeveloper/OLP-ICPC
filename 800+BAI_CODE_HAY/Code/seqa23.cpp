#include <bits/stdc++.h>
using namespace std;
#define int long long
int calc(int n)
{
	return n*(n+1)/2;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int x; cin >> x;
		int l=1,r=(int)1e6;
		while (l<r)
		{
			int mid=(l+r)/2;
			if (calc(mid)>x) r=mid-1;
			else l=mid+1;
		}
		while (calc(l-1)>=x) l--;
		while (calc(l)<x) l++;
		cout << !(calc(l)==x) << '\n';

	}
}