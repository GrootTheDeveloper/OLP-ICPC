#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,s;

struct dta{int w,v,type;};
dta a[100005];
int f[100005],b[100005];
bool cmp(dta a, dta b)
{
	return a.w < b.w;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> n >> s;
	int m=0,wig=0,val=0;
	for (int i=1;i<=n;i++)
		cin >> a[i].w >> a[i].v >> a[i].type;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) 
		if (a[i].type==0)
		{
			m++;
			f[m]=a[i].w;
			b[m]=max(b[m-1],a[i].v);
		}
		else wig+=a[i].w,val+=a[i].v;
	int res=val;
	for (int i=1;i<=n;i++)
	if (a[i].type)
	{
		int pos=upper_bound(f+1,f+m+1,s-(wig-a[i].w))-f-1;
		res=max(res,val-a[i].v+b[pos]);
	}
	cout << res;
}