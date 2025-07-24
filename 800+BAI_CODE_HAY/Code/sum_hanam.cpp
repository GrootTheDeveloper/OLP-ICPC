#include <bits/stdc++.h>
using namespace std;
#define int long long

struct dta{int l,r;};
dta a[111];
int t;

int calc(int n)
{
	int k=n%9;
	return (n/9)*45+k*(k+1)/2;
}
void sub2()
{
	for (int i=1;i<=t;i++)
	{
		cout << calc(a[i].r)-calc(a[i].l-1) << '\n';
	}
}




int sum(int n)
{
	int res=0;
	while (n) res+=n%10,n/=10;
	return res;
}
int g(int x)
{
	while (x>9) x=sum(x);
	return x;
}
void sub1()
{
	for (int i=1;i<=t;i++)
	{
		int res=0;
		for (int j=a[i].l;j<=a[i].r;j++) res+=g(j);
		cout << res << '\n';
	}
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("t.inp","r",stdin);
	freopen("t.out","w",stdout);
	cin >> t;
	int mx=0;
	for (int i=1;i<=t;i++) cin >> a[i].l >> a[i].r, mx=max(mx,a[i].r);
	if (mx<=1e4) sub1();
	else sub2();
	
}