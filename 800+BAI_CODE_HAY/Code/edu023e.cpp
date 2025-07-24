#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first
#define se second


const int mode=1e9+7;
int n,x,y,res=1;
pair <int,int> a[1111];

void sub1()
{
	unordered_map <int,int> f;
	int res=1;
	for (int i=1;i<=n;i++)
	{
		if (f[a[i].fi]) res/=f[a[i].fi];
		f[a[i].fi]++;
		res=(res*f[a[i].fi])%mode;
		cout << res << '\n';
	}
}
int f[1111],pos[1111],rig[1111];
void sub2()
{

	for (int i=1;i<=n;i++)
	{
		int l,r,res=1;
		if (pos[a[i].fi]==0) l=a[i].fi;
		else l=pos[a[i].fi];
		if (rig[a[i].se]==0) r=a[i].se;
		else r=rig[a[i].se];
		int cnt=1;
		for (int i=l;i<=r;i++) pos[i]=l,rig[i]=r,cnt+=(()? f[i]:0);
		for (int i=l;i<=r;i++) f[i]=cnt;
		for (int i=1;i<=1000;i++) if (f[i]!=f[i-1] && f[i]) res=(res*f[i])%mode;
		cout << res << '\n';
	}
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("DOANTOT.INP","r",stdin);
//	freopen("DOANTOT.OUT","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
	if (n<=30 && a[1].fi==a[1].se && a[n].fi==a[n].se) sub1();
	else if (n<=1000) sub2();
}