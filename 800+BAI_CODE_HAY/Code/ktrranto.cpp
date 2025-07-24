#include <bits/stdc++.h>
using namespace std;
#define int long long

bool prime[1000006];
void sang()
{
	for (int i=2;i<=1000;i++)
	if (!prime[i])
		for (int j=i*i;j<=1e6;j+=i) prime[j]=true;
}
int power(int a, int b, int mode)
{
	int res=1;
	while (b)
	{
		if (b&1) res=(res*a)%mode;
		a=(a*a)%mode;
		b/=2;
	}
	return res;
}
bool check(int a, int n, int m, int k)
{
	int mode=power(a,m,n);
	if (mode==1 || mode==n-1) return true;
	for (int l=1;l<=k;l++)
	{
		mode=(mode*mode)%n;
		if (mode==n-1) return true;
	}
	return false;
}

bool nto(int n)
{
	if (n==2 || n==3 || n==5 || n==7) return true;
	if (n<11) return false;
	int m=n-1,k=0;
	while (m%2==0)
	{
		k++;
		m/=2;
	}
	vector<int> test={2,3,5,7,11,13,17,19,23,29,31,37};
	for (int a : test)
	{
		if (n==a) return true;
		else if (!check(a,n,m,k)) return false;
	}
	return true;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int d1=0,d2=0;
	sang();
	for (int i=2;i<=1e6;i++) 
	{
		if (!prime[i]) d1++;
		d2+=nto(i);
	}
	cout << d1 << ' ' << d2;
}