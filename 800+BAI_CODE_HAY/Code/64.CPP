#include <bits/stdc++.h>
using namespace std;
#define int long long 
int kq, f[10000007], n, a[100007],x,y;
main()
{
	int kq=INT_MIN;
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		f[i]=f[i-1]+a[i];
	}
	for (int i=1; i<=n; i++)
	{
		x=(f[i]*(-1)+(f[n]-f[i]));
		y=(f[i]+(f[n]-f[i])*(-1));
		kq=max({kq,x,y});
	}
	cout << kq;
}