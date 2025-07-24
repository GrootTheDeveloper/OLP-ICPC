#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005];
int n,m;

int pin(int &x)
{
	int l=1,r=n;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (a[mid]>=x) r=mid-1;
		else l=mid+1;
	}
	while (a[l]>x) l--;
	while (a[l+1]<=x) l++;
	return l;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("CLIMBSTAIR.INP","r",stdin);
	freopen("CLIMBSTAIR.OUT","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i],a[i]=max(a[i],a[i-1]);
	a[n+1]=INT_MAX;
	while (m--)
	{
		int x; cin >> x;
		cout << pin(x) << '\n';
	}
}