#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005],n,f[55555];
void sub1()
{
	int res=0;
	for (int i=1;i<=n;i++) 
	{
		for (int j=1;j<=n;j++)
		if (a[j]>a[i]) res+=f[a[j]+(a[j]-a[i])];
	}  
	for (int i=1;i<=n;i++) if (f[a[i]]>=3) 
	{
		int k=f[a[i]];
		res+=(k-2)*(k-1)*k;
		f[a[i]]=0;
	}
	cout << res;
}
void suball()
{
	int res=0;
	for (int i=1;i<5000;i++)
	for (int j=i+1;j<=5000;j++) 
	{
		res+=f[i]*f[j]*f[j+j-i];
		if (f[i]>=3) res+=(f[i]-2)*(f[i]-1)*f[i];
	}
	if (f[5000]>=3) res+=(f[5000]-2)*(f[5000]-1)*f[5000];
	cout << res;
}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("TRIPLE.INP","r",stdin);
	freopen("TRIPLE.OUT","w",stdout);
	cin >> n;
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];sum+=a[i];
		f[a[i]]++;
	}
	/*if (f[1]+f[2]+f[3]==n) cout << f[1]*f[2]*f[3];
	else if (n<=2000 && sum!=n) sub1();
	else if (sum==n) cout << (n-2)*(n-1)*n;
	else*/ suball();

}