#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;

int g(int n)
{
	vector <int> v;
	int lim=(int)sqrt(n);
	for (int i=2;i<=lim;i++)
	{
		if (n%i==0)
		{
			v.push_back(i);
			while (n%i==0) n/=i;
		}
	}
	int res=1;
	for (int c : v) res*=c;
	if (n!=0) res*=n;
	return res;
}

void sub1()
{
	int res=1,mx=0;
	for (int i=2;i<=n;i++)
	{
		int x=g(i);
		if (mx<=x) mx=x,res=i;
	}
	cout << res;
}
void sub2()
{
	int res=1,mx=0;
	for (int i=max(1LL,n-10);i<=n;i++)
	{
		int x=g(i);
		if (mx<x) mx=x,res=i;
	}
	cout << res ;
}
main()
{
	freopen("bai2.inp","r",stdin);
	freopen("bai2.out","w",stdout);
	int n; cin >> n;
	if (n<=1e5) sub1();
	else sub2();
}