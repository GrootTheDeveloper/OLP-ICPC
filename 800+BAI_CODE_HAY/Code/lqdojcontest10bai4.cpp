#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
int a[300005];


bool check(int k)
{
	int cnt=0;
	for (int i=1;i<=m;i++) cnt+=a[i]/k+(a[i]%k!=0);
	return cnt<=n;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	int mx=0;
	for (int i=1;i<=m;i++) cin >> a[i],mx=max(mx,a[i]);
	int l=1,r=mx;
	while (l<r)
	{
		int mid=l+r >> 1;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	while (!check(l)) l++;
	while (check(l-1)) l--;
	cout << l;
}