#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9+7;

int f[500005],pre[500005];
struct dta{int fi,se;};
dta a[100];
vector <dta> v;
bool cmp(dta a, dta b)
{
	return a.fi < b.fi;
}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k; cin >> n >> k;
	for (int i=1;i<=k;i++)
	cin >> a[i].fi >> a[i].se;
	sort(a+1,a+k+1,cmp);
	for (int i=1;i<=k;i++)
	{
		if (v.size()==0) v.push_back(a[i]);
		else
		{
			if (v.back().se<a[i].fi) v.push_back(a[i]);
			else v.back().se=max(v.back().se,a[i].se);
		}
	}
	f[1]=1;pre[1]=1;
	for (int i=2;i<=n;i++)
	{
		for (dta c : v)
		{
			int r=i-c.fi,l=i-c.se;
			l=max(l,1LL);
			if (r>=1) f[i]=(f[i]+pre[r]-pre[l-1])%mode;
		}
		pre[i]=pre[i-1]+f[i];
	}
	cout << f[n]%mode;
}