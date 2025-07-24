#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,t,a[200005];

bool check(int k)
{
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		sum+=k/a[i];
		if (sum>=t) return true;
	}
	return false;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> n >> t;
	for (int i=1;i<=n;i++) cin >> a[i];
	int l=1,r=1e18;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	while (check(l-1)) l--;
	while (!check(l)) l++;
	cout << l;
}