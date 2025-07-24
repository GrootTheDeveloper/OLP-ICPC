#include <bits/stdc++.h>
using namespace std;
#define int long long 


struct dta{
	int d=0,r=0,h=0;
};
bool cmp(dta a, dta b)
{
	return a.d*a.r > b.d*b.r;
}
dta a[222];
int f[222];
int n;

void solve()
{
	for (int i=1;i<=n;i++) 
	{
		cin >> a[i].d >> a[i].r >> a[i].h;
		if (a[i].d < a[i].r) swap(a[i].d,a[i].r);
		if (a[i].h < a[i].d) swap(a[i].h,a[i].d);
		if (a[i].d < a[i].r) swap(a[i].d,a[i].r);

	}
	sort(a+1,a+n+1,cmp);
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		f[i]=a[i].h;
		for (int j=1;j<i;j++) 
			if (a[i].d<=a[j].d && a[i].r<=a[j].r) f[i]=max(f[i],f[j]+a[i].h);
	}
	int res=0;
	for (int i=1;i<=n;i++) res=max(res,f[i]);
	cout << res << '\n';
}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	while (true)
	{
		cin >> n;
		if (n==0) break;
		solve();
	}
}