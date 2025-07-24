#include <bits/stdc++.h>
using namespace std;
#define int long long 
int cnt[8],res;
int p,l,v,h,sum;
void check()
{
	int s=1;
	for (int i=1;i<=6;i++)
		s*=pow(i,cnt[i]);
	if (s==sum) res++;
}
void Try(int i)
{
	if (i>p) return check(),void();
	for (int j=1;j<=6;j++)
	{
		cnt[j]++;
		Try(i+1);
		cnt[j]--;
	}
}
void sub1()
{
	Try(1);
	cout << res;
}



main()
{
	freopen("dice.inp","r",stdin);
	freopen("dice.out","w",stdout);
	cin >> p >> l >> v >> h;
	if (p==1)
	{
		if ((l+v+h==0) || (l+v+h==1) || (l==0 && v==h && h==1)) cout << 1;
		else cout << 0;
	}
	else if (p==l && v+h==0) cout << 1;
	else if (p<=9) sum=pow(5,l)*pow(3,v)*pow(2,h),sub1();
}