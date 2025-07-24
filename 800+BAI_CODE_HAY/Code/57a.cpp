#include <bits/stdc++.h>
using namespace std;
#define int long long 
int m,n;
int a[100005];

void sub1()
{
	int res=0,d=0;
	for (int i=1;i<=n;i++) 
	{
		if (a[i]==0) d++;
		else d=0;
		res=max(res,d);
	}
	cout << res+1;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("FROG.inp","r",stdin);
	freopen("FROG.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	if (m==1) sub1();
}