#include <bits/stdc++.h>
using namespace std;
#define int long long  
int mx,q,f[1000099];
struct dta{int l,r;};
dta a[200005];
int s(int n)
{
	int res=0;
	while (n) res+=n%10,n/=10;
	return res;
}
int ans[1000006];
void sub1()
{
	for (int i=1;i<=mx;i++)
		f[i+s(i)]++;
	for (int i=1;i<=mx;i++) ans[i]=ans[i-1]+f[i];
	for (int i=1;i<=q;i++) cout << ans[a[i].r]-ans[a[i].l-1] << '\n';
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("GENNUM.INP","r",stdin);
	freopen("GENNUM.OUT","w",stdout);
	cin >> q;
	for (int i=1;i<=q;i++) cin >> a[i].l >> a[i].r,mx=max(mx,a[i].r);
	if (mx<=1e6) sub1();
}