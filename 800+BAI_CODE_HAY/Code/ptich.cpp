#include <bits/stdc++.h>
using namespace std;
#define int long long
int dif[5000006],dem[5000006];



int g(int n)
{
	int lim=n;
	for (int i=2;i<=sqrt(lim);i++)
	{
		while (n%i==0)  
		{
			dem[i]=1;
			n/=i;
		}
	}

	if (n!=1) dem[n]=1;
	int res=1;
	for (int i=2;i<=lim;i++) 
	{
		if (dem[i]) res*=i,dem[i]=0;
	}
	return res;
}


main()
{
	int n; cin >> n;
	int val=0,res=0;
	for (int i=max(n-2,2LL);i<=n;i++)  
	{
		int x=g(x);
		if (val<x) val=x,res=i;
	}
	cout << res;
}
