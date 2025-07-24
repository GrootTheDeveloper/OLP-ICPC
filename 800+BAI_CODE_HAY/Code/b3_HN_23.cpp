#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[555],res,f[555];

void check()
{
	int sum1=0,sum2=0;
	for (int i=1;i<=n;i++)
	{
		if (f[i]==1) sum1+=a[i];
		if (f[i]==2) sum2+=a[i];
	}
	if (sum1==sum2) res=max(res,sum1);
}

void Try(int i)
{
	if (i>n) return check(),void();
	for (int j=1;j<=3;j++)
	{
		f[i]=j;
		Try(i+1);
	}
}

void sub1()
{
	Try(1);
	cout << res;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	/*cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	if (n<=12) sub1();*/
cout << fixed << setprecision(4) << (double)10/3;
}