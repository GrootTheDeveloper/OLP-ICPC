#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int,int>
#define fi first
#define se second
int t,p[10004];

ii ans[1005];
bool cp(int n)
{
	int lim=trunc(sqrt(n));
	return lim*lim==n;
}
void sub1()
{
	for (int i=1;i<=1000;i++) ans[i].fi=ans[i].se=-1;
	for (int i=1;i<=1000;i++) for (int j=i;j<=1000-i;j++) 
	if (cp(i*j)) ans[i+j].fi=i,ans[i+j].se=j;
	for (int i=1;i<=t;i++) cout << ans[p[i]].fi << ' ' << ans[p[i]].se << '\n';
	
}

void sub2()
{
	for (int i=1;i<=t;i++)
	{
		bool gn=false;
		int lim=p[i]/2;
		for (int x=1;x<=lim;x++) 
			if (cp(x*(p[i]-x))) {gn=true; cout << x << ' ' << p[i]-x << '\n'; break;}
		if (!gn) cout << "-1 -1" << '\n'; 
	}
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("SQPROD.INP","r",stdin);
	freopen("SQPROD.OUT","w",stdout);
	cin >> t;
	int mx=0;
	for (int i=1;i<=t;i++) cin >> p[i],mx=max(mx,p[i]);
	if (t<=30) sub2();
	else if (mx<1000) sub1();

	


}