#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,p,x,res,s,a[100005];

void Try(int i)
{
	if (i==n+1) return res+=(s%x==p),void();
	s+=a[i];
	Try(i+1);
	s-=a[i];
	Try(i+1);
}

void sub1()
{
	Try(1);
	if (p==0) res++;
	cout << res;
}
int f[1000006];
void sub2()
{
	f[0]=1;
	int res=0;
	for (int i=1;i<=n;i++) a[i]%=x,s+=a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) 
	{
		for (int j=s;j>=a[i];j--)
			f[j]+=f[j-a[i]];
	}
	for (int i=p;i<=s;i+=x) res+=f[i];
	if (p==0) res++;
	cout << res;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("MODSUM.INP","r",stdin);
	freopen("MODSUM.OUT","w",stdout);
	cin >> n >> p >> x;
	for (int i=1;i<=n;i++) cin >> a[i];
	if (n<=20) sub1();
	else sub2();
	
}