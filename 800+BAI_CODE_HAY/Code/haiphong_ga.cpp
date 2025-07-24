#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[22],t[22],n,x;


bool check(int ti)
{
	int cnt=0;
	for (int i=1;i<=n;i++)
		cnt+=(p[i]<=ti) + max(0ll,ti-p[i])/t[i];
	return cnt>=x;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> x;
	for (int i=1;i<=n;i++)
		cin >> p[i] >> t[i];
	int l=1,r=1e18;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	while (!check(l)) l++;
	while (check(l-1)) l--;
	cout << l;
}