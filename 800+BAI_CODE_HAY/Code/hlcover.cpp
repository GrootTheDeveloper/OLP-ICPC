#include <bits/stdc++.h>
using namespace std;
#define int long long 
struct Data
{
	int fi,se;
};

bool cmp(Data a, Data b)
{
	if (a.fi==b.fi) return a.se<b.se;
	return a.fi<b.fi;
}
vector <Data> v;
Data a[5555];
int f[5555],x,y;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> x >> y;
		a[i].fi=abs(x);a[i].se=abs(y);
	}
	sort(a+1,a+n+1,cmp);
	v.push_back(a[1]);
	for (int i=2;i<=n;i++)
	{
		if (a[i].fi>=v.back().fi && a[i].se>=v.back().se) v.back()=a[i];
		else v.push_back(a[i]);
	}
	
	int m=v.size();
	for (int i=1;i<=m;i++)
	{
		f[i]=f[i-1]+v[i-1].fi*v[i-1].se*4;
		int lx=v[i-1].fi,ly=v[i-1].se;
		for (int j=i-1;j>=1;j--)
		{
			lx=max(lx,v[j-1].fi);
			ly=max(ly,v[j-1].se);
			f[i]=min(f[i],f[j-1]+lx*ly*4);
		}
	}
	cout << f[m];


}